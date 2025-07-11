/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 22:28:18 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "philo_actor.h"

void	philo_actor_del(t_philo_actor **philo_ptr)
{
	t_philo_actor	*philo;

	philo = *philo_ptr;
	if (!philo)
		return ;
	ft_actor_del(&philo->base);
	free(philo);
	*philo_ptr = NULL;
}

t_philo_actor	*philo_actor_new(size_t no, t_main_args args)
{
	t_philo_actor					*philo;
	static const t_ft_actor_vtable	vtable = {
		.on_start = philo_on_start,
		.on_receive = philo_on_receive,
		.on_stop = NULL,
		.update = philo_update,
	};

	philo = philo_calloc(1, sizeof(t_philo_actor));
	if (!philo)
		return (NULL);
	philo->base = ft_actor_new(philo);
	if (!philo->base)
		return (philo_actor_del(&philo), NULL);
	philo->no = no;
	philo->run_update = false;
	philo->base->v = &vtable;
	philo->hp.max = args.time_to_die;
	philo->eat.max = args.time_to_eat;
	philo->slp.max = args.time_to_sleep;
	philo->max_eat_count = args.number_of_times_each_philosopher_must_eat;
	return (philo);
}
