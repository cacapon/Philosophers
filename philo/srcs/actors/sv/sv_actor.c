/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_actor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:42:16 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/14 15:49:22 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "sv_actor.h"

static void	_child_init_done(t_sv_actor *self)
{
	const size_t	total = (self->prop->args.num_of_philos * 2) + 1;

	self->prop->child_ready_count++;
	if (self->prop->child_ready_count >= total)
	{
		self->base->is_ready = true;
	}
}

static void	_child_stop_done(t_sv_actor *self)
{
	self->prop->child_ready_count--;
	if (self->prop->child_ready_count == 0)
	{
		actor_stop(&self->base);
	}
}

// TODO: PHILO_DEADの実装
// TODO: MONITORの実装
static bool	_sv_on_receive(t_actor *self, t_msg *msg)
{
	t_sv_actor	*sv;

	sv = self->ref;
	if (msg->type == INIT_DONE)
		_child_init_done(sv);
	if (msg->type == STOP_DONE)
		_child_stop_done(sv);
	if (msg->type == PHILO_EAT_DONE)
		_advance_to_next_phase(sv);
	if (msg->type == UPDATE)
		_sv_on_update(sv);
	if (msg->type == MONITOR)
		(void)0;
	if (msg->type == PHILO_DEAD)
		(void)0;
	return (true);
}

static void	_sv_on_stop(t_actor *self)
{
	self->is_ready = false;
}

t_sv_actor	*sv_actor_new(int id, t_main_args args)
{
	t_sv_actor					*sv;
	static const t_actor_vtable	vtable = {
		.on_start = _sv_on_start,
		.on_receive = _sv_on_receive,
		.on_stop = _sv_on_stop,
		.tell = default_tell};

	sv = philo_calloc(1, sizeof(t_sv_actor));
	if (!sv)
		return (NULL);
	sv->base = actor_new(id, sv, &vtable);
	sv->prop = _sv_prop_new(args);
	return (sv);
}
