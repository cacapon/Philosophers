/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _on_philo_eat_done.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 21:37:09 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/21 22:13:19 by ttsubo           ###   ########.fr       */
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
		_send_grant_eat(self);
	}
}

void	_on_philo_eat_done(t_sv_actor *self)
{
	_advance_to_next_phase(self);
}
