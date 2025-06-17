/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:47:33 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/17 21:37:03 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	system_run(t_system *sys)
{
	t_ft_msg	*sys_msg;

	ft_actor_start(sys->sv->base);
	while (true)
	{
		sys_msg = sys->notify_inbox->deq(sys->notify_inbox);
		if (sys_msg && sys_msg->type == ACTOR_START_DONE)
		{
			msg_del(&sys_msg);
			break;
		}
		msg_del(&sys_msg);
	}
	while (true)
	{
		sys->sv->base->tell(sys->sv->base, gen_msg(UPDATE, NULL, NULL));
		sys_msg = sys->notify_inbox->deq(sys->notify_inbox);
		if (sys_msg && sys_msg->type == ACTOR_STOP_DONE)
			break;
	}
}

int	main(int argc, char **argv)
{
	t_main_args	args;
	t_system	*sys;

	if (!(argc == 5 || argc == 6))
		return (printf("%s", USAGE_STR), 1);
	args.num_of_philos = (size_t)philo_atoi(argv[1]);
	args.time_to_die = (size_t)philo_atoi(argv[2]);
	args.time_to_eat = (size_t)philo_atoi(argv[3]);
	args.time_to_sleep = (size_t)philo_atoi(argv[4]);
	if (argc == 6)
		args.number_of_times_each_philosopher_must_eat = philo_atoi(argv[5]);
	else
		args.number_of_times_each_philosopher_must_eat = -1;
	sys = system_new(args);
	system_run(sys);
	system_del(&sys, args.num_of_philos);
	return (0);
}
