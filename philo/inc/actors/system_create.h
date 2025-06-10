/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_create.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:00:40 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/10 16:11:49 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_CREATE_H
# define SYSTEM_CREATE_H

# include "args.h"
# include "fork_actor.h"
# include "philo_actor.h"
# include "sv_actor.h"
# include "monitor_actor.h"

typedef struct s_system
{
	t_sv_actor		*sv;
	t_monitor_actor	*monitor;
	t_philo_actor	**philos;
	t_fork_actor	**forks;
}					t_system;

t_system	*system_create(t_main_args args);

#endif