/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:47:33 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/12 14:02:27 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	sys = system_create(args);
	system_start(sys);
	system_destroy(&sys);
	return (0);
}
