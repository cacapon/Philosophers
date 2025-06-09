/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_actor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:42:51 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/09 19:27:24 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SV_ACTOR_H
# define SV_ACTOR_H

# include "main.h"
# include "actor.h"
# include "matrix.h"
# include "philo_calloc.h"
# include <stdint.h>

typedef struct s_sv_prop
{
	t_size_t_matrix	*send_ptn;
	t_main_args		args;
	uint64_t		timestamp;
	size_t			philo_done_count;
	size_t			ptn_i;
	t_actor			**forks_ref;
	t_actor			**philos_ref;
}					t_sv_prop;

typedef struct s_sv_actor
{
	t_actor			*base;
	t_sv_prop		*prop;
}					t_sv_actor;

void				free_send_patterns(size_t ***ptns_ptr);
void				free_sv(t_sv_actor **sv_ptr);
t_sv_actor			*sv_actor_new(int id, t_main_args args);
t_sv_prop			*_sv_prop_new(t_main_args args);
t_size_t_matrix		*_create_send_ptn(size_t n);
void				_advance_to_next_phase(t_sv_actor *self);

#endif