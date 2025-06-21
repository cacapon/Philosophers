/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_on_receive.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:11:18 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/21 18:58:19 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor_actor.h"

bool	monitor_on_receive(t_ft_actor *self, t_ft_msg *msg)
{
	if (!self || !msg)
		return (true);
	if (MONITOR_MSG_START < msg->type && msg->type < MONITOR_MSG_END)
		_show_monitor(msg);
	return (true);
}
