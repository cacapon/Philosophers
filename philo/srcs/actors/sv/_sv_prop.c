/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _sv_prop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:42:16 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/12 12:53:53 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

t_sv_prop	*_sv_prop_new(t_main_args args)
{
	t_sv_prop	*prop;

	prop = philo_calloc(1, sizeof(t_sv_prop));
	if (!prop)
		return (NULL);
	prop->args = args;
	prop->philos_ref = philo_calloc(args.num_of_philos, sizeof(t_actor *));
	prop->philo_done_count = 0;
	prop->ptn_i = 0;
	prop->timestamp = 0;
	prop->child_ready_count = 0;
	prop->send_ptn = _create_send_ptn(args.num_of_philos);
	if (!prop->send_ptn || !prop->philos_ref)
		return (free_sv_prop(&prop), NULL);
	return (prop);
}
