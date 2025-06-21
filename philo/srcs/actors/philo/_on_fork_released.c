/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _philo_actor_methods2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/21 18:38:19 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

void	_on_fork_released(t_philo_actor *self, t_ft_actor *sender)
{
	if (sender == self->l_fork)
		self->has_l_fork = false;
	if (sender == self->r_fork)
		self->has_r_fork = false;
	if (!(self->has_l_fork && self->has_r_fork))
		self->sts = PHILO_STS_SLEEPING;
}
