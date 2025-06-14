/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:55:40 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/07 14:20:00 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

/**
 * @return true     :SUCCESS
 * @return false    :FAILURE
 */
static bool	_enqueue(t_queue *self, t_msg *msg)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (false);
	node->msg = msg;
	node->next = NULL;
	pthread_mutex_lock(&self->mutex);
	if (self->tail)
		self->tail->next = node;
	else
		self->head = node;
	self->tail = node;
	pthread_mutex_unlock(&self->mutex);
	return (true);
}

/**
 * @brief
 *
 * @param self
 * @return t_msg*   :SUCCESS
 * @return NULL     :FAILURE
 */
static t_msg	*_dequeue(t_queue *self)
{
	t_msg	*msg;
	t_node	*node;

	msg = NULL;
	pthread_mutex_lock(&self->mutex);
	if (self->head)
	{
		node = self->head;
		msg = node->msg;
		self->head = node->next;
		if (!self->head)
			self->tail = NULL;
		free(node);
	}
	pthread_mutex_unlock(&self->mutex);
	return (msg);
}

t_queue	*queue_new(void)
{
	t_queue	*q;

	q = malloc(sizeof(t_queue));
	if (!q)
		return (NULL);
	q->head = NULL;
	q->tail = NULL;
	pthread_mutex_init(&q->mutex, NULL);
	q->enqueue = _enqueue;
	q->dequeue = _dequeue;
	return (q);
}

void	queue_destroy(t_queue **q)
{
	t_node	*curr;
	t_node	*next;

	if (!q || !*q)
		return ;
	curr = (*q)->head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	pthread_mutex_destroy(&(*q)->mutex);
	free(*q);
	*q = NULL;
}
