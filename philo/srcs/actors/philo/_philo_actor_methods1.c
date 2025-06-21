/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _philo_actor_methods1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/20 22:39:17 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"
#include <stdio.h>

// TODO: UPDATEは必ずlong型のargsを含むメッセージを渡されるのでそれ以外ならerrorにしたい
void	_common_update(t_philo_actor *self, t_ft_msg *msg)
{
	long	delta;

	if (!self || !msg || !msg->args)
		return ;
	delta = *(long *)(msg->args);
	self->now_hp -= delta;
	if (self->now_hp <= 0)
	{
		self->sts = PHILO_STS_DEAD;
		self->sv->tell(self->sv, msg_new(PHILO_DEAD, self->base, NULL));
	}
}

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
	}
}

void	_eating(t_philo_actor *self)
{
	bool (*l_tell)(t_ft_actor * self, t_ft_msg * msg);
	bool (*r_tell)(t_ft_actor * self, t_ft_msg * msg);
	bool (*sv_tell)(t_ft_actor * self, t_ft_msg * msg);
	l_tell = self->l_fork->tell;
	r_tell = self->r_fork->tell;
	sv_tell = self->sv->tell;
	self->now_eat++;
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

void	_sleeping(t_philo_actor *self)
{
	self->now_slp++;
	if (self->now_slp >= self->max_slp)
	{
		self->now_slp = 0;
		self->sts = PHILO_STS_THINKING;
	}
}
