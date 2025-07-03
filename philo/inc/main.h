/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:04:01 by ttsubo            #+#    #+#             */
/*   Updated: 2025/07/03 12:56:24 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define USAGE_STR "usage: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]\n"
# define ERR_STR1 "numbernumber_of_philosophers\t\t\t[1 <= x <= 200    ]"
# define ERR_STR2 "time_to_die\t\t\t\t\t[1 <= x <= INT_MAX]"
# define ERR_STR3 "time_to_eat\t\t\t\t\t[1 <= x <= INT_MAX]"
# define ERR_STR4 "time_to_sleep\t\t\t\t\t[1 <= x <= INT_MAX]"
# define ERR_STR5 "number_of_times_each_philosopher_must_eat\t\
[1 <= x <= INT_MAX]"

# include <stddef.h>
# include <stdio.h>
# include <limits.h>
# include "ft_actor.h"
# include "args.h"
# include "system.h"
# include "philo_utils.h"
# include "philo_msg.h"

#endif