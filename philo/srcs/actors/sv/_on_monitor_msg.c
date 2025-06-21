/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _on_monitor_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:59:18 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/21 19:20:25 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor_actor.h"
#include "sv_actor.h"

static long	_get_timestamp(t_sv_actor *self)
{
	long			timestamp;
	struct timeval	now;

	gettimeofday(&now, NULL);
	timestamp = get_delta_ms(&self->prop->start, &now);
	return (timestamp);
}

void	_on_monitor_msg(t_sv_actor *self, t_ft_msg *msg)
{
	t_ft_actor		*monitor_ref;
	t_philo_actor	*sender;
	t_monitor_data	*data;
	long			timestamp;

	sender = (t_philo_actor *)msg->sender->ref;
	timestamp = _get_timestamp(self);
	data = monitor_data_new(timestamp, sender->no, msg->type);
	monitor_ref = self->prop->monitor_ref;
	monitor_ref->tell(monitor_ref, msg_new(msg->type, msg->sender, data));
}
