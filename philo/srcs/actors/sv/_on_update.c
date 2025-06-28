/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _on_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:50:17 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/28 16:58:15 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

void	_on_update(t_sv_actor *self)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	self->prop->last_update_time = now;
}
