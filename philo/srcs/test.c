/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:41:57 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/31 09:11:45 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actor.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static bool	_on_recieve(t_msg *msg)
{
	if (msg->type == PHILO_DEAD)
	{
		printf("bye actor%d\n", msg->sender->id);
		return (false);
	}
	if (msg->type == UPDATE)
		printf("hello actor%d\n", msg->sender->id);
	return (true);
}

void	*actor_start(void *arg)
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

t_actor	init_actor(int id)
{
	t_actor	actor;

	actor.id = id;
	actor.msg_box = malloc(sizeof(t_queue));
	queue_init(actor.msg_box);
	actor.on_recieve = _on_recieve;
	actor.ref = NULL;
	return (actor);
}

t_msg	*gen_msg(t_msg_type type, t_actor *sender, void *args)
{
	t_msg	*msg;

	msg = malloc(sizeof(t_msg));
	if (!msg)
		return (NULL);
	msg->sender = sender;
	msg->type = type;
	msg->args = args;
	return (msg);
}

// int	main(void)
// {
// 	t_actor actor1;
// 	t_actor actor2;
// 	pthread_t t1;
// 	pthread_t t2;

// 	actor1 = init_actor(1);
// 	actor2 = init_actor(2);
// 	pthread_create(&t1, NULL, actor_start, &actor1);
// 	pthread_create(&t2, NULL, actor_start, &actor2);
// 	for (int x = 0; x < 10; x++)
// 	{
// 		actor1.msg_box->enqueue(actor1.msg_box, gen_msg(UPDATE, &actor1, NULL));
// 		actor2.msg_box->enqueue(actor2.msg_box, gen_msg(UPDATE, &actor2, NULL));
// 		usleep(100000);
// 	}
// 	actor1.msg_box->enqueue(actor1.msg_box, gen_msg(PHILO_DEAD, &actor1, NULL));
// 	actor2.msg_box->enqueue(actor2.msg_box, gen_msg(PHILO_DEAD, &actor2, NULL));
// 	pthread_join(t1, NULL);
// 	pthread_join(t2, NULL);
// 	return (0);
// }
