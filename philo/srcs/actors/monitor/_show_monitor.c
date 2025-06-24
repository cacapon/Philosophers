/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _show_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:11:18 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 22:41:57 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor_actor.h"

static const char	*_get_msg(t_ft_msg *msg)
{
	if (msg->type == MONITOR_TAKEN_FORK)
		return (MSG_TAKEN_FORK);
	if (msg->type == MONITOR_EATING)
		return (MSG_EATING);
	if (msg->type == MONITOR_THINKING)
		return (MSG_THINKING);
	if (msg->type == MONITOR_SLEEPING)
		return (MSG_SLEEPING);
	if (msg->type == MONITOR_DIED)
		return (MSG_DIED);
	return ("");
}

void	_show_monitor(t_ft_msg *msg)
{
	t_philo_actor	*philo;
	long			time_ms;
	size_t			no;

	philo = msg->sender->ref;
	time_ms = msg->data.l;
	no = philo->no;
	printf("%08ld %ld %s\n", time_ms, no, _get_msg(msg));
}
