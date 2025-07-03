/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _on_philo_eat_start.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:40:20 by ttsubo            #+#    #+#             */
/*   Updated: 2025/07/03 11:38:23 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

static void	_advance_to_next_phase(t_sv_actor *self)
{
	self->prop->philo_done_count++;
	if (self->prop->philo_done_count >= self->prop->send_ptn->col)
	{
		self->prop->philo_done_count = 0;
		self->prop->ptn_i = (self->prop->ptn_i + 1) % self->prop->send_ptn->row;
	}
}

void	_on_philo_eat_start(t_sv_actor *self)
{
	_advance_to_next_phase(self);
}
