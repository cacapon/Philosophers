/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _common_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 14:02:35 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

void	_common_update(t_philo_actor *self, long delta)
{
	if (!self)
		return ;
	self->now_hp -= delta;
	if (self->now_hp <= 0)
	{
		self->sts = PHILO_STS_DEAD;
		self->sv->eg_tell(self->sv, msg_new(MONITOR_DIED, self->base, NULL));
		self->sv->tell(self->sv, msg_new(PHILO_DEAD, self->base, NULL));
	}
}
