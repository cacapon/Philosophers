/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_actor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/06 17:07:53 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork_actor.h"

static void	*on_start(t_actor *self)
{
	t_fork_actor	*fork;

	fork = (t_fork_actor *)self->ref;
	fork->sts = FORK_AVAILABLE;
	fork->holder = NULL;
	return (NULL);
}

// TODO: 31行目にデバッグ出力を仕込みたい
static bool	*on_receive(t_actor *self, t_msg *msg)
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

void	free_fork(t_fork_actor **fork_ptr)
{
	t_fork_actor	*fork;

	fork = *fork_ptr;
	if (!fork)
		return ;
	free_actor(&fork->base);
	free(fork);
	*fork_ptr = NULL;
}

t_fork_actor	*fork_actor_new(int id)
{
	t_fork_actor			*fork;
	const t_actor_vtable	vtable = {
		.on_start = on_start,
		.on_receive = on_receive,
		.on_stop = NULL,
		.tell = default_tell};

	fork = philo_calloc(1, sizeof(t_fork_actor));
	if (!fork)
		return (NULL);
	fork->base = actor_new(id, fork, &vtable);
	if (!fork->base)
		return (free_fork(fork->base), NULL);
	return (fork);
}
