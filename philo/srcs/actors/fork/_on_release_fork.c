/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _on_release_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/28 17:59:51 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork_actor.h"

void	_on_release_fork(t_fork_actor *fork, t_ft_actor *sender)
{
	if (fork->holder != sender)
		return ;
	if (fork->sts == FORK_HELD)
	{
		fork->sts = FORK_AVAILABLE;
		fork->holder = NULL;
		sender->tell(sender, msg_new(FORK_RELEASED, fork->base));
	}
	if (fork->sts == FORK_AVAILABLE && fork->wait->head)
	{
		fork->sts = FORK_HELD;
		fork->holder = fork->wait->deq(fork->wait);
		fork->holder->tell(fork->holder, msg_new(GRANT_FORK, fork->base));
	}
}
