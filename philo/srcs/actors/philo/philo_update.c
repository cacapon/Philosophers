/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:15:49 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 21:40:07 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"
#include "philo_utils.h"

static long	_get_philo_delta(t_philo_actor *philo)
{
	t_timeval	now;
	long		delta;

	gettimeofday(&now, NULL);
	delta = get_delta_ms(&philo->last_update_time, &now);
	philo->last_update_time = now;
	return (delta);
}

void	philo_update(t_ft_actor *self)
{
	t_philo_actor	*philo;
	long			delta;

	philo = self->ref;
	if (!philo->run_update || philo->sts == PHILO_STS_DEAD)
		return ;
	delta = _get_philo_delta(philo);
	_common_update(philo, delta);
	if (philo->sts == PHILO_STS_THINKING)
		_thinking(philo);
	if (philo->sts == PHILO_STS_EATING)
		_eating(philo, delta);
	if (philo->sts == PHILO_STS_SLEEPING)
		_sleeping(philo, delta);
}
