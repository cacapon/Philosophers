/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _eating.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/21 21:26:27 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

void	_eating(t_philo_actor *self, long delta)
{
	bool (*l_tell)(t_ft_actor * self, t_ft_msg * msg);
	bool (*r_tell)(t_ft_actor * self, t_ft_msg * msg);
	bool (*sv_tell)(t_ft_actor * self, t_ft_msg * msg);
	l_tell = self->l_fork->tell;
	r_tell = self->r_fork->tell;
	sv_tell = self->sv->tell;
	self->now_eat += delta;
	if (self->now_eat >= self->max_eat)
	{
		self->eat_count++;
		self->now_eat = 0;
		l_tell(self->l_fork, msg_new(RELEASE_FORK, self->base, NULL));
		r_tell(self->r_fork, msg_new(RELEASE_FORK, self->base, NULL));
		sv_tell(self->sv, msg_new(PHILO_EAT_DONE, NULL, NULL));
		self->can_eat = false;
		self->sts = PHILO_STS_WAITING;
	}
}
