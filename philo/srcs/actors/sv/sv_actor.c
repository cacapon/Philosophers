/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_actor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:42:16 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/17 21:55:18 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "sv_actor.h"

static void	sv_on_start(t_ft_actor *self)
{
	size_t		i;
	t_sv_actor	*sv;

	sv = self->ref;
	i = 0;
	while (i < sv->prop->args.num_of_philos)
	{
		ft_actor_start(sv->prop->philos_ref[i]);
		ft_actor_start(sv->prop->forks_ref[i]);
		sv->prop->ref_count += 2;
		i++;
	}
	ft_actor_start(sv->prop->monitor_ref);
	sv->prop->ref_count++;
}

static void	sv_on_stop(t_ft_actor *self)
{
	(void)self;
}

t_sv_actor	*sv_actor_new(t_main_args args)
{
	t_sv_actor						*sv;
	static const t_ft_actor_vtable	vtable = {
		.on_start = sv_on_start,
		.on_receive = _sv_on_receive,
		.on_stop = sv_on_stop,
	};

	sv = philo_calloc(1, sizeof(t_sv_actor));
	if (!sv)
		return (NULL);
	sv->base = ft_actor_new(sv);
	sv->base->v = &vtable;
	sv->prop = _sv_prop_new(args);
	return (sv);
}
