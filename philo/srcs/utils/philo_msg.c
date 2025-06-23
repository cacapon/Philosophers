/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:25:38 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/23 14:03:10 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_msg.h"

t_philo_msg	*p_msg_new(int type, t_ft_actor *sender)
{
	t_philo_msg	*msg;

	msg = ft_actor_calloc(1, sizeof(t_philo_msg));
	if (!msg)
		return (NULL);
	msg->base = msg_new(type, sender, NULL);
	return (msg);
}

void	p_msg_del(t_philo_msg **msg)
{
	t_philo_msg	*_msg;

	if (!msg || !*msg)
		return ;
	_msg = *msg;
	msg_del(&_msg->base);
	free(_msg);
	*msg = NULL;
}
