/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_philo_actor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:51:36 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/07 14:58:12 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"
#include "test_util.h"

#define WAIT_TIME 10000


t_philo_actor *p = NULL;
t_actor *p_dummy = NULL;
t_actor	*p_dummy2 = NULL;
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
    p_dummy = actor_new(1, NULL, &p_dummy_vtable);
	p_dummy2 = actor_new(2, NULL, &p_dummy_vtable);
}

static void teardown(void) {
    free_philo(&p);
    free_actor(&p_dummy);
	free_actor(&p_dummy2);
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

void	test_thinking_l_fork_send(void)
{
    t_msg   *res = NULL;

	p->can_eat = true;
	p->has_r_fork = true;
	p->has_l_fork = false;
	p->r_fork = p_dummy2;
	p->l_fork = p_dummy;
	_thinking(p);
	res = _wait_mes(p_dummy, WAIT_TIME);
    TEST_ASSERT_NOT_NULL(res);
	TEST_ASSERT_EQUAL_INT(res->type, REQUEST_FORK);
	free(res);
}

void	test_thinking_r_fork_send(void)
{
    t_msg   *res = NULL;

	p->can_eat = true;
	p->has_r_fork = false;
	p->has_l_fork = true;
	p->r_fork = p_dummy;
	p->l_fork = p_dummy2;
	_thinking(p);
	res = _wait_mes(p_dummy, WAIT_TIME);
    TEST_ASSERT_NOT_NULL(res);
	TEST_ASSERT_EQUAL_INT(res->type, REQUEST_FORK);
	free(res);
}

void	test_thinking_has_both_fork(void)
{
    t_msg   *res1 = NULL;
    t_msg   *res2 = NULL;

	p->can_eat = true;
	p->has_r_fork = true;
	p->has_l_fork = true;
	p->r_fork = p_dummy;
	p->l_fork = p_dummy2;
	_thinking(p);
	res1 = _wait_mes(p_dummy, WAIT_TIME);
	res2 = _wait_mes(p_dummy2, WAIT_TIME);
    TEST_ASSERT_NULL(res1);
    TEST_ASSERT_NULL(res2);
	TEST_ASSERT_EQUAL_INT(p->sts, PHILO_STS_EATING);
	TEST_ASSERT_EQUAL_INT(p->max_hp, p->now_hp);
}

void	test_eating(void)
{
	p->r_fork = p_dummy;
	p->l_fork = p_dummy2;
	TEST_ASSERT_EQUAL_INT(p->now_eat, 0);
	_eating(p, p_dummy);
	TEST_ASSERT_EQUAL_INT(p->now_eat, 1);
}

void	test_eating_done(void)
{
	t_msg	*res1 = NULL;
	t_msg	*res2 = NULL;
	t_msg	*res3 = NULL;

	p->r_fork = p_dummy;
	p->l_fork = p_dummy;
	p->max_eat = 1;
	TEST_ASSERT_EQUAL_INT(p->now_eat, 0);
	_eating(p, p_dummy2);
	res1 = _wait_mes(p_dummy, WAIT_TIME);
	res2 = _wait_mes(p_dummy, WAIT_TIME);
	res3 = _wait_mes(p_dummy2, WAIT_TIME);
	TEST_ASSERT_NOT_NULL(res1);
	TEST_ASSERT_NOT_NULL(res2);
	TEST_ASSERT_NOT_NULL(res3);
	TEST_ASSERT_EQUAL_INT(res1->type, RELEASE_FORK);
	TEST_ASSERT_EQUAL_INT(res2->type, RELEASE_FORK);
	TEST_ASSERT_EQUAL_INT(res3->type, PHILO_EAT_DONE);
	TEST_ASSERT_EQUAL_INT(p->can_eat, false);
	TEST_ASSERT_EQUAL_INT(p->sts, PHILO_STS_WAITING);
	free(res1);
	free(res2);
	free(res3);
}

void	test_sleeping(void)
{
	TEST_ASSERT_EQUAL_INT(p->now_slp, 0);
	_sleeping(p);
	TEST_ASSERT_EQUAL_INT(p->now_slp, 1);
}

void	test_sleeping_wakeup(void)
{
	p->max_slp = 1;
	TEST_ASSERT_EQUAL_INT(p->now_slp, 0);
	_sleeping(p);
	TEST_ASSERT_EQUAL_INT(p->now_slp, 0);
	TEST_ASSERT_EQUAL_INT(p->sts, PHILO_STS_THINKING);
}

void	test_confirm_fork_l(void)
{
	p->l_fork = p_dummy;
	p->r_fork = p_dummy2;
	p->has_l_fork = false;
	_confirm_fork(p, p_dummy);
	TEST_ASSERT_EQUAL_INT(p->has_l_fork, true);
}

void	test_confirm_fork_r(void)
{
	p->l_fork = p_dummy;
	p->r_fork = p_dummy2;
	p->has_r_fork = false;
	_confirm_fork(p, p_dummy2);
	TEST_ASSERT_EQUAL_INT(p->has_r_fork, true);
}

void	test_on_fork_released_l()
{
	p->l_fork = p_dummy;
	p->r_fork = p_dummy2;
	p->has_l_fork = true;
	_on_fork_released(p, p_dummy);
	TEST_ASSERT_EQUAL_INT(p->has_l_fork, false);
}

void	test_on_fork_released_r()
{
	p->l_fork = p_dummy;
	p->r_fork = p_dummy2;
	p->has_r_fork = true;
	_on_fork_released(p, p_dummy2);
	TEST_ASSERT_EQUAL_INT(p->has_r_fork, false);
}

void	test_on_fork_released_both()
{
	p->l_fork = p_dummy;
	p->r_fork = p_dummy2;
	p->has_l_fork = true;
	p->has_r_fork = true;
	_on_fork_released(p, p_dummy);
	_on_fork_released(p, p_dummy2);
	TEST_ASSERT_EQUAL_INT(p->has_l_fork, false);
	TEST_ASSERT_EQUAL_INT(p->has_r_fork, false);
	TEST_ASSERT_EQUAL_INT(p->sts, PHILO_STS_SLEEPING);
}

void test_philo(void) {
    RUN_PHILO_TEST(test_common_update_normal);
    RUN_PHILO_TEST(test_common_update_dead);
	RUN_PHILO_TEST(test_thinking_l_fork_send);
	RUN_PHILO_TEST(test_thinking_r_fork_send);
	RUN_PHILO_TEST(test_thinking_has_both_fork);
	RUN_PHILO_TEST(test_eating);
	RUN_PHILO_TEST(test_eating_done);
	RUN_PHILO_TEST(test_sleeping);
	RUN_PHILO_TEST(test_sleeping_wakeup);
	RUN_PHILO_TEST(test_confirm_fork_l);
	RUN_PHILO_TEST(test_confirm_fork_r);
	RUN_PHILO_TEST(test_on_fork_released_l);
	RUN_PHILO_TEST(test_on_fork_released_r);
	RUN_PHILO_TEST(test_on_fork_released_both);
}
