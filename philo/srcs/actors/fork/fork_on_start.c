/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_on_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 15:15:25 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork_actor.h"

void	fork_on_start(t_ft_actor *self)
{
	t_fork_actor	*fork;

	fork = (t_fork_actor *)self->ref;
	fork->sts = FORK_AVAILABLE;
	fork->holder = NULL;
	self->parent->tell(self->parent, msg_new(ACTOR_START_DONE, self));
}
