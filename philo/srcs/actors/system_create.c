/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:27:01 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/12 13:19:06 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

static t_system	*_calloc_system(size_t num)
{
	t_system	*sys;

	sys = philo_calloc(1, sizeof(t_system));
	if (!sys)
		return (NULL);
	sys->philos = philo_calloc(num, sizeof(t_philo_actor *));
	sys->forks = philo_calloc(num, sizeof(t_fork_actor *));
	if (!sys->philos || !sys->forks)
		return (free_system(&sys, 0), NULL);
	return (sys);
}

static t_system	*_system_new(t_system *sys, t_main_args args)
{
	size_t	i;

	i = 0;
	sys->num = args.num_of_philos;
	sys->sv = sv_actor_new(0, args);
	sys->monitor = monitor_actor_new(0);
	if (!sys->sv || !sys->monitor)
		return (free_system(&sys, i), NULL);
	while (i < sys->num)
	{
		sys->forks[i] = fork_actor_new(i);
		sys->philos[i] = philo_actor_new(i + 1, args);
		if (!sys->forks || !sys->philos)
			return (free_system(&sys, i), NULL);
		i++;
	}
	return (sys);
}

static t_system	*_system_ref(t_system *sys)
{
	size_t	i;

	i = 0;
	while (i < sys->num)
	{
		sys->sv->prop->philos_ref[i] = sys->philos[i]->base;
		sys->sv->prop->forks_ref[i] = sys->forks[i]->base;
		sys->philos[i]->sv = sys->sv->base;
		sys->philos[i]->l_fork = sys->forks[(i - 1) % sys->num]->base;
		sys->philos[i]->r_fork = sys->forks[i % sys->num]->base;
		i++;
	}
	sys->sv->prop->monitor_ref = sys->monitor->base;
	return (sys);
}

t_system	*system_create(t_main_args args)
{
	t_system	*sys;

	sys = _calloc_system(args.num_of_philos);
	sys = _system_new(sys, args);
	sys = _system_ref(sys);
	return (sys);
}
