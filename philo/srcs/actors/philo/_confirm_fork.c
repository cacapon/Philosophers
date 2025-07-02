/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _confirm_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 23:12:37 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

static void	_send_taken_fork_msg(t_philo_actor *self)
{
	t_ft_msg	*msg;

	msg = msg_new(MONITOR_TAKEN_FORK, self->base);
	if (msg)
		msg->data.tv = self->last_update_time;
	self->sv->tell(self->sv, msg);
}

void	_confirm_fork(t_philo_actor *self, t_ft_actor *sender)
{
	if (sender == self->l_fork)
	{
		self->has_l_fork = true;
		_send_taken_fork_msg(self);
	}
	if (sender == self->r_fork)
	{
		self->has_r_fork = true;
		_send_taken_fork_msg(self);
	}
}
