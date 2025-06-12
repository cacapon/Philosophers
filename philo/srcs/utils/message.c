/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:25:38 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/12 13:35:29 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message.h"

t_msg	*gen_msg(t_msg_type type, t_actor *sender, void *args)
{
	t_msg	*msg;

	msg = philo_calloc(1, sizeof(t_msg));
	if (!msg)
		return (NULL);
	msg->sender = sender;
	msg->type = type;
	msg->args = args;
	return (msg);
}

void	free_msg(t_msg **msg_ptr)
{
	t_msg	*msg;

	msg = *msg_ptr;
	free(msg);
	*msg_ptr = NULL;
}
