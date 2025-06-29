/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _on_actor_start_done.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:50:17 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/29 12:58:54 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

static void	_send_set_start_msg(t_sv_actor *self)
{
	int			i;
	t_ft_msg	*msg;
	t_ft_actor	*philo_ref;

	i = 0;
	while (i < self->prop->args.num_of_philos)
	{
		philo_ref = self->prop->philos_ref[i++];
		msg = msg_new(SYNC_START, self->base);
		msg->data.tv = self->prop->start;
		philo_ref->tell(philo_ref, msg);
	}
}

void	_on_actor_start_done(t_sv_actor *self)
{
	self->prop->start_done_count++;
	if (self->prop->start_done_count == self->prop->ref_count)
	{
		_send_grant_eat(self);
		gettimeofday(&self->prop->start, NULL);
		self->prop->last_update_time = self->prop->start;
		_send_set_start_msg(self);
		self->sys_notify_inbox->enq(
			self->sys_notify_inbox, msg_new(ACTOR_START_DONE, NULL));
	}
}
