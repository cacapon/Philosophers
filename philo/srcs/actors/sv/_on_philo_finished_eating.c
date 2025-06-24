/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _on_philo_finished_eating.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 21:56:57 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 15:15:50 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

void	_on_philo_finished_eating(t_sv_actor *self)
{
	t_ft_queue	*notify;

	notify = self->sys_notify_inbox;
	self->prop->philo_finished_eat_count++;
	if (self->prop->philo_finished_eat_count >= self->prop->args.num_of_philos)
	{
		notify->enq(notify, msg_new(SYSTEM_STOP, NULL));
	}
}
