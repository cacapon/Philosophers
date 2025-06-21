/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _on_actor_stop_done.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:50:17 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/21 17:25:43 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

void	_on_actor_stop_done(t_sv_actor *sv)
{
	sv->prop->ref_count--;
	if (sv->prop->ref_count == 0)
	{
		sv->sys_notify_inbox->enq(sv->sys_notify_inbox,
			msg_new(ACTOR_STOP_DONE, NULL, NULL));
		ft_actor_stop(sv->base);
	}
}
