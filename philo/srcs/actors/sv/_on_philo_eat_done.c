/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _on_philo_eat_done.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 21:37:09 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/21 21:47:37 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

static void	_advance_to_next_phase(t_sv_actor *self)
{
	size_t		i;
	t_ft_actor	*philo;

	self->prop->philo_done_count++;
	if (self->prop->philo_done_count >= self->prop->send_ptn->col)
	{
		self->prop->philo_done_count = 0;
		self->prop->ptn_i = (self->prop->ptn_i + 1) % self->prop->send_ptn->row;
		i = 0;
		while (i < self->prop->send_ptn->col)
		{
			philo = self->prop->philos_ref[i++];
			philo->tell(philo, msg_new(GRANT_EAT, NULL, NULL));
		}
	}
}

void	_on_philo_eat_done(t_sv_actor *self)
{
	_advance_to_next_phase(self);
}
