/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actor_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:25:38 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/16 19:57:13 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_actor_msg.h"

t_msg	*gen_msg(int type, t_ft_actor *sender, void *args)
{
	t_msg	*msg;

	msg = ft_actor_calloc(1, sizeof(t_msg));
	if (!msg)
		return (NULL);
	msg->sender = sender;
	msg->type = type;
	msg->args = args;
	return (msg);
}
