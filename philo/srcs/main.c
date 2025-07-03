/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:47:33 by ttsubo            #+#    #+#             */
/*   Updated: 2025/07/03 12:56:57 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	_print_err(int argc, char **argv)
{
	printf("%s", USAGE_STR);
	printf("Error: invalid argument\n");
	printf("\t%s:%s\n", ERR_STR1, argv[1]);
	printf("\t%s:%s\n", ERR_STR2, argv[2]);
	printf("\t%s:%s\n", ERR_STR3, argv[3]);
	printf("\t%s:%s\n", ERR_STR4, argv[4]);
	if (argc == 6)
		printf("\t%s:%s\n", ERR_STR5, argv[5]);
}

static bool	_isnum(char *str)
{
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (false);
		str++;
	}
	return (true);
}

static bool	_in_range(int val, int min, int max)
{
	if (min > max)
		return (false);
	return (min <= val && val <= max);
}

static bool	_validate_args(int ac, char **av)
{
	if (!(ac == 5 || ac == 6))
		return (false);
	if (!_isnum(av[1]) || !_in_range(philo_atoi(av[1]), 1, 200))
		return (false);
	if (!_isnum(av[2]) || !_in_range(philo_atoi(av[2]), 1, INT_MAX))
		return (false);
	if (!_isnum(av[3]) || !_in_range(philo_atoi(av[3]), 1, INT_MAX))
		return (false);
	if (!_isnum(av[4]) || !_in_range(philo_atoi(av[4]), 1, INT_MAX))
		return (false);
	if (ac == 6)
		if (!_isnum(av[5]) || !_in_range(philo_atoi(av[5]), 1, INT_MAX))
			return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_main_args	args;
	t_system	*sys;

	if (!_validate_args(argc, argv))
		return (_print_err(argc, argv), 1);
	args.num_of_philos = (int)philo_atoi(argv[1]);
	args.time_to_die = (int)philo_atoi(argv[2]);
	args.time_to_eat = (int)philo_atoi(argv[3]);
	args.time_to_sleep = (int)philo_atoi(argv[4]);
	if (argc == 6)
		args.number_of_times_each_philosopher_must_eat = philo_atoi(argv[5]);
	else
		args.number_of_times_each_philosopher_must_eat = -1;
	sys = system_new(args);
	system_run(sys);
	system_del(&sys, args.num_of_philos);
	return (0);
}
