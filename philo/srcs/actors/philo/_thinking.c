/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _thinking.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/21 21:04:02 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

void	_thinking(t_philo_actor *self)
{
	bool (*l_tell)(t_ft_actor * self, t_ft_msg * msg);
	bool (*r_tell)(t_ft_actor * self, t_ft_msg * msg);
	l_tell = self->l_fork->tell;
	r_tell = self->r_fork->tell;
	if (!self->can_eat)
		return ;
	if (!self->has_l_fork)
		l_tell(self->l_fork, msg_new(REQUEST_FORK, self->base, NULL));
	if (!self->has_r_fork)
		r_tell(self->r_fork, msg_new(REQUEST_FORK, self->base, NULL));
	if (self->has_l_fork && self->has_r_fork)
	{
		self->sts = PHILO_STS_EATING;
		self->now_hp = self->max_hp;
		self->sv->tell(self->sv, msg_new(MONITOR_EATING, self->base, NULL));
	}
}
