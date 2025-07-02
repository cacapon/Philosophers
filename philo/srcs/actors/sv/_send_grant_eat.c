/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _send_grant_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:34:57 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 15:15:52 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

void	_send_grant_eat(t_sv_actor *self)
{
	size_t		i;
	t_ft_actor	*philo_ref;
	size_t		send_i;

	i = 0;
	while (i < self->prop->send_ptn->col)
	{
		send_i = self->prop->send_ptn->rows[self->prop->ptn_i][i];
		philo_ref = self->prop->philos_ref[send_i];
		philo_ref->tell(philo_ref, msg_new(GRANT_EAT, NULL));
		i++;
	}
}
