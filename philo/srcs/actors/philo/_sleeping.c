/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _sleeping.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/21 21:26:44 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

void	_sleeping(t_philo_actor *self, long delta)
{
	self->now_slp += delta;
	if (self->now_slp >= self->max_slp)
	{
		self->now_slp = 0;
		self->sts = PHILO_STS_THINKING;
		self->sv->tell(self->sv, msg_new(MONITOR_THINKING, self->base, NULL));
	}
}
