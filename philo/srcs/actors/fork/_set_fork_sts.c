/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _set_fork_sts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:49:24 by ttsubo            #+#    #+#             */
/*   Updated: 2025/07/04 19:58:06 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork_actor.h"

void	_set_fork_sts(t_fork_actor *self, t_fork_sts sts)
{
	pthread_mutex_lock(&self->mutex);
	self->sts = sts;
	pthread_mutex_unlock(&self->mutex);
}
