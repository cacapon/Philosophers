/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _thinking.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/28 20:21:04 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

void	_thinking(t_philo_actor *self)
{
	t_ft_msg	*msg;

	if (!self->can_eat)
		return ;
	if (self->has_l_fork && self->has_r_fork)
	{
		msg = msg_new(MONITOR_EATING, self->base);
		if (msg)
			msg->data.tv = self->last_update_time;
		self->sts = PHILO_STS_EATING;
		self->hp.now = self->hp.max;
		self->sv->tell(self->sv, msg_new(PHILO_EAT_START, NULL));
		self->can_eat = false;
		self->sv->tell(self->sv, msg);
	}
}
