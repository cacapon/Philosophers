/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _eating.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/30 20:18:31 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

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
		_put_forks(self);
		self->sts = PHILO_STS_SLEEPING;
		_send_monitor_msg(self, MONITOR_SLEEPING);
	}
}
