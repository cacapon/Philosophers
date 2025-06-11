/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _sv_prop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:42:16 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/11 10:44:21 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

static void	_free_sv_prop(t_sv_prop **prop_ptr)
{
	t_sv_prop	*prop;

	if (!prop_ptr || !*prop_ptr)
		return ;
	prop = *prop_ptr;
	free(prop->philos_ref);
	free_matrix(&prop->send_ptn);
	free(prop);
	*prop_ptr = NULL;
}

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
	prop->send_ptn = _create_send_ptn(args.num_of_philos);
	if (!prop->send_ptn || !prop->philos_ref)
		return (_free_sv_prop(&prop), NULL);
	return (prop);
}
