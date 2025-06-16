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
t_ft_actor *f_dummy = NULL;
const t_ft_actor_vtable f_dummy_vtable = {
    .on_start = NULL,
    .on_receive = NULL,
    .on_stop = NULL,
    
};

static void setup(void) {
    f = fork_actor_new();
    f_dummy = ft_actor_new(NULL);
}

static void teardown(void) {
    ft_actor_stop(f->base);
    ft_actor_stop(f_dummy);
    fork_actor_del(&f);
    ft_actor_del(&f_dummy);
}

static t_ft_msg   *_wait_mes(t_ft_actor *f_dummy, size_t max)
{
    t_ft_msg   *res = NULL;
    size_t  time = 0;

    while (time < max)
    {
        res = f_dummy->inbox->deq(f_dummy->inbox);
        if (res)
            return (res);
        time++;
    }
    return (NULL);
}

void    test_on_request_fork_normal(void) {

    t_ft_msg   *res = NULL;

    _on_request_fork(f, f_dummy);
    res = _wait_mes(f_dummy, WAIT_TIME);
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_INT(res->type, GRANT_FORK);
    free(res);
}

void    test_on_request_fork_failed(void) {

    t_ft_msg   *res = NULL;

    _on_request_fork(f, f_dummy);
    res = _wait_mes(f_dummy, WAIT_TIME);
    _on_request_fork(f, f_dummy);
    free(res);
    res = _wait_mes(f_dummy, WAIT_TIME);
    TEST_ASSERT_NULL(res);
}

void    test_on_release_fork_normal(void) {

    t_ft_msg   *res = NULL;

    _on_request_fork(f, f_dummy);
    res = _wait_mes(f_dummy, WAIT_TIME);
    _on_release_fork(f, f_dummy);
    free(res);
    res = _wait_mes(f_dummy, WAIT_TIME);
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_INT(res->type, FORK_RELEASED);
    free(res);
}

void    test_on_release_fork_failed(void) {
    t_ft_msg   *res = NULL;

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
