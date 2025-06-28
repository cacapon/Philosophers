/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_actor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/28 18:28:44 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork_actor.h"

void	fork_actor_del(t_fork_actor **fork_ptr)
{
	t_fork_actor	*fork;

	fork = *fork_ptr;
	if (!fork)
		return ;
	ft_actor_del(&fork->base);
	ft_queue_del(&fork->wait);
	free(fork);
	*fork_ptr = NULL;
}

t_fork_actor	*fork_actor_new(void)
{
	t_fork_actor					*fork;
	static const t_ft_actor_vtable	vtable = {
		.on_start = fork_on_start,
		.on_receive = fork_on_receive,
		.on_stop = NULL,
	};

	fork = philo_calloc(1, sizeof(t_fork_actor));
	if (!fork)
		return (NULL);
	fork->base = ft_actor_new(fork);
	fork->wait = ft_queue_new(NULL);
	if (!fork->base || !fork->wait)
		return (fork_actor_del(&fork), NULL);
	fork->base->v = &vtable;
	return (fork);
}
