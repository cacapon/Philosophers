/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _fork_actor_methods.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/06 17:08:13 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork_actor.h"

void	_on_request_fork(t_fork_actor *fork, t_actor *sender)
{
	if (fork->holder == sender)
		return ;
	if (fork->sts == FORK_AVAILABLE)
	{
		fork->sts = FORK_HELD;
		fork->holder = sender;
		sender->vtable->tell(sender, gen_msg(GRANT_FORK, fork->base, NULL));
	}
}

void	_on_release_fork(t_fork_actor *fork, t_actor *sender)
{
	if (fork->holder != sender)
		return ;
	if (fork->sts == FORK_HELD)
	{
		fork->sts = FORK_AVAILABLE;
		fork->holder = NULL;
		sender->vtable->tell(sender, gen_msg(FORK_RELEASED, fork->base, NULL));
	}
}

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
