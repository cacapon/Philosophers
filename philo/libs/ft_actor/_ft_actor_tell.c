/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_actor_tell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:08:51 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/22 00:13:52 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_actor.h"

bool	_ft_actor_eg_tell(t_ft_actor *self, t_ft_msg *msg)
{
	return (self->emergency_inbox->enq(self->emergency_inbox, msg));
}

bool	_ft_actor_tell(t_ft_actor *self, t_ft_msg *msg)
{
	return (self->inbox->enq(self->inbox, msg));
}
