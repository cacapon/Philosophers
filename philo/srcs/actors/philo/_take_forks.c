/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _take_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:01:48 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/30 19:24:52 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

static void	_send_taken_fork_msg(t_philo_actor *self)
{
	t_ft_msg	*msg;
	t_timeval	now;

	msg = msg_new(MONITOR_TAKEN_FORK, self->base);
	gettimeofday(&now, NULL);
	self->last_update_time = now;
	if (msg)
		msg->data.tv = self->last_update_time;
	self->sv->tell(self->sv, msg);
}

static bool	_take_fork(t_philo_actor *self, t_fork *fork)
{
	fork->take(fork);
	_send_taken_fork_msg(self);
	return (true);
}

void	_take_forks(t_philo_actor *self)
{
	if (self->no % 2 == 0)
	{
		self->has_l_fork = _take_fork(self, self->l_fork);
		self->has_r_fork = _take_fork(self, self->r_fork);
	}
	else
	{
		self->has_r_fork = _take_fork(self, self->r_fork);
		self->has_l_fork = _take_fork(self, self->l_fork);
	}
}
