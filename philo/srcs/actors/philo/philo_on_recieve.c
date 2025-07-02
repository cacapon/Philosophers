/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_on_recieve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/07/02 19:47:06 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "philo_actor.h"

bool	philo_on_receive(t_ft_actor *self, t_ft_msg *msg)
{
	t_philo_actor	*philo;

	if (!self || !self->ref || !msg)
		return (true);
	philo = (t_philo_actor *)self->ref;
	if (msg->type == SYNC_START)
		_on_sync_start(philo, msg);
	if (msg->type == GRANT_EAT)
		_on_grant_eat(philo);
	if (msg->type == GRANT_FORK)
		_confirm_fork(philo, msg->sender);
	if (msg->type == FORK_RELEASED)
		_on_fork_released(philo, msg->sender);
	if (msg->type == SHUT_DOWN)
		ft_actor_stop(self);
	return (true);
}
