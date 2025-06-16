/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_actor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:42:16 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/16 22:55:00 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "sv_actor.h"

static void	sv_on_start(t_ft_actor *self)
{
	(void)self;
}

static bool	sv_on_receive(t_ft_actor *self, t_ft_msg *msg)
{
	(void)self;
	(void)msg;
	return (false);
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
		.on_receive = sv_on_receive,
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
