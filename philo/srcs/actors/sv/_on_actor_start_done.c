/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _on_actor_start_done.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:50:17 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 21:12:28 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

static void	_send_set_start_msg(t_sv_actor *self, t_ft_msg *rv_msg)
{
	t_ft_msg	*msg;

	msg = msg_new(PHILO_SET_START, self->base);
	msg->data.tv = self->prop->start;
	rv_msg->sender->tell(rv_msg->sender, msg);
}

void	_on_actor_start_done(t_sv_actor *self, t_ft_msg *rv_msg)
{
	self->prop->start_done_count++;
	_send_set_start_msg(self, rv_msg);
	if (self->prop->start_done_count == self->prop->ref_count)
	{
		_send_grant_eat(self);
		gettimeofday(&self->prop->start, NULL);
		self->prop->last_update_time = self->prop->start;
		self->sys_notify_inbox->enq(
			self->sys_notify_inbox, msg_new(ACTOR_START_DONE, NULL));
	}
}
