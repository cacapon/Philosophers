/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_on_recieve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 14:03:16 by ttsubo           ###   ########.fr       */
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
	if (msg->type == GRANT_EAT)
		philo->can_eat = true;
	if (msg->type == GRANT_FORK)
		_confirm_fork(philo, msg->sender);
	if (msg->type == FORK_RELEASED)
		_on_fork_released(philo, msg->sender);
	return (true);
}
