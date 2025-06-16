/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:08:51 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/16 21:20:28 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_actor.h"

t_ft_actor	*ft_actor_new(void)
{
	t_ft_actor	*a;

	a = ft_actor_calloc(1, sizeof(t_ft_actor));
	if (!a)
		return (NULL);
	a->inbox = ft_queue_new();
	a->is_running = false;
	a->tell = _ft_actor_tell;
	if (!a->inbox)
		ft_actor_del(&a);
	return (a);
}

static void	*_ft_actor_loop(void *arg)
{
	t_ft_actor	*self;
	t_ft_msg	*msg;

	self = (t_ft_actor *)arg;
	if (!self || !self->v || !self->v->on_receive)
		return (NULL);
	if (self->v->on_start)
		self->v->on_start(self);
	while (true)
	{
		usleep(1000);
		msg = self->inbox->deq(self->inbox);
		if (!msg)
			continue ;
		if (!(self->v->on_receive(self, msg)))
		{
			msg_del(&msg);
			break ;
		}
		msg_del(&msg);
	}
	return (NULL);
}

void	ft_actor_del(t_ft_actor **a)
{
	t_ft_actor	*_a;

	_a = *a;
	ft_queue_del(&_a->inbox);
	free(_a);
	*a = NULL;
}

void	ft_actor_start(t_ft_actor *a)
{
	a->is_running = true;
	pthread_create(&a->thread, NULL, _ft_actor_loop, a);
}

void	ft_actor_stop(t_ft_actor *a)
{
	a->is_running = false;
	pthread_join(a->thread, NULL);
}
