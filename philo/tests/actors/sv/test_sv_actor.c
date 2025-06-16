/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sv_actor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:51:36 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/07 14:58:12 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "sv_actor.h"
#include "test_util.h"
#include <time.h>

#define WAIT_TIME 10000
#define MAX_PHILO_COUNT 500

t_sv_actor				*sv = NULL;
t_ft_actor					*sv_dummy = NULL;
const t_ft_actor_vtable	sv_dummy_vtable = 
{
	.on_start = NULL,
	.on_receive = NULL,
	.on_stop = NULL,
	
};
const t_main_args main_args = 
{
	.num_of_philos = 5,
	.time_to_die = 800,
	.time_to_eat = 200,
	.time_to_sleep = 200,
	.number_of_times_each_philosopher_must_eat = -1
};

static void	setup(void)
{
	sv = sv_actor_new(main_args);
	sv_dummy = ft_actor_new(NULL);
}

static void	teardown(void)
{
	sv_actor_del(&sv);
	ft_actor_del(&sv_dummy);
}

static size_t	make_even_rand(void)
{
	size_t	n;

	srand(time(NULL));
	do
	{
		n = (size_t)(rand() % MAX_PHILO_COUNT + 1);
	} while (n % 2 == 1);
	return (n);
}

static size_t	make_odd_rand(void)
{
	size_t	n;

	srand(time(NULL));
	do
	{
		n = (size_t)(rand() % MAX_PHILO_COUNT + 1);
	} while (n % 2 == 0);
	return (n);
}

// static t_ft_msg	*_wait_mes(t_ft_actor *sv_dummy, size_t max)
// {
// 	t_ft_msg	*res;
// 	size_t	time;

// 	res = NULL;
// 	time = 0;
// 	while (time < max)
// 	{
// 		res = sv_dummy->inbox->deq(sv_dummy->inbox);
// 		if (res)
// 			return (res);
// 		time++;
// 	}
// 	return (NULL);
// }

void	test_create_send_ptn_even(void)
{
	size_t			rand_n;
	size_t			end0;
	size_t			end1;
	t_size_t_matrix	*ptns;

	for (int i = 0; i < 100; i++)
	{
		rand_n = make_even_rand();
		end0 = rand_n - 2;
		end1 = rand_n - 1;
		ptns = _create_send_ptn(rand_n);
		TEST_ASSERT_EQUAL_size_t(ptns->rows[0][0], 0);
		TEST_ASSERT_EQUAL_size_t(ptns->rows[0][ptns->col - 1], end0);
		TEST_ASSERT_EQUAL_size_t(ptns->rows[1][0], 1);
		TEST_ASSERT_EQUAL_size_t(ptns->rows[1][ptns->col - 1], end1);
		free_matrix(&ptns);
	}
}

void	test_create_send_ptn_odd(void)
{
	size_t			rand_n;
	size_t			end;
	t_size_t_matrix	*ptns;

	for (size_t i = 0; i < 100; i++)
	{
		rand_n = make_odd_rand();
		ptns = _create_send_ptn(rand_n);
		end = rand_n - 2;
		for (size_t j = 0; j < rand_n; j++)
		{
			TEST_ASSERT_EQUAL_size_t(ptns->rows[j][0], (1 + j) % rand_n);
			TEST_ASSERT_EQUAL_size_t(ptns->rows[j][ptns->col -1], (end + j) % rand_n);
		}
		free_matrix(&ptns);
	}
}

void	test_advance_to_next_phase_countup(void)
{
	TEST_ASSERT_EQUAL_INT(sv->prop->philo_done_count, 0);
	_advance_to_next_phase(sv);
	TEST_ASSERT_EQUAL_INT(sv->prop->philo_done_count, 1);
}

void	test_create_forks(void)
{
	TEST_ASSERT_EQUAL(true, false);
}

void	test_create_philos(void)
{
	TEST_ASSERT_EQUAL(true, false);
}

void	test_update_philos(void)
{
	TEST_ASSERT_EQUAL(true, false);
}

void	test_sv(void)
{
	RUN_PHILO_TEST(test_create_send_ptn_even);
	RUN_PHILO_TEST(test_create_send_ptn_odd);
	RUN_PHILO_TEST(test_advance_to_next_phase_countup);
	// RUN_PHILO_TEST(test_create_forks);
	// RUN_PHILO_TEST(test_create_philos);
	// RUN_PHILO_TEST(test_update_philos);
}
