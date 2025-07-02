/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:13:02 by ttsubo            #+#    #+#             */
/*   Updated: 2025/07/02 19:58:31 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

static void	_start_phase(t_system *sys)
{
	t_ft_msg	*sys_msg;

	ft_actor_start(sys->sv->base);
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

static void	_run_phase(t_system *sys)
{
	t_ft_msg	*sys_msg;

	while (true)
	{
		sys_msg = sys->notify_inbox->deq(sys->notify_inbox);
		if (sys_msg && sys_msg->type == SYSTEM_STOP)
		{
			msg_del(&sys_msg);
			break ;
		}
		msg_del(&sys_msg);
	}
}

static void	_shutdown_phase(t_system *sys)
{
	t_ft_msg	*sys_msg;

	sys->sv->base->tell(sys->sv->base, msg_new(SHUT_DOWN, NULL));
	while (true)
	{
		sys_msg = sys->notify_inbox->deq(sys->notify_inbox);
		if (sys_msg && sys_msg->type == ACTOR_STOP_DONE)
		{
			msg_del(&sys_msg);
			break ;
		}
		msg_del(&sys_msg);
	}
	pthread_join(sys->sv->base->thread, NULL);
}

void	system_run(t_system *sys)
{
	_start_phase(sys);
	_run_phase(sys);
	_shutdown_phase(sys);
}
