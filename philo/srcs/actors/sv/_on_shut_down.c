/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _on_shut_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:50:17 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/29 12:59:40 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

void	_on_shut_down(t_sv_actor *self)
{
	int	i;

	i = 0;
	while (i < self->prop->args.num_of_philos)
	{
		ft_actor_stop(self->prop->philos_ref[i]);
		ft_actor_stop(self->prop->forks_ref[i]);
		i++;
	}
	ft_actor_stop(self->prop->monitor_ref);
}
