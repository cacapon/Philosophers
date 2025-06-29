/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:47:33 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/29 13:15:26 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	_print_args_err(t_main_args args)
{
	int	must_eat;

	must_eat = args.number_of_times_each_philosopher_must_eat;
	printf("%s", ARGS_ERR_STR);
	printf("args:\n");
	printf("\tnumber_of_philosophers:%d\n", args.num_of_philos);
	printf("\ttime_to_die:%d\n", args.time_to_die);
	printf("\ttime_to_eat:%d\n", args.time_to_eat);
	printf("\ttime_to_sleep:%d\n", args.time_to_sleep);
	printf("\tnumber_of_times_each_philosopher_must_eat:%d\n", must_eat);
}

int	main(int argc, char **argv)
{
	t_main_args	args;
	t_system	*sys;

	if (!(argc == 5 || argc == 6))
		return (printf("%s", USAGE_STR), 1);
	args.num_of_philos = (int)philo_atoi(argv[1]);
	args.time_to_die = (int)philo_atoi(argv[2]);
	args.time_to_eat = (int)philo_atoi(argv[3]);
	args.time_to_sleep = (int)philo_atoi(argv[4]);
	if (argc == 6)
		args.number_of_times_each_philosopher_must_eat = philo_atoi(argv[5]);
	else
		args.number_of_times_each_philosopher_must_eat = -1;
	if (args.num_of_philos <= 0
		|| args.time_to_die <= 0
		|| args.time_to_eat <= 0
		|| args.time_to_sleep <= 0)
		return (_print_args_err(args), 1);
	sys = system_new(args);
	system_run(sys);
	system_del(&sys, args.num_of_philos);
	return (0);
}
