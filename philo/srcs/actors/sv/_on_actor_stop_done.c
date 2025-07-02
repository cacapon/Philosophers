/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _on_actor_stop_done.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:50:17 by ttsubo            #+#    #+#             */
/*   Updated: 2025/07/02 20:13:18 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

static void	_join_actor(t_sv_actor *sv)
{
	int			i;
	t_ft_actor	*philo_ref;
	t_ft_actor	*fork_ref;
	t_ft_actor	*monitor_ref;

	i = 0;
	while (i < sv->prop->args.num_of_philos)
	{
		philo_ref = sv->prop->philos_ref[i];
		pthread_join(philo_ref->thread, NULL);
		fork_ref = sv->prop->forks_ref[i];
		pthread_join(fork_ref->thread, NULL);
		i++;
	}
	monitor_ref = sv->prop->monitor_ref;
	pthread_join(monitor_ref->thread, NULL);
}

void	_on_actor_stop_done(t_sv_actor *sv)
{
	sv->prop->ref_count--;
	if (sv->prop->ref_count == 0)
	{
		sv->sys_notify_inbox->enq(sv->sys_notify_inbox,
			msg_new(ACTOR_STOP_DONE, NULL));
		_join_actor(sv);
		ft_actor_stop(sv->base);
	}
}
