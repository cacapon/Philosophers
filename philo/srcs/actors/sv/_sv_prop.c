/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _sv_prop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:42:16 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/09 19:27:10 by ttsubo           ###   ########.fr       */
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
	prop->forks_ref = NULL;
	prop->philos_ref = NULL;
	prop->philo_done_count = 0;
	prop->ptn_i = 0;
	prop->timestamp = 0;
	prop->send_ptn = _create_send_ptn(args.num_of_philos);
	if (!prop->send_ptn)
		return (free(prop), NULL);
	return (prop);
}
