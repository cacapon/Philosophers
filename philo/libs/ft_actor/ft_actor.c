/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:08:51 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/22 00:10:55 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_actor.h"

t_ft_actor	*ft_actor_new(void *ref)
{
	t_ft_actor	*a;

	a = ft_actor_calloc(1, sizeof(t_ft_actor));
	if (!a)
		return (NULL);
	a->inbox = ft_queue_new();
	a->emergency_inbox = ft_queue_new();
	a->is_running = false;
	a->tell = _ft_actor_tell;
	a->ref = ref;
	a->parent = NULL;
	if (!a->inbox || !a->emergency_inbox)
		ft_actor_del(&a);
	return (a);
}

void	ft_actor_del(t_ft_actor **a)
{
	t_ft_actor	*_a;

	_a = *a;
	ft_queue_del(&_a->inbox);
	ft_queue_del(&_a->emergency_inbox);
	free(_a);
	*a = NULL;
}

void	ft_actor_start(t_ft_actor *a)
{
	a->is_running = true;
	pthread_create(&a->thread, NULL, _ft_actor_loop, a);
}

void	ft_actor_stop(t_ft_actor *a)
{
	a->is_running = false;
	if (a->v && a->v->on_stop)
		a->v->on_stop(a);
	if (a->parent)
		a->parent->tell(a->parent, msg_new(ACTOR_STOP_DONE, a, NULL));
	pthread_join(a->thread, NULL);
}
