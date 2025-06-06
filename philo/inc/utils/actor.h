/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actor.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:34:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/06 10:50:00 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTOR_H
# define ACTOR_H

# include "philo_calloc.h"
# include "queue.h"
# include <pthread.h>

typedef struct s_actor		t_actor;

typedef struct s_actor_vtable
{
	void					(*on_start)(t_actor *self);
	bool					(*on_receive)(t_actor * self, t_msg * msg);
	void					(*on_stop)(t_actor *self);
	bool					(*tell)(t_actor * self, t_msg * msg);
}							t_actor_vtable;

typedef struct s_actor
{
	int						id;
	pthread_t				th_id;
	t_queue					*msg_box;
	void					*ref;
	const t_actor_vtable	*vtable;
}							t_actor;

bool						default_tell(t_actor *self, t_msg *msg);
t_actor						*actor_new(int id, void *ref,
								const t_actor_vtable *vtable);
void						actor_start(t_actor *actor);
void						actor_stop(t_actor **actor_pt);

#endif