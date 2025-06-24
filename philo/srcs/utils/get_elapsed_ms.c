/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elapsed_ms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:44:20 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 13:49:33 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

long	get_delta_ms(t_timeval *prev, t_timeval *now)
{
	long	sec;
	long	micro_sec;

	sec = now->tv_sec - prev->tv_sec;
	micro_sec = now->tv_usec - prev->tv_usec;
	return (sec * 1000 + micro_sec / 1000);
}

long	get_elapsed_ms(t_timeval *start)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	return (get_delta_ms(start, &now));
}
