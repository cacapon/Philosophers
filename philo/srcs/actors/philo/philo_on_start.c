/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_on_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/30 16:05:07 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "philo_actor.h"

void	philo_on_start(t_ft_actor *self)
{
	t_philo_actor	*philo;
	t_ft_actor		*parent;

	philo = self->ref;
	parent = self->parent;
	philo->sts = PHILO_STS_THINKING;
	philo->hp.now = philo->hp.max;
	philo->eat.now = 0;
	philo->slp.now = 0;
	philo->eat_count = 0;
	philo->has_r_fork = false;
	philo->has_l_fork = false;
	parent->tell(parent, msg_new(ACTOR_START_DONE, self));
}
