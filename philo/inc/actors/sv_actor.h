/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_actor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:42:51 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/17 23:09:28 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SV_ACTOR_H
# define SV_ACTOR_H

# include <stdint.h>
# include "args.h"
# include "ft_actor.h"
# include "philo_msg.h"
# include "matrix.h"
# include "philo_calloc.h"
# include "get_elapsed_ms.h"

typedef struct s_sv_prop
{
	t_size_t_matrix	*send_ptn;
	t_main_args		args;
	struct timeval	start;
	size_t			philo_done_count;
	size_t			ptn_i;
	t_ft_actor		**philos_ref;
	t_ft_actor		**forks_ref;
	t_ft_actor		*monitor_ref;
	size_t			ref_count;
	size_t			start_done_count;
}					t_sv_prop;

typedef struct s_sv_actor
{
	t_ft_queue		*sys_notify_inbox;
	t_ft_actor		*base;
	t_sv_prop		*prop;
}					t_sv_actor;

t_sv_actor			*sv_actor_new(t_main_args args);
void				sv_actor_del(t_sv_actor **sv);
t_sv_prop			*_sv_prop_new(t_main_args args);
void				sv_prop_del(t_sv_prop **prop);

// methods
bool				_sv_on_receive(t_ft_actor *self, t_ft_msg *msg);
t_size_t_matrix		*_create_send_ptn(size_t n);
void				_advance_to_next_phase(t_sv_actor *self);
void				_send_grant_eat(t_sv_actor *self);

#endif