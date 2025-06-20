/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:04:01 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/20 21:07:13 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define USAGE_STR "usage: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]\n"

# include <stddef.h>
# include <stdio.h>
# include "ft_actor.h"
# include "args.h"
# include "system.h"
# include "philo_utils.h"
# include "philo_msg.h"

#endif