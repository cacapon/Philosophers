/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_actor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:11:18 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/17 22:21:22 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor_actor.h"

static void	on_start(t_ft_actor *self)
{
	self->parent->tell(self->parent, msg_new(ACTOR_START_DONE, self, NULL));
}

static bool	on_receive(t_ft_actor *self, t_ft_msg *msg)
{
	if (!self || !msg)
		return (true);
	if (msg->type == MONITOR)
		_show_monitor(msg);
	return (true);
}

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

void	monitor_actor_del(t_monitor_actor **monitor)
{
	t_monitor_actor	*_monitor;

	if (!monitor || !*monitor)
		return ;
	_monitor = *monitor;
	ft_actor_del(&_monitor->base);
	free(_monitor);
	*monitor = NULL;
}

t_monitor_actor	*monitor_actor_new(void)
{
	t_monitor_actor			*monitor;
	const t_ft_actor_vtable	vtable = {
		.on_start = on_start,
		.on_receive = on_receive,
		.on_stop = NULL,
	};

	monitor = philo_calloc(1, sizeof(t_monitor_actor));
	if (!monitor)
		return (NULL);
	monitor->base = ft_actor_new(monitor);
	if (!monitor->base)
		return (monitor_actor_del(&monitor), NULL);
	monitor->base->v = &vtable;
	return (monitor);
}
