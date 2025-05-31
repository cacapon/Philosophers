/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actor.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:34:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/31 16:39:54 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTOR_H
# define ACTOR_H

# include "queue.h"
# include <pthread.h>

typedef struct s_actor	t_actor;

typedef struct s_actor
{
	int					id;
	pthread_t			th_id;
	t_queue				*msg_box;
	void				*ref;
	bool				(*on_recieve)(t_msg * msg);
	bool				(*tell)(t_actor * self, t_msg * msg);
	void				(*stop)(t_actor *self);
}						t_actor;

t_actor					*init_actor(int id, bool (*on_recieve)(t_msg *msg));
void					actor_start(t_actor *actor);

#endif