/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _thinking.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 23:11:39 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

static void	send_request_fork(t_ft_actor *fork, t_ft_actor *philo_ref)
{
	fork->tell(fork, msg_new(REQUEST_FORK, philo_ref));
}

void	_thinking(t_philo_actor *self)
{
	t_ft_msg	*msg;

	if (!self->can_eat)
		return ;
	if (!self->has_l_fork)
		send_request_fork(self->l_fork, self->base);
	if (!self->has_r_fork)
		send_request_fork(self->r_fork, self->base);
	if (self->has_l_fork && self->has_r_fork)
	{
		msg = msg_new(MONITOR_EATING, self->base);
		if (msg)
			msg->data.tv = self->last_update_time;
		self->sts = PHILO_STS_EATING;
		self->hp.now = self->hp.max;
		self->sv->tell(self->sv, msg);
	}
}
