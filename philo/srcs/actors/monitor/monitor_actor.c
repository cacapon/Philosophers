/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_actor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:11:18 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/21 18:44:53 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor_actor.h"

void	monitor_actor_del(t_monitor_actor **monitor)
{
	t_monitor_actor	*_monitor;

	if (!monitor || !*monitor)
		return ;
	_monitor = *monitor;
	ft_actor_del(&_monitor->base);
	free(_monitor);
	*monitor = NULL;
}

t_monitor_actor	*monitor_actor_new(void)
{
	t_monitor_actor					*monitor;
	static const t_ft_actor_vtable	vtable = {
		.on_start = monitor_on_start,
		.on_receive = monitor_on_receive,
		.on_stop = NULL,
	};

	monitor = philo_calloc(1, sizeof(t_monitor_actor));
	if (!monitor)
		return (NULL);
	monitor->base = ft_actor_new(monitor);
	if (!monitor->base)
		return (monitor_actor_del(&monitor), NULL);
	monitor->base->v = &vtable;
	return (monitor);
}
