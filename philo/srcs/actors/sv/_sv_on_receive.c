/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _sv_on_receive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:50:17 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/17 22:00:59 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

static void	_on_actor_start_done(t_sv_actor *self)
{
	self->prop->start_done_count++;
	if (self->prop->start_done_count == self->prop->ref_count)
		self->sys_notify_inbox->enq(
			self->sys_notify_inbox, msg_new(ACTOR_START_DONE, NULL, NULL));
}

bool	_sv_on_receive(t_ft_actor *self, t_ft_msg *msg)
{
	t_sv_actor	*sv;

	sv = self->ref;
	if (msg->type == ACTOR_START_DONE)
		_on_actor_start_done(sv);
	return (true);
}
