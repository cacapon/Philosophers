/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_on_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:42:47 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/14 15:44:26 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

// TODO: timestampの更新をここで行う。
void	_sv_on_update(t_sv_actor *self)
{
	size_t	i;
	t_actor	*ref;

	i = 0;
	while (i < self->prop->args.num_of_philos)
	{
		ref = self->prop->philos_ref[i++];
		ref->vtable->tell(ref, gen_msg(UPDATE, NULL, NULL));
	}
}
