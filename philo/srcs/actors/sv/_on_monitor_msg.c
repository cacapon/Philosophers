/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _on_monitor_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:59:18 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 13:52:20 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor_actor.h"
#include "sv_actor.h"

static long	_get_timestamp(t_sv_actor *self)
{
	long		timestamp;
	t_timeval	now;

	gettimeofday(&now, NULL);
	timestamp = get_delta_ms(&self->prop->start, &now);
	return (timestamp);
}

void	_on_monitor_msg(t_sv_actor *self, t_ft_msg *rv_msg)
{
	t_ft_actor	*monitor_ref;
	t_ft_msg	*msg;

	msg = msg_new(rv_msg->type, rv_msg->sender, NULL);
	if (!msg)
		return ;
	msg->data.l = _get_timestamp(self);
	monitor_ref = self->prop->monitor_ref;
	monitor_ref->tell(monitor_ref, msg);
}
