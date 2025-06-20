/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_actor.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:28:12 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/21 20:46:42 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_ACTOR_H
# define MONITOR_ACTOR_H

# include <stdio.h>
# include "ft_actor.h"
# include "philo_actor.h"
# include "philo_utils.h"

# define MSG_TAKEN_FORK "has taken a fork"
# define MSG_EATING "is eating"
# define MSG_SLEEPING "is sleeping"
# define MSG_THINKING "is thinking"
# define MSG_DIED "died"

typedef struct s_monitor_data
{
	long		timestamp;
	size_t		philo_no;
	int			msg_id;
}				t_monitor_data;

typedef struct s_monitor_actor
{
	t_ft_actor		*base;
}				t_monitor_actor;

t_monitor_actor	*monitor_actor_new(void);
void			monitor_actor_del(t_monitor_actor **monitor);
t_monitor_data	*monitor_data_new(long timestamp, size_t philo_no, int msg_id);
void			monitor_data_del(t_monitor_data **data);
void			monitor_on_start(t_ft_actor *self);
bool			monitor_on_receive(t_ft_actor *self, t_ft_msg *msg);
void			_show_monitor(t_ft_msg *msg);

#endif