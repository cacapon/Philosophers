/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_actor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:42:51 by ttsubo            #+#    #+#             */
/*   Updated: 2025/07/03 11:37:24 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SV_ACTOR_H
# define SV_ACTOR_H

# include "args.h"
# include "philo_define.h"
# include "ft_actor.h"
# include "matrix.h"
# include "philo_msg.h"
# include "philo_utils.h"
# include <stdint.h>

typedef struct s_sv_prop
{
	t_size_t_matrix	*send_ptn;
	t_main_args		args;
	t_timeval		start;
	t_timeval		last_update_time;
	size_t			philo_done_count;
	size_t			ptn_i;
	t_ft_actor		**philos_ref;
	t_ft_actor		**forks_ref;
	t_ft_actor		*monitor_ref;
	size_t			ref_count;
	size_t			start_done_count;
	int				philo_finished_eat_count;
}					t_sv_prop;

typedef struct s_sv_actor
{
	t_ft_queue		*sys_notify_inbox;
	t_ft_actor		*base;
	t_sv_prop		*prop;
}					t_sv_actor;

t_sv_actor			*sv_actor_new(t_main_args args);
void				sv_actor_del(t_sv_actor **sv);

// vtable
void				sv_on_start(t_ft_actor *self);
bool				sv_on_receive(t_ft_actor *self, t_ft_msg *msg);

// on_recieved
void				_on_actor_start_done(t_sv_actor *self);
void				_on_actor_stop_done(t_sv_actor *self);
void				_on_update(t_sv_actor *self);
void				_on_philo_eat_start(t_sv_actor *self);
void				_on_philo_dead(t_sv_actor *self);
void				_on_sv_shut_down(t_sv_actor *self);
void				_on_monitor_msg(t_sv_actor *self, t_ft_msg *msg);
void				_on_philo_finished_eating(t_sv_actor *self);

// methods
t_size_t_matrix		*_create_send_ptn(size_t n);

#endif