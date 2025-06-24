/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_on_receive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:50:17 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 21:14:04 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

bool	sv_on_receive(t_ft_actor *self, t_ft_msg *msg)
{
	t_sv_actor	*sv;

	sv = self->ref;
	if (msg->type == ACTOR_START_DONE)
		_on_actor_start_done(sv, msg);
	if (msg->type == UPDATE)
		_on_update(sv);
	if (msg->type == PHILO_EAT_DONE)
		_on_philo_eat_done(sv);
	if (msg->type == PHILO_FINISHED_EATING)
		_on_philo_finished_eating(sv);
	if (msg->type == PHILO_DEAD)
		_on_philo_dead(sv);
	if (msg->type == ACTOR_STOP_DONE)
		_on_actor_stop_done(sv);
	if (msg->type == SHUT_DOWN)
		_on_shut_down(sv);
	if (msg->type > MONITOR_MSG_START && msg->type < MONITOR_MSG_END)
		_on_monitor_msg(sv, msg);
	return (true);
}
