/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _common_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 22:26:48 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

void	_common_update(t_philo_actor *self, long delta)
{
	if (!self)
		return ;
	self->hp.now -= delta;
	if (self->hp.now <= 0)
	{
		self->sts = PHILO_STS_DEAD;
		self->sv->eg_tell(self->sv, msg_new(MONITOR_DIED, self->base));
		self->sv->tell(self->sv, msg_new(PHILO_DEAD, self->base));
	}
}
