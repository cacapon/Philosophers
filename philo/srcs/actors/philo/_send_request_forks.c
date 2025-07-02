/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _send_request_forks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:01:48 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/30 16:15:06 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

static void	_send_request_fork(t_ft_actor *fork, t_ft_actor *philo_ref)
{
	fork->tell(fork, msg_new(REQUEST_FORK, philo_ref));
}

void	_send_request_forks(t_philo_actor *self)
{
	if (self->no % 2 == 0)
	{
		_send_request_fork(self->l_fork, self->base);
		_send_request_fork(self->r_fork, self->base);
	}
	else
	{
		_send_request_fork(self->r_fork, self->base);
		_send_request_fork(self->l_fork, self->base);
	}
}
