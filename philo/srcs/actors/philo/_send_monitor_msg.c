/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _send_monitor_msg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:27:15 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/30 19:45:23 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

static long	_update_time(t_philo_actor *philo)
{
	t_timeval	now;
	long		delta;

	gettimeofday(&now, NULL);
	delta = get_delta_ms(&philo->last_update_time, &now);
	philo->last_update_time = now;
	return (delta);
}

void	_send_monitor_msg(t_philo_actor *self, int msg_type)
{
	t_ft_msg *msg;

	msg = msg_new(msg_type, self->base);
	_update_time(self);
	if (msg)
		msg->data.tv = self->last_update_time;
	self->sv->tell(self->sv, msg);
}
