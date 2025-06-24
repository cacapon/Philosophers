/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _sleeping.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 22:25:31 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

void	_sleeping(t_philo_actor *self, long delta)
{
	self->slp.now += delta;
	if (self->slp.now >= self->slp.max)
	{
		self->slp.now = 0;
		self->sts = PHILO_STS_THINKING;
		self->sv->tell(self->sv, msg_new(MONITOR_THINKING, self->base));
	}
}
