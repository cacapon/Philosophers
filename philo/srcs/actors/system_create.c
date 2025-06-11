/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:27:01 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/11 10:38:33 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system_create.h"

static void	_free_system(t_system **sys_ptr, size_t num)
{
	size_t		i;
	t_system	*sys;

	sys = *sys_ptr;
	i = 0;
	while (i < num)
	{
		free_philo(&sys->philos[i]);
		free_fork(&sys->forks[i]);
		i++;
	}
	free(sys->forks);
	free(sys->philos);
	free_sv(&sys->sv);
	free_monitor(&sys->monitor);
	free(sys);
	*sys_ptr = NULL;
}

static t_system	*_calloc_system(size_t num)
{
	t_system	*sys;

	sys = philo_calloc(1, sizeof(t_system));
	if (!sys)
		return (NULL);
	sys->philos = philo_calloc(num, sizeof(t_philo_actor *));
	sys->forks = philo_calloc(num, sizeof(t_fork_actor *));
	if (!sys->philos || !sys->forks)
		return (_free_system(&sys, 0), NULL);
	return (sys);
}

static t_system	*_system_new(t_system *sys, t_main_args args)
{
	size_t	i;

	i = 0;
	sys->sv = sv_actor_new(0, args);
	sys->monitor = monitor_actor_new(0);
	if (!sys->sv || !sys->monitor)
		return (_free_system(&sys, i), NULL);
	while (i < args.num_of_philos)
	{
		sys->forks[i] = fork_actor_new(i);
		sys->philos[i] = philo_actor_new(i + 1, args);
		if (!sys->forks || !sys->philos)
			return (_free_system(&sys, i), NULL);
		i++;
	}
	return (sys);
}

static t_system	*_system_ref(t_system *sys, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		sys->sv->prop->philos_ref[i] = sys->philos[i]->base;
		sys->philos[i]->sv = sys->sv->base;
		sys->philos[i]->l_fork = sys->forks[(i - 1) % len]->base;
		sys->philos[i]->r_fork = sys->forks[i % len]->base;
		i++;
	}
	return (sys);
}

t_system	*system_create(t_main_args args)
{
	t_system	*sys;

	sys = _calloc_system(args.num_of_philos);
	sys = _system_new(sys, args);
	sys = _system_ref(sys, args.num_of_philos);
	return (sys);
}
