/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:27:01 by ttsubo            #+#    #+#             */
/*   Updated: 2025/07/02 14:42:48 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

void	system_del(t_system **sys, size_t num)
{
	size_t		i;
	t_system	*_sys;

	if (!sys || !*sys)
		return ;
	_sys = *sys;
	i = 0;
	while (i < num)
	{
		philo_actor_del(&_sys->philos[i]);
		fork_actor_del(&_sys->forks[i]);
		i++;
	}
	free(_sys->forks);
	free(_sys->philos);
	sv_actor_del(&_sys->sv);
	monitor_actor_del(&_sys->monitor);
	ft_queue_del(&_sys->notify_inbox);
	free(_sys);
	*sys = NULL;
}

static t_system	*_calloc_system(int num)
{
	t_system	*sys;

	sys = philo_calloc(1, sizeof(t_system));
	if (!sys)
		return (NULL);
	sys->philos = philo_calloc(num, sizeof(t_philo_actor *));
	sys->forks = philo_calloc(num, sizeof(t_fork_actor *));
	if (!sys->philos || !sys->forks)
		return (system_del(&sys, 0), NULL);
	return (sys);
}

static t_system	*_system_new(t_system *sys, t_main_args args)
{
	int	i;

	i = 0;
	sys->num = args.num_of_philos;
	sys->sv = sv_actor_new(args);
	sys->monitor = monitor_actor_new();
	sys->notify_inbox = ft_queue_new((t_ft_deleter)msg_del);
	if (!sys->sv || !sys->monitor || !sys->notify_inbox)
		return (system_del(&sys, i), NULL);
	while (i < sys->num)
	{
		sys->forks[i] = fork_actor_new();
		sys->philos[i] = philo_actor_new(i + 1, args);
		if (!sys->forks || !sys->philos)
			return (system_del(&sys, i), NULL);
		i++;
	}
	return (sys);
}

static t_system	*_system_ref(t_system *sys)
{
	int	i;

	i = 0;
	while (i < sys->num)
	{
		sys->sv->prop->philos_ref[i] = sys->philos[i]->base;
		sys->sv->prop->forks_ref[i] = sys->forks[i]->base;
		sys->philos[i]->sv = sys->sv->base;
		sys->philos[i]->l_fork = sys->forks[i % sys->num]->base;
		sys->philos[i]->r_fork = sys->forks[(i + 1) % sys->num]->base;
		if (sys->philos[i]->l_fork == sys->philos[i]->r_fork)
			sys->philos[i]->r_fork = NULL;
		ft_actor_set_parent(sys->philos[i]->base, sys->sv->base);
		ft_actor_set_parent(sys->forks[i]->base, sys->sv->base);
		i++;
	}
	sys->sv->prop->monitor_ref = sys->monitor->base;
	ft_actor_set_parent(sys->monitor->base, sys->sv->base);
	sys->sv->sys_notify_inbox = sys->notify_inbox;
	return (sys);
}

t_system	*system_new(t_main_args args)
{
	t_system	*sys;

	sys = _calloc_system(args.num_of_philos);
	sys = _system_new(sys, args);
	sys = _system_ref(sys);
	return (sys);
}
