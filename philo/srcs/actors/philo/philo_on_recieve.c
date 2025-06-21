/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_on_recieve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/21 18:41:13 by ttsubo           ###   ########.fr       */
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
	if (msg->type == UPDATE)
	{
		if (philo->sts == PHILO_STS_DEAD)
			return (true);
		_common_update(philo, msg);
		if (philo->sts == PHILO_STS_THINKING)
			_thinking(philo);
		if (philo->sts == PHILO_STS_EATING)
			_eating(philo);
		if (philo->sts == PHILO_STS_SLEEPING)
			_sleeping(philo);
	}
	if (msg->type == GRANT_EAT)
		philo->can_eat = true;
	if (msg->type == GRANT_FORK)
		_confirm_fork(philo, msg->sender);
	if (msg->type == FORK_RELEASED)
		_on_fork_released(philo, msg->sender);
	return (true);
}
