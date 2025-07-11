/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _on_request_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/07/04 19:55:01 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork_actor.h"

void	_on_request_fork(t_fork_actor *fork, t_ft_actor *sender)
{
	if (fork->holder == sender)
		return ;
	if (fork->sts == FORK_AVAILABLE)
	{
		_set_fork_sts(fork, FORK_HELD);
		fork->holder = sender;
		sender->tell(sender, msg_new(GRANT_FORK, fork->base));
	}
	else
		fork->wait->enq(fork->wait, sender);
}
