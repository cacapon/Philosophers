/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:25:38 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/31 16:27:03 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message.h"

t_msg	*gen_msg(t_msg_type type, t_actor *sender, void *args)
{
	t_msg	*msg;

	msg = malloc(sizeof(t_msg));
	if (!msg)
		return (NULL);
	msg->sender = sender;
	msg->type = type;
	msg->args = args;
	return (msg);
}
