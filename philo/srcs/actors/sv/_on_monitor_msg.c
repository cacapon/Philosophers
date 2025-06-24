/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _on_monitor_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:59:18 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 23:14:24 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor_actor.h"
#include "sv_actor.h"

void	_on_monitor_msg(t_sv_actor *self, t_ft_msg *rv_msg)
{
	t_ft_actor	*monitor_ref;
	t_ft_msg	*msg;

	msg = msg_new(rv_msg->type, rv_msg->sender);
	if (!msg)
		return ;
	msg->data.l = tvtol(&rv_msg->data.tv) - tvtol(&self->prop->start);
	monitor_ref = self->prop->monitor_ref;
	monitor_ref->tell(monitor_ref, msg);
}
