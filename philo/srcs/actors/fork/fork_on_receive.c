/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_on_receive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/07/02 19:46:38 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork_actor.h"

// TODO: 31行目にデバッグ出力を仕込みたい
bool	fork_on_receive(t_ft_actor *self, t_ft_msg *msg)
{
	t_fork_actor	*fork;

	if (!self || !self->ref || !msg)
		return (true);
	fork = self->ref;
	if (msg->type == REQUEST_FORK)
		_on_request_fork(fork, msg->sender);
	if (msg->type == RELEASE_FORK)
		_on_release_fork(fork, msg->sender);
	if (msg->type == SHUT_DOWN)
		ft_actor_stop(self);
	return (true);
}
