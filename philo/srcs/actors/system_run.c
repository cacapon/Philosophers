/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:13:02 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 14:26:21 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

static void	_start_phase(t_system *sys)
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

static void	_shatdown_phase(t_system *sys)
{
	t_ft_msg	*sys_msg;

	sys->sv->base->tell(sys->sv->base, msg_new(SHUT_DOWN, NULL, NULL));
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
}

void	system_run(t_system *sys)
{
	ft_actor_start(sys->sv->base);
	_start_phase(sys);
	_run_phase(sys);
	_shatdown_phase(sys);
}
