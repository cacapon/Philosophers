/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _on_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:50:17 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 15:15:51 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

void	_on_update(t_sv_actor *self)
{
	size_t		i;
	t_timeval	now;
	t_ft_actor	*philo_ref;
	t_ft_msg	*msg;

	gettimeofday(&now, NULL);
	i = 0;
	while (i < self->prop->args.num_of_philos)
	{
		msg = msg_new(UPDATE, NULL);
		if (!msg)
			return ;
		msg->data.l = get_delta_ms(&self->prop->last_update_time, &now);
		philo_ref = self->prop->philos_ref[i++];
		philo_ref->tell(philo_ref, msg);
	}
	self->prop->last_update_time = now;
}
