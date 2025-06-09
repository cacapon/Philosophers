/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_actor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:42:51 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/09 18:08:58 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SV_ACTOR_H
# define SV_ACTOR_H

# include "actor.h"
# include "philo_calloc.h"
# include "matrix.h"
# include <stdint.h>

typedef struct s_actor_ref	t_actor_ref;

typedef struct s_sv_prop
{
	int						**send_ptn;
	size_t					num;
	size_t					t_die;
	size_t					t_eat;
	size_t					t_slp;
	uint64_t				timestamp;
	size_t					philo_done_count;
	size_t					ptn_i;
	t_actor_ref				*forks_ref;
	t_actor_ref				*philos_ref;
}							t_sv_prop;

typedef struct s_sv_method
{
	void					(*on_start)(t_actor *self);
	void					(*on_recieve)(t_actor *self, t_msg *msg);
	void					(*on_stop)(t_actor *self);
}							t_sv_method;

typedef struct s_sv_actor
{
	t_actor					*base;
	t_sv_prop				prop;
	t_sv_method				method;
}							t_sv_actor;

void						free_send_patterns(size_t ***ptns_ptr);
void						free_sv(t_sv_actor **sv_ptr);
t_sv_actor					*sv_actor_new(int id);
t_size_t_matrix				*_create_send_ptn(size_t n);

#endif