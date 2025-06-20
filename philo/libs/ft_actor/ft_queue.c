/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:55:40 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/16 21:19:30 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

/**
 * @return true     :SUCCESS
 * @return false    :FAILURE
 */
static bool	_enqueue(t_ft_queue *self, void *msg)
{
	t_ft_node	*node;

	node = malloc(sizeof(t_ft_node));
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
 * @return void*	:SUCCESS
 * @return NULL     :FAILURE
 */
static void	*_dequeue(t_ft_queue *self)
{
	void		*msg;
	t_ft_node	*node;

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

t_ft_queue	*ft_queue_new(void)
{
	t_ft_queue	*q;

	q = malloc(sizeof(t_ft_queue));
	if (!q)
		return (NULL);
	q->head = NULL;
	q->tail = NULL;
	pthread_mutex_init(&q->mutex, NULL);
	q->enq = _enqueue;
	q->deq = _dequeue;
	return (q);
}

void	ft_queue_del(t_ft_queue **q)
{
	t_ft_node	*curr;
	t_ft_node	*next;

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
