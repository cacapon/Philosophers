/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:46:19 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/11 10:56:53 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

void	free_system(t_system **sys_ptr, size_t num)
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

void	system_destroy(t_system **sys_ptr)
{
	if (!sys_ptr || !*sys_ptr)
		return ;
	free_system(sys_ptr, (*sys_ptr)->num);
}
