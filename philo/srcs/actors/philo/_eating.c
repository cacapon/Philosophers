/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _eating.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/30 19:30:39 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

static bool _put_fork(t_fork *fork)
{
	fork->put(fork);
	return (false);
}

void	_eating(t_philo_actor *self, long delta)
{
	bool (*sv_tell)(t_ft_actor * self, t_ft_msg * msg);
	sv_tell = self->sv->tell;
	self->eat.now += delta;
	if (self->eat.now >= self->eat.max)
	{
		self->eat_count++;
		if (self->eat_count == self->max_eat_count)
			sv_tell(self->sv, msg_new(PHILO_FINISHED_EATING, NULL));
		self->eat.now = 0;
		self->has_l_fork = _put_fork(self->l_fork);
		self->has_r_fork = _put_fork(self->l_fork);
		self->sts = PHILO_STS_SLEEPING;
		_send_monitor_msg(self, MONITOR_SLEEPING);
	}
}
