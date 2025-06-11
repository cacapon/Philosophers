/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:00:40 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/11 10:52:23 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_H
# define SYSTEM_H

# include "args.h"
# include "fork_actor.h"
# include "monitor_actor.h"
# include "philo_actor.h"
# include "sv_actor.h"

typedef struct s_system
{
	size_t			num;
	t_sv_actor		*sv;
	t_monitor_actor	*monitor;
	t_philo_actor	**philos;
	t_fork_actor	**forks;
}					t_system;

t_system			*system_create(t_main_args args);
void				free_system(t_system **sys_ptr, size_t num);
void				system_destroy(t_system **sys_ptr);

#endif