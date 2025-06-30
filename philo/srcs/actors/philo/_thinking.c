/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _thinking.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/30 19:43:20 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

void	_thinking(t_philo_actor *self)
{
	if (self->has_l_fork && self->has_r_fork)
	{
		_send_monitor_msg(self, MONITOR_EATING);
		self->sts = PHILO_STS_EATING;
		self->hp.now = self->hp.max;
		self->sv->tell(self->sv, msg_new(PHILO_EAT_START, NULL));
	}
}
