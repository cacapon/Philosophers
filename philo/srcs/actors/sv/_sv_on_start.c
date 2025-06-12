/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _sv_on_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:08:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/12 13:11:43 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

static void	_start_forks(t_sv_actor *self)
{
	size_t	i;

	i = 0;
	while (i < self->prop->args.num_of_philos)
		actor_start(self->prop->forks_ref[i++]);
}

static void	_start_philos(t_sv_actor *self)
{
	size_t	i;

	i = 0;
	while (i < self->prop->args.num_of_philos)
		actor_start(self->prop->philos_ref[i++]);
}

static void	_start_monitor(t_sv_actor *self)
{
	actor_start(self->prop->monitor_ref);
}

void	sv_on_start(t_actor *self)
{
	t_sv_actor	*sv;

	sv = self->ref;
	_start_forks(sv);
	_start_philos(sv);
	_start_monitor(sv);
}
