/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _on_sync_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:22:17 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/30 15:56:59 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"
#include "ft_usleep.h"

void	_on_sync_start(t_philo_actor *self, t_ft_msg *msg)
{
	self->base->start = msg->data.tv;
	self->last_update_time = self->base->start;
	self->run_update = true;
	if (self->no % 2 == 0)
		ft_usleep(1);
}
