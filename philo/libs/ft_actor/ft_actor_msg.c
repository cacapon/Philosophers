/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actor_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:25:38 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/16 21:07:45 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_actor_msg.h"

/**
 * @note pre: args is allocate memory or NULL.
 */
t_ft_msg	*msg_new(int type, t_ft_actor *sender, void *args)
{
	t_ft_msg	*msg;

	msg = ft_actor_calloc(1, sizeof(t_ft_msg));
	if (!msg)
		return (NULL);
	msg->sender = sender;
	msg->type = type;
	msg->args = args;
	return (msg);
}

/**
 * @note pre: msg.args is allocate memory or NULL.
 */
void		msg_del(t_ft_msg **msg)
{
	t_ft_msg	*_msg;

	_msg = *msg;
	if (!_msg->args)
		free(_msg->args);
	free(_msg);
	*msg = NULL;
}
