/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:41:57 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/31 16:45:11 by ttsubo           ###   ########.fr       */
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

int	main(void)
{
	int		x;
	t_actor	*actor1;
	t_actor	*actor2;

	actor1 = init_actor(1, _on_recieve);
	actor2 = init_actor(2, _on_recieve);
	actor_start(actor1);
	actor_start(actor2);
	x = 0;
	while (x < 10)
	{
		actor1->tell(actor1, gen_msg(UPDATE, actor1, NULL));
		actor2->tell(actor1, gen_msg(UPDATE, actor2, NULL));
		usleep(100000);
		x++;
	}
	actor1->tell(actor1, gen_msg(PHILO_DEAD, actor1, NULL));
	actor2->tell(actor2, gen_msg(PHILO_DEAD, actor2, NULL));
	actor_stop(&actor1);
	actor_stop(&actor2);
	return (0);
}
