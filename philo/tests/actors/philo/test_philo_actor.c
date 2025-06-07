/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_philo_actor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:51:36 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/07 14:15:05 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"
#include "test_util.h"

#define WAIT_TIME 10000


t_philo_actor *p = NULL;
t_actor *p_dummy = NULL;
const t_actor_vtable p_dummy_vtable = {
    .on_start = NULL,
    .on_receive = NULL,
    .on_stop = NULL,
    .tell = default_tell
};

static void setup(void) {
	t_philo_args	args;
	args = (t_philo_args){
		.number_of_philosophers = 1,
		.time_to_die = 500,
		.time_to_eat = 100,
		.time_to_sleep = 100,
		.number_of_times_each_philosopher_must_eat = -1
	};
    p = philo_actor_new(0, args);
    p_dummy = actor_new(0, NULL, &p_dummy_vtable);
}

static void teardown(void) {
    free_philo(&p);
    free_actor(&p_dummy);
}

static t_msg   *_wait_mes(t_actor *p_dummy, size_t max)
{
    t_msg   *res = NULL;
    size_t  time = 0;

    while (time < max)
    {
        res = p_dummy->msg_box->dequeue(p_dummy->msg_box);
        if (res)
            return (res);
        time++;
    }
    return (NULL);
}

void    test_common_update_normal(void)
{
    t_msg   *res = NULL;

	_common_update(p, p_dummy);
	res = _wait_mes(p_dummy, WAIT_TIME);
    TEST_ASSERT_NULL(res);
}

void	test_common_update_dead(void)
{
    t_msg   *res = NULL;

	p->now_hp = 1;
	_common_update(p, p_dummy);
	res = _wait_mes(p_dummy, WAIT_TIME);
	TEST_ASSERT_NOT_NULL(res);
	TEST_ASSERT_EQUAL_INT(res->type, PHILO_DEAD);
	free(res);
}

void	test_thinking_cant_eat(void)
{
    t_msg   *res = NULL;

	p->can_eat = false;
	_thinking(p);
	res = _wait_mes(p_dummy, WAIT_TIME);
    TEST_ASSERT_NULL(res);
}

void	test_thinking_has_l_fork(void)
{
    t_msg   *res = NULL;

	p->can_eat = true;
	p->has_l_fork = true;
	p->r_fork = p_dummy;
	p->l_fork = p_dummy;
	_thinking(p);
	res = _wait_mes(p_dummy, WAIT_TIME);
    TEST_ASSERT_NOT_NULL(res);
	TEST_ASSERT_EQUAL_INT(res->type, REQUEST_FORK);
	free(res);
}

void	test_thinking_has_r_fork(void)
{
    t_msg   *res = NULL;

	p->can_eat = true;
	p->has_r_fork = true;
	p->r_fork = p_dummy;
	p->l_fork = p_dummy;
	_thinking(p);
	res = _wait_mes(p_dummy, WAIT_TIME);
    TEST_ASSERT_NOT_NULL(res);
	TEST_ASSERT_EQUAL_INT(res->type, REQUEST_FORK);
	free(res);
}

void test_philo(void) {
    RUN_PHILO_TEST(test_common_update_normal);
    RUN_PHILO_TEST(test_common_update_dead);
	RUN_PHILO_TEST(test_thinking_has_l_fork);
	RUN_PHILO_TEST(test_thinking_has_r_fork);
}
