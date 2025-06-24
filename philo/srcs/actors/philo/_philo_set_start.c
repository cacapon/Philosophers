/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _philo_set_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:22:17 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 21:39:37 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

void	_philo_sync_start(t_philo_actor *self, t_ft_msg *msg)
{
	self->base->start = msg->data.tv;
	self->last_update_time = self->base->start;
	self->run_update = true;
}