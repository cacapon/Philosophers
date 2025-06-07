/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 23:40:09 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/30 19:10:24 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork_actor.h"
#include "test_util.h"
#define WAIT_TIME 10000


t_fork_actor *f = NULL;
t_actor *f_dummy = NULL;
const t_actor_vtable f_dummy_vtable = {
    .on_start = NULL,
    .on_receive = NULL,
    .on_stop = NULL,
    .tell = default_tell
};

static void setup(void) {
    f = fork_actor_new(0);
    f_dummy = actor_new(0, NULL, &f_dummy_vtable);
}

static void teardown(void) {
    actor_stop(&f->base);
    actor_stop(&f_dummy);
    free_fork(&f);
    free_actor(&f_dummy);
}

static t_msg   *_wait_mes(t_actor *f_dummy, size_t max)
{
    t_msg   *res = NULL;
    size_t  time = 0;

    while (time < max)
    {
        res = f_dummy->msg_box->dequeue(f_dummy->msg_box);
        if (res)
            return (res);
        time++;
    }
    return (NULL);
}

void    test_on_request_fork_normal(void) {

    t_msg   *res = NULL;

    _on_request_fork(f, f_dummy);
    res = _wait_mes(f_dummy, WAIT_TIME);
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_INT(res->type, GRANT_FORK);
}

void    test_on_request_fork_failed(void) {

    t_msg   *res = NULL;

    _on_request_fork(f, f_dummy);
    res = _wait_mes(f_dummy, WAIT_TIME);
    _on_request_fork(f, f_dummy);
    free(res);
    res = _wait_mes(f_dummy, WAIT_TIME);
    TEST_ASSERT_NULL(res);
}

void    test_on_release_fork_normal(void) {

    t_msg   *res = NULL;

    _on_request_fork(f, f_dummy);
    res = _wait_mes(f_dummy, WAIT_TIME);
    _on_release_fork(f, f_dummy);
    free(res);
    res = _wait_mes(f_dummy, WAIT_TIME);
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_INT(res->type, FORK_RELEASED);
}

void    test_on_release_fork_failed(void) {
    t_msg   *res = NULL;

    _on_release_fork(f, f_dummy);
    _wait_mes(f_dummy, WAIT_TIME);
    TEST_ASSERT_NULL(res);
}

void test_fork(void) {
    RUN_PHILO_TEST(test_on_request_fork_normal);
    RUN_PHILO_TEST(test_on_request_fork_failed);
    RUN_PHILO_TEST(test_on_release_fork_normal);
    RUN_PHILO_TEST(test_on_release_fork_failed);
}
