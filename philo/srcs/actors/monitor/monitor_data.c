/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:06:12 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/21 19:09:10 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor_actor.h"

void	monitor_data_del(t_monitor_data **data)
{
	t_monitor_data	*_data;

	if (!data || !*data)
		return ;
	_data = *data;
	free(_data);
	*data = NULL;
}

t_monitor_data	*monitor_data_new(long timestamp, size_t philo_no, int msg_id)
{
	t_monitor_data	*data;

	data = philo_calloc(1, sizeof(t_monitor_data));
	if (!data)
		return (NULL);
	data->timestamp = timestamp;
	data->philo_no = philo_no;
	data->msg_id = msg_id;
	return (data);
}
