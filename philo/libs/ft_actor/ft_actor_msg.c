/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actor_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:25:38 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 15:17:59 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_actor_msg.h"

t_ft_msg	*msg_new(int type, t_ft_actor *sender)
{
	t_ft_msg	*msg;

	msg = ft_actor_calloc(1, sizeof(t_ft_msg));
	if (!msg)
		return (NULL);
	msg->sender = sender;
	msg->type = type;
	return (msg);
}

void	msg_del(t_ft_msg **msg)
{
	t_ft_msg	*_msg;

	if (!msg || !*msg)
		return ;
	_msg = *msg;
	free(_msg);
	*msg = NULL;
}
