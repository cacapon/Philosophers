/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_actor.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:28:12 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/10 15:43:18 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_ACTOR_H
# define MONITOR_ACTOR_H

# include <stdio.h>
# include "actor.h"
# include "philo_actor.h"

# define MSG_TAKEN_FORK "has taken a fork"
# define MSG_EATING "is eating"
# define MSG_SLEEPING "is sleeping"
# define MSG_DIED "died"

typedef struct s_monitor_data
{
	time_t		timestamp;
	int			philo_no;
	int			msg_id;
}				t_monitor_data;

typedef struct s_monitor_actor
{
	t_actor		*base;
}				t_monitor_actor;

t_monitor_actor	*monitor_actor_new(int id);
void			free_monitor(t_monitor_actor **monitor_ptr);
void			_show_monitor(t_msg *msg);

#endif