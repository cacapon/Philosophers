/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:09:06 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/16 22:13:12 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ACTOR_H
# define FT_ACTOR_H

# include "ft_actor_calloc.h"
# include "ft_queue.h"
# include "ft_actor_msg.h"
# include "stdbool.h"
# include <pthread.h>

typedef struct s_ft_actor	t_ft_actor;

typedef struct s_ft_actor_vtable
{
	void	(*on_start)(t_ft_actor *self);
	bool	(*on_receive)(t_ft_actor * self, t_ft_msg * msg);
	void	(*on_stop)(t_ft_actor *self);
}			t_ft_actor_vtable;

typedef struct s_ft_actor
{
	pthread_t				thread;
	t_ft_queue				*inbox;
	void					*ref;
	const t_ft_actor_vtable	*v;
	bool					(*tell)(t_ft_actor * self, t_ft_msg * msg);
	bool					is_running;
}							t_ft_actor;

t_ft_actor	*ft_actor_new(void *ref);
void		ft_actor_del(t_ft_actor **actor);
void		ft_actor_start(t_ft_actor *actor);
void		ft_actor_stop(t_ft_actor *actor);
bool		_ft_actor_tell(t_ft_actor *self, t_ft_msg *msg);

#endif