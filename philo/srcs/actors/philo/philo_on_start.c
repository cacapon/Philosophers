/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_on_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/21 18:40:58 by ttsubo           ###   ########.fr       */
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
	philo->now_hp = philo->max_hp;
	philo->now_eat = 0;
	philo->now_slp = 0;
	philo->eat_count = 0;
	philo->has_r_fork = false;
	philo->has_l_fork = false;
	philo->can_eat = false;
	parent->tell(parent, msg_new(ACTOR_START_DONE, self, NULL));
}
