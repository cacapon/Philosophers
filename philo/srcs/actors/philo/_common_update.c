/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _common_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:32:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/22 00:14:56 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

// TODO: UPDATEは必ずlong型のargsを含むメッセージを渡されるのでそれ以外ならerrorにしたい
void	_common_update(t_philo_actor *self, t_ft_msg *msg)
{
	long	delta;

	if (!self || !msg || !msg->args)
		return ;
	delta = *(long *)(msg->args);
	self->now_hp -= delta;
	if (self->now_hp <= 0)
	{
		self->sts = PHILO_STS_DEAD;
		self->sv->eg_tell(self->sv, msg_new(MONITOR_DIED, self->base, NULL));
		self->sv->tell(self->sv, msg_new(PHILO_DEAD, self->base, NULL));
	}
}
