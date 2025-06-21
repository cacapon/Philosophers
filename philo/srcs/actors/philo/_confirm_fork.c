/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _confirm_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/21 21:01:31 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

void	_confirm_fork(t_philo_actor *self, t_ft_actor *sender)
{
	if (sender == self->l_fork)
	{
		self->has_l_fork = true;
		self->sv->tell(self->sv, msg_new(MONITOR_TAKEN_FORK, self->base, NULL));
	}
	if (sender == self->r_fork)
	{
		self->has_r_fork = true;
		self->sv->tell(self->sv, msg_new(MONITOR_TAKEN_FORK, self->base, NULL));
	}
}
