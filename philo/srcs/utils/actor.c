/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:34:15 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/06 17:37:24 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actor.h"

bool	default_tell(t_actor *self, t_msg *msg)
{
	return (self->msg_box->enqueue(self->msg_box, msg));
}

void	*actor_thread_main(void *arg)
{
	t_actor	*self;
	t_msg	*msg;

	self = (t_actor *)arg;
	if (!self || !self->vtable || !self->vtable->on_receive)
		return (NULL);
	while (true)
	{
		usleep(1000);
		msg = self->msg_box->dequeue(self->msg_box);
		if (!msg)
			continue ;
		if (!(self->vtable->on_receive(self, msg)))
		{
			free(msg);
			break ;
		}
		free(msg);
	}
	return (NULL);
}

t_actor	*actor_new(int id, void *ref, const t_actor_vtable *vtable)
{
	t_actor	*a;

	a = philo_calloc(1, sizeof(t_actor));
	if (!a)
		return (NULL);
	a->id = id;
	a->ref = ref;
	a->vtable = vtable;
	a->msg_box = queue_new();
	return (a);
}

void	actor_start(t_actor *self)
{
	pthread_create(&self->th_id, NULL, actor_thread_main, self);
}

void	actor_stop(t_actor **actor_pt)
{
	t_actor	*actor;

	actor = *actor_pt;
	pthread_join(actor->th_id, NULL);
	free(actor->msg_box);
	free(actor);
	*actor_pt = NULL;
}
