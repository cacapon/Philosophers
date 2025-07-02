/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _sleeping.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/30 16:14:15 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

void	_sleeping(t_philo_actor *self, long delta)
{
	t_ft_msg	*msg;

	self->slp.now += delta;
	if (self->slp.now >= self->slp.max)
	{
		self->slp.now = 0;
		self->sts = PHILO_STS_THINKING;
		msg = msg_new(MONITOR_THINKING, self->base);
		if (msg)
			msg->data.tv = self->last_update_time;
		self->sv->tell(self->sv, msg);
		_send_request_forks(self);
	}
}
