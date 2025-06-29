/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:00:40 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/29 12:58:30 by ttsubo           ###   ########.fr       */
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
	int				num;
	t_ft_queue		*notify_inbox;
	t_sv_actor		*sv;
	t_monitor_actor	*monitor;
	t_philo_actor	**philos;
	t_fork_actor	**forks;
}					t_system;

t_system			*system_new(t_main_args args);
void				system_del(t_system **sys, size_t num);
void				system_run(t_system *sys);

#endif