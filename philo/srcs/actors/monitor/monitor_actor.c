/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_actor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:11:18 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/10 16:38:06 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor_actor.h"

static bool	on_receive(t_actor *self, t_msg *msg)
{
	if (!self || !self->ref || !msg)
		return (true);
	if (msg->type == MONITOR)
		_show_monitor(msg);
	return (true);
}

void	_show_monitor(t_msg *msg)
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

void	free_monitor(t_monitor_actor **monitor_ptr)
{
	t_monitor_actor	*monitor;

	monitor = *monitor_ptr;
	if (!monitor)
		return ;
	free_actor(&monitor->base);
	free(monitor);
	*monitor_ptr = NULL;
}

t_monitor_actor	*monitor_actor_new(int id)
{
	t_monitor_actor			*monitor;
	const t_actor_vtable	vtable = {
		.on_start = NULL,
		.on_receive = on_receive,
		.on_stop = NULL,
		.tell = default_tell};

	monitor = philo_calloc(1, sizeof(t_monitor_actor));
	if (!monitor)
		return (NULL);
	monitor->base = actor_new(id, monitor, &vtable);
	if (!monitor->base)
		return (free_monitor(&monitor), NULL);
	return (monitor);
}
