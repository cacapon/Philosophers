/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:34:15 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/31 16:55:41 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actor.h"

static bool	_tell(t_actor *self, t_msg *msg)
{
	return (self->msg_box->enqueue(self->msg_box, msg));
}

static void	*_actor_loop(void *arg)
{
	t_actor	*actor;
	t_msg	*msg;

	actor = (t_actor *)arg;
	while (true)
	{
		usleep(1000);
		msg = actor->msg_box->dequeue(actor->msg_box);
		if (!msg)
			continue ;
		if (!(actor->on_recieve(msg)))
		{
			free(msg);
			break ;
		}
		free(msg);
	}
	return (NULL);
}

t_actor	*init_actor(int id, bool (*on_recieve)(t_msg *msg))
{
	t_actor	*actor;

	actor = malloc(sizeof(t_actor));
	if (!actor)
		return (NULL);
	actor->msg_box = queue_init();
	if (!actor->msg_box)
		return (NULL);
	actor->id = id;
	actor->th_id = 0;
	actor->on_recieve = on_recieve;
	actor->ref = NULL;
	actor->tell = _tell;
	return (actor);
}

void	actor_start(t_actor *actor)
{
	pthread_create(&actor->th_id, NULL, _actor_loop, actor);
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
