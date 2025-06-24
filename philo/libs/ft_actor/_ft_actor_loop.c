/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_actor_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:08:51 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 13:14:40 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_actor.h"

static void _take_msg(t_ft_actor *self, t_ft_queue *inbox)
{
	t_ft_msg	*msg;

	msg = inbox->deq(inbox);
	if (!msg)
		return ;
	self->v->on_receive(self, msg);
	msg_del(&msg);
}

void	*_ft_actor_loop(void *arg)
{
	t_ft_actor	*self;

	self = (t_ft_actor *)arg;
	if (!self || !self->v || !self->v->on_receive)
		return (NULL);
	if (self->v->on_start)
		self->v->on_start(self);
	while (self->is_running)
	{
		usleep(1000);
		if (self->v->update)
			self->v->update(self);
		_take_msg(self, self->emergency_inbox);
		_take_msg(self, self->inbox);
	}
	return (NULL);
}
