/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _philo_actor_methods1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/07 13:12:10 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

void	_common_update(t_philo_actor *self, t_actor *sender)
{
	self->now_hp--;
	if (self->now_hp == 0)
	{
		self->sts = PHILO_DEAD;
		sender->vtable->tell(sender, gen_msg(PHILO_DEAD, self->base, self));
	}
}

void	_thinking(t_philo_actor *self)
{
	bool (*l_tell)(t_actor * self, t_msg * msg);
	bool (*r_tell)(t_actor * self, t_msg * msg);
	l_tell = self->l_fork->vtable->tell;
	r_tell = self->r_fork->vtable->tell;
	if (!self->can_eat)
		return ;
	if (!self->has_l_fork)
		l_tell(self->l_fork, gen_msg(REQUEST_FORK, self->base, NULL));
	if (!self->has_r_fork)
		r_tell(self->r_fork, gen_msg(REQUEST_FORK, self->base, NULL));
	if (self->has_l_fork && self->has_r_fork)
	{
		self->sts = PHILO_STS_EATING;
		self->now_hp = self->max_hp;
	}
}

void	_eating(t_philo_actor *self, t_actor *sender)
{
	bool (*l_tell)(t_actor * self, t_msg * msg);
	bool (*r_tell)(t_actor * self, t_msg * msg);
	bool (*sv_tell)(t_actor * self, t_msg * msg);
	l_tell = self->l_fork->vtable->tell;
	r_tell = self->r_fork->vtable->tell;
	sv_tell = sender->vtable->tell;
	self->now_eat++;
	if (self->now_eat >= self->max_eat)
	{
		self->eat_count++;
		self->now_eat = 0;
		l_tell(self->l_fork, gen_msg(RELEASE_FORK, self->base, NULL));
		r_tell(self->r_fork, gen_msg(RELEASE_FORK, self->base, NULL));
		sv_tell(sender, gen_msg(PHILO_EAT_DONE, NULL, NULL));
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
