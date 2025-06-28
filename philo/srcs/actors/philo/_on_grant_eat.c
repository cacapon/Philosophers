/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _on_grant_eat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:51:13 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/28 18:02:11 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_actor.h"

static void	_send_request_fork(t_ft_actor *fork, t_ft_actor *philo_ref)
{
	fork->tell(fork, msg_new(REQUEST_FORK, philo_ref));
}

void	_on_grant_eat(t_philo_actor *self)
{
	self->can_eat = true;
	_send_request_fork(self->l_fork, self->base);
	_send_request_fork(self->r_fork, self->base);
}
