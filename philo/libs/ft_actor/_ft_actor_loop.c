/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_actor_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:08:51 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/28 19:36:30 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_actor.h"
#include "ft_actor_msg.h"


typedef enum e_philo_msg_type
{
	E_PHILO_TOP = CUSTOM_MSG_START,
	SYNC_START,
	GRANT_EAT,
	PHILO_EAT_START,
	PHILO_DEAD,
	GRANT_FORK,
	REQUEST_FORK,
	RELEASE_FORK,
	FORK_RELEASED,
	PHILO_FINISHED_EATING,
	MONITOR_MSG_START,
	MONITOR_TAKEN_FORK,
	MONITOR_EATING,
	MONITOR_SLEEPING,
	MONITOR_THINKING,
	MONITOR_DIED,
	MONITOR_MSG_END,
}	t_philo_msg_type;

const char *get_enum_name(int value) {
    switch (value)
	{
		case SYSTEM_STOP: return "SYSTEM_STOP";
		case SHUT_DOWN: return "SHUT_DOWN";
		case ACTOR_START: return "ACTOR_START";
		case ACTOR_STOP: return "ACTOR_STOP";
		case ACTOR_START_DONE: return "ACTOR_START_DONE";
		case ACTOR_STOP_DONE: return "ACTOR_STOP_DONE";
		case SYNC_START: return "SYNC_START";
		case GRANT_EAT: return "GRANT_EAT";
		case PHILO_EAT_START: return "PHILO_EAT_START";
		case PHILO_DEAD: return "PHILO_DEAD";
		case GRANT_FORK: return "GRANT_FORK";
		case REQUEST_FORK: return "REQUEST_FORK";
		case RELEASE_FORK: return "RELEASE_FORK";
		case FORK_RELEASED: return "FORK_RELEASED";
		case PHILO_FINISHED_EATING: return "PHILO_FINISHED_EATING";
		case MONITOR_MSG_START: return "MONITOR_MSG_START";
		case MONITOR_TAKEN_FORK: return "MONITOR_TAKEN_FORK";
		case MONITOR_EATING: return "MONITOR_EATING";
		case MONITOR_SLEEPING: return "MONITOR_SLEEPING";
		case MONITOR_THINKING: return "MONITOR_THINKING";
		case MONITOR_DIED: return "MONITOR_DIED";
		case MONITOR_MSG_END: return "MONITOR_MSG_END";
		default: return "UNNOWN_MSG";
	}
}

static void _take_msg(t_ft_actor *self, t_ft_queue *inbox)
{
	t_ft_msg	*msg;

	msg = inbox->deq(inbox);
	if (!msg)
		return ;
	__builtin_printf("thread[%ld] msg[%s]\n",self->thread, get_enum_name(msg->type));
	self->v->on_receive(self, msg);
	msg_del(&msg);
}

void	*_ft_actor_loop(void *arg)
{
	t_ft_actor	*self;

	self = (t_ft_actor *)arg;
	if (!self || !self->v || !self->v->on_receive)
		return (NULL);
	if (self->v->on_start)
		self->v->on_start(self);
	while (self->is_running)
	{
		ft_usleep(1);
		if (self->v->update)
			self->v->update(self);
		_take_msg(self, self->emergency_inbox);
		_take_msg(self, self->inbox);
	}
	return (NULL);
}
