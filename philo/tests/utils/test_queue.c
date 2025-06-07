/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 23:40:09 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/07 13:13:07 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include "test_util.h"

t_queue		*q = NULL;

static void	setup(void)
{
	q = queue_new();
}

static void	teardown(void)
{
	queue_clear(&q);
}

void	test_push_and_pop(void)
{
	t_msg	msg1;
	t_msg	*msg2;

	msg1 = (t_msg){.type = UPDATE, .args = "NULL", .sender = NULL};
	q->enqueue(q, &msg1);
	msg2 = q->dequeue(q);
	TEST_ASSERT_EQUAL_PTR(&msg1, msg2);
}

void	test_dequeue_is_empty(void)
{
	t_msg	*msg;

	msg = q->dequeue(q);
	TEST_ASSERT_NULL(msg);
}

void	test_queue(void)
{
	RUN_PHILO_TEST(test_push_and_pop);
	RUN_PHILO_TEST(test_dequeue_is_empty);
}
