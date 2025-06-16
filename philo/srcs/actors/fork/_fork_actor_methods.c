/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _fork_actor_methods.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/16 22:09:20 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork_actor.h"

void	_on_request_fork(t_fork_actor *fork, t_ft_actor *sender)
{
	if (fork->holder == sender)
		return ;
	if (fork->sts == FORK_AVAILABLE)
	{
		fork->sts = FORK_HELD;
		fork->holder = sender;
		sender->tell(sender, msg_new(GRANT_FORK, fork->base, NULL));
	}
}

void	_on_release_fork(t_fork_actor *fork, t_ft_actor *sender)
{
	if (fork->holder != sender)
		return ;
	if (fork->sts == FORK_HELD)
	{
		fork->sts = FORK_AVAILABLE;
		fork->holder = NULL;
		sender->tell(sender, msg_new(FORK_RELEASED, fork->base, NULL));
	}
}
