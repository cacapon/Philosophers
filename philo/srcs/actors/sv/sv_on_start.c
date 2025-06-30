/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_on_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:07:27 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/30 19:35:10 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

void	sv_on_start(t_ft_actor *self)
{
	int			i;
	t_sv_actor	*sv;

	sv = self->ref;
	i = 0;
	while (i < sv->prop->args.num_of_philos)
	{
		ft_actor_start(sv->prop->philos_ref[i]);
		sv->prop->ref_count++;
		i++;
	}
	ft_actor_start(sv->prop->monitor_ref);
	sv->prop->ref_count++;
}
