/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _on_fork_released.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/30 18:54:44 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

void	_on_fork_released(t_philo_actor *self, t_ft_actor *sender)
{
	(void) self;
	(void) sender;
//	t_ft_msg	*msg;
//
//	if (sender == self->l_fork)
//		self->has_l_fork = false;
//	if (sender == self->r_fork)
//		self->has_r_fork = false;
//	if (!self->has_l_fork && !self->has_r_fork)
//	{
//		self->sts = PHILO_STS_SLEEPING;
//		msg = msg_new(MONITOR_SLEEPING, self->base);
//		if (msg)
//			msg->data.tv = self->last_update_time;
//		self->sv->tell(self->sv, msg);
//	}
}
