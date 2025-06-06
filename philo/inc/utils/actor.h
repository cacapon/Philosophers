/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actor.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:34:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/06 10:16:03 by ttsubo           ###   ########.fr       */
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
	bool				(*on_start)(t_actor * self, t_msg * msg);
	bool				(*on_recieve)(t_actor * self, t_msg * msg);
	bool				(*on_stop)(t_actor * self, t_msg * msg);
	bool				(*tell)(t_actor * self, t_msg * msg);
}						t_actor;

t_actor					*init_actor(int id, bool (*on_recieve)(t_msg *msg));
void					actor_start(t_actor *actor);
void					actor_stop(t_actor **actor_pt);

#endif