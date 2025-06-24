/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:09:06 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 15:34:10 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ACTOR_H
# define FT_ACTOR_H

# include "ft_actor_calloc.h"
# include "ft_queue.h"
# include "ft_actor_msg.h"
# include "stdbool.h"
# include <sys/time.h>	
# include <pthread.h>

typedef struct s_ft_actor	t_ft_actor;

typedef struct s_ft_actor_vtable
{
	void	(*on_start)(t_ft_actor *self);
	bool	(*on_receive)(t_ft_actor * self, t_ft_msg * msg);
	void	(*on_stop)(t_ft_actor *self);
	void	(*update)(t_ft_actor *self);
}			t_ft_actor_vtable;

typedef struct s_ft_actor
{
	pthread_t				thread;
	struct timeval			start;
	t_ft_queue				*inbox;
	t_ft_queue				*emergency_inbox;
	void					*ref;
	t_ft_actor				*parent;
	const t_ft_actor_vtable	*v;
	bool					(*tell)(t_ft_actor * self, t_ft_msg * msg);
	bool					(*eg_tell)(t_ft_actor * self, t_ft_msg * msg);
	bool					is_running;
}							t_ft_actor;

t_ft_actor	*ft_actor_new(void *ref);
void		ft_actor_del(t_ft_actor **actor);
void		ft_actor_start(t_ft_actor *actor);
void		ft_actor_stop(t_ft_actor *actor);
void		*_ft_actor_loop(void *arg);
void		ft_actor_set_parent(t_ft_actor *actor, t_ft_actor *parent);
bool		_ft_actor_tell(t_ft_actor *self, t_ft_msg *msg);
bool		_ft_actor_eg_tell(t_ft_actor *self, t_ft_msg *msg);

#endif