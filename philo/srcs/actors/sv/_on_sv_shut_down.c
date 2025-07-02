/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _on_sv_shut_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:50:17 by ttsubo            #+#    #+#             */
/*   Updated: 2025/07/02 19:46:00 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

void	_on_sv_shut_down(t_sv_actor *self)
{
	int			i;
	t_ft_actor	*philo_ref;
	t_ft_actor	*fork_ref;
	t_ft_actor	*monitor_ref;

	i = 0;
	while (i < self->prop->args.num_of_philos)
	{
		philo_ref = self->prop->philos_ref[i];
		fork_ref = self->prop->forks_ref[i];
		philo_ref->eg_tell(philo_ref, msg_new(SHUT_DOWN, NULL));
		fork_ref->eg_tell(fork_ref, msg_new(SHUT_DOWN, NULL));
		i++;
	}
	monitor_ref = self->prop->monitor_ref;
	monitor_ref->eg_tell(monitor_ref, msg_new(SHUT_DOWN, NULL));
}
