/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _actor_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:42:27 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/12 13:43:33 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actor.h"

void	set_actor_parent(t_actor *self, void *parent)
{
	self->parent = parent;
}

bool	default_tell(t_actor *self, t_msg *msg)
{
	return (self->msg_box->enqueue(self->msg_box, msg));
}
