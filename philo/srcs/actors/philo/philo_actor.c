/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/10 16:05:20 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "philo_actor.h"

static void	on_start(t_actor *self)
{
	t_philo_actor	*philo;

	philo = self->ref;
	philo->sts = PHILO_STS_THINKING;
	philo->now_hp = philo->max_hp;
	philo->now_eat = 0;
	philo->now_slp = 0;
	philo->eat_count = 0;
	philo->has_r_fork = false;
	philo->has_l_fork = false;
	philo->can_eat = false;
}

static bool	on_receive(t_actor *self, t_msg *msg)
{
	t_philo_actor	*philo;

	if (!self || !self->ref || !msg)
		return (true);
	philo = (t_philo_actor *)self->ref;
	if (msg->type == UPDATE)
	{
		if (philo->sts == PHILO_STS_DEAD)
			return (true);
		_common_update(philo, msg->sender);
		if (philo->sts == PHILO_STS_THINKING)
			_thinking(philo);
		if (philo->sts == PHILO_STS_EATING)
			_eating(philo, msg->sender);
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

void	free_philo(t_philo_actor **philo_ptr)
{
	t_philo_actor	*philo;

	philo = *philo_ptr;
	if (!philo)
		return ;
	free_actor(&philo->base);
	free(philo);
	*philo_ptr = NULL;
}

t_philo_actor	*philo_actor_new(int id, t_main_args args)
{
	t_philo_actor			*philo;
	const t_actor_vtable	vtable = {
		.on_start = on_start,
		.on_receive = on_receive,
		.on_stop = NULL,
		.tell = default_tell};

	philo = philo_calloc(1, sizeof(t_philo_actor));
	if (!philo)
		return (NULL);
	philo->base = actor_new(id, philo, &vtable);
	if (!philo->base)
		return (free_philo(&philo), NULL);
	philo->max_hp = args.time_to_die;
	philo->max_eat = args.time_to_eat;
	philo->max_slp = args.time_to_sleep;
	philo->max_eat_count = args.number_of_times_each_philosopher_must_eat;
	return (philo);
}
