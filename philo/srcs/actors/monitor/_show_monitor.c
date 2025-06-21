/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _show_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:11:18 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/21 18:44:33 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor_actor.h"

void	_show_monitor(t_ft_msg *msg)
{
	t_monitor_data	*data;
	const char		*msg_str[] = {
		MSG_TAKEN_FORK, MSG_EATING, MSG_SLEEPING, MSG_DIED};

	data = (t_monitor_data *)msg->args;
	if (!data)
		return ;
	if (0 <= data->msg_id && data->msg_id < 4)
		printf("%ld %d %s\n", data->timestamp, data->philo_no,
			msg_str[data->philo_no]);
}
