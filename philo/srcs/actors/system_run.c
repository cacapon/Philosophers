/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:13:02 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/17 23:21:01 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

static void	_wait_actor_start_done(t_system	*sys)
{
	t_ft_msg	*sys_msg;

	while (true)
	{
		sys_msg = sys->notify_inbox->deq(sys->notify_inbox);
		if (sys_msg && sys_msg->type == ACTOR_START_DONE)
		{
			msg_del(&sys_msg);
			break ;
		}
		msg_del(&sys_msg);
	}
}

static void	_wait_actor_stop_done(t_system *sys)
{
	t_ft_msg	*sys_msg;

	while (true)
	{
		sys->sv->base->tell(sys->sv->base, msg_new(UPDATE, NULL, NULL));
		sys_msg = sys->notify_inbox->deq(sys->notify_inbox);
		if (sys_msg && sys_msg->type == ACTOR_STOP_DONE)
		{
			msg_del(&sys_msg);
			break ;
		}
		msg_del(&sys_msg);
	}
}

void	system_run(t_system *sys)
{
	ft_actor_start(sys->sv->base);
	_wait_actor_start_done(sys);
	_wait_actor_stop_done(sys);
}
