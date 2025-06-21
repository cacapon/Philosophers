/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _on_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:50:17 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/21 17:17:41 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

void	_on_update(t_sv_actor *self)
{
	size_t			i;
	struct timeval	now;
	long			*delta;
	t_ft_actor		*philo_ref;

	gettimeofday(&now, NULL);
	i = 0;
	while (i < self->prop->args.num_of_philos)
	{
		delta = philo_calloc(1, sizeof(long));
		if (!delta)
			return ;
		*delta = get_delta_ms(&self->prop->last_update_time, &now);
		philo_ref = self->prop->philos_ref[i++];
		philo_ref->tell(philo_ref, msg_new(UPDATE, NULL, delta));
	}
	self->prop->last_update_time = now;
}
