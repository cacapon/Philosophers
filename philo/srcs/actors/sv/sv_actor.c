/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_actor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:42:16 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/07 13:10:56 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

static void	sv_on_start(t_actor *self)
{
	(void)self;
}

static bool	sv_on_receive(t_actor *self, t_msg *msg)
{
	(void)self;
	(void)msg;
	return (false);
}

static void	sv_on_stop(t_actor *self)
{
	(void)self;
}

t_sv_actor	*sv_actor_new(int id)
{
	t_sv_actor					*sv;
	static const t_actor_vtable	vtable = {
		.on_start = sv_on_start,
		.on_receive = sv_on_receive,
		.on_stop = sv_on_stop,
		.tell = default_tell};

	sv = philo_calloc(1, sizeof(t_sv_actor));
	if (!sv)
		return (NULL);
	sv->base = actor_new(id, sv, &vtable);
	return (sv);
}
