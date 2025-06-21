/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _sv_on_receive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:50:17 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/21 10:03:31 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

static void	_on_actor_start_done(t_sv_actor *self)
{
	self->prop->start_done_count++;
	if (self->prop->start_done_count == self->prop->ref_count)
	{
		_send_grant_eat(self);
		gettimeofday(&self->prop->start, NULL);
		self->prop->last_update_time = self->prop->start;
		self->sys_notify_inbox->enq(
			self->sys_notify_inbox, msg_new(ACTOR_START_DONE, NULL, NULL));
	}
}

// TODO: deltaの確保に失敗したらエラーにしたい 現状はreturnのみ
static void	_on_update(t_sv_actor *self)
{
	size_t			i;
	struct timeval	now;
	long			*delta;
	t_ft_actor		*philo_ref;

	gettimeofday(&now, NULL);
	i = 0;
	while (i < self->prop->args.num_of_philos)
	{
		delta = philo_calloc(1, sizeof(long));
		if (!delta)
			return ;
		*delta = get_delta_ms(&self->prop->last_update_time, &now);
		philo_ref = self->prop->philos_ref[i++];
		philo_ref->tell(philo_ref, msg_new(UPDATE, NULL, delta));
	}
	self->prop->last_update_time = now;
}

static void	_on_actor_stop_done(t_sv_actor *sv)
{
	sv->prop->ref_count--;
	if (sv->prop->ref_count == 0)
	{
		sv->sys_notify_inbox->enq(sv->sys_notify_inbox,
			msg_new(ACTOR_STOP_DONE, NULL, NULL));
		ft_actor_stop(sv->base);
	}
}

void	_on_shut_down(t_sv_actor *self)
{
	size_t		i;

	i = 0;
	while (i < self->prop->args.num_of_philos)
	{
		ft_actor_stop(self->prop->philos_ref[i]);
		ft_actor_stop(self->prop->forks_ref[i]);
		i++;
	}
	ft_actor_stop(self->prop->monitor_ref);
}

bool	_sv_on_receive(t_ft_actor *self, t_ft_msg *msg)
{
	t_sv_actor	*sv;

	sv = self->ref;
	if (msg->type == ACTOR_START_DONE)
		_on_actor_start_done(sv);
	if (msg->type == UPDATE)
		_on_update(sv);
	if (msg->type == PHILO_DEAD)
		sv->sys_notify_inbox->enq(sv->sys_notify_inbox,
			msg_new(SYSTEM_STOP, NULL, NULL));
	if (msg->type == ACTOR_STOP_DONE)
		_on_actor_stop_done(sv);
	if (msg->type == SHUT_DOWN)
		_on_shut_down(sv);
	return (true);
}
