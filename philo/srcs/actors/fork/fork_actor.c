/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_actor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/17 22:20:58 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork_actor.h"

static void	on_start(t_ft_actor *self)
{
	t_fork_actor	*fork;

	fork = (t_fork_actor *)self->ref;
	fork->sts = FORK_AVAILABLE;
	fork->holder = NULL;
	self->parent->tell(self->parent, msg_new(ACTOR_START_DONE, self, NULL));
}

// TODO: 31行目にデバッグ出力を仕込みたい
static bool	on_receive(t_ft_actor *self, t_ft_msg *msg)
{
	t_fork_actor	*fork;

	if (!self || !self->ref || !msg)
		return (true);
	fork = self->ref;
	if (msg->type == REQUEST_FORK)
		_on_request_fork(fork, msg->sender);
	if (msg->type == RELEASE_FORK)
		_on_release_fork(fork, msg->sender);
	return (true);
}

void	fork_actor_del(t_fork_actor **fork_ptr)
{
	t_fork_actor	*fork;

	fork = *fork_ptr;
	if (!fork)
		return ;
	ft_actor_del(&fork->base);
	free(fork);
	*fork_ptr = NULL;
}

t_fork_actor	*fork_actor_new(void)
{
	t_fork_actor			*fork;
	const t_ft_actor_vtable	vtable = {
		.on_start = on_start,
		.on_receive = on_receive,
		.on_stop = NULL,
	};

	fork = philo_calloc(1, sizeof(t_fork_actor));
	if (!fork)
		return (NULL);
	fork->base = ft_actor_new(fork);
	if (!fork->base)
		return (fork_actor_del(&fork), NULL);
	fork->base->v = &vtable;
	return (fork);
}
