/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_actor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:42:16 by ttsubo            #+#    #+#             */
/*   Updated: 2025/07/03 11:44:43 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "sv_actor.h"

static void	_sv_prop_del(t_sv_prop **prop_ptr)
{
	t_sv_prop	*prop;

	if (!prop_ptr || !*prop_ptr)
		return ;
	prop = *prop_ptr;
	free(prop->philos_ref);
	free(prop->forks_ref);
	free(prop);
	*prop_ptr = NULL;
}

static t_sv_prop	*_sv_prop_new(t_main_args args)
{
	t_sv_prop	*prop;

	prop = philo_calloc(1, sizeof(t_sv_prop));
	if (!prop)
		return (NULL);
	prop->args = args;
	prop->philos_ref = philo_calloc(args.num_of_philos, sizeof(t_ft_actor *));
	prop->forks_ref = philo_calloc(args.num_of_philos, sizeof(t_ft_actor *));
	prop->philo_done_count = 0;
	if (!prop->philos_ref)
		_sv_prop_del(&prop);
	return (prop);
}

void	sv_actor_del(t_sv_actor **sv_ptr)
{
	t_sv_actor	*sv;

	sv = *sv_ptr;
	if (!sv)
		return ;
	ft_actor_del(&sv->base);
	_sv_prop_del(&sv->prop);
	free(sv);
	*sv_ptr = NULL;
}

t_sv_actor	*sv_actor_new(t_main_args args)
{
	t_sv_actor						*sv;
	static const t_ft_actor_vtable	vtable = {
		.on_start = sv_on_start,
		.on_receive = sv_on_receive,
		.on_stop = NULL,
	};

	sv = philo_calloc(1, sizeof(t_sv_actor));
	if (!sv)
		return (NULL);
	sv->base = ft_actor_new(sv);
	sv->base->v = &vtable;
	sv->prop = _sv_prop_new(args);
	if (!sv->base || !sv->prop)
		sv_actor_del(&sv);
	return (sv);
}
