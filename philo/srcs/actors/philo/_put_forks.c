/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _put_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:01:48 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/30 19:54:59 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

static void	_put_r_fork(t_philo_actor *self)
{
	if (self->has_r_fork)
		self->r_fork->put(self->r_fork);
	self->has_r_fork = false;
}

static void	_put_l_fork(t_philo_actor *self)
{
	if (self->has_l_fork)
		self->l_fork->put(self->l_fork);
	self->has_l_fork = false;
}

void	_put_forks(t_philo_actor *self)
{
	if (self->no % 2 == 0)
	{
		_put_l_fork(self);
		_put_r_fork(self);
	}
	else
	{
		_put_r_fork(self);
		_put_l_fork(self);
	}
}
