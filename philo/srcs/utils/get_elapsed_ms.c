/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elapsed_ms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:44:20 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/20 21:05:16 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

long	get_delta_ms(struct timeval *prev, struct timeval *now)
{
	long	sec;
	long	micro_sec;

	sec = now->tv_sec - prev->tv_sec;
	micro_sec = now->tv_usec - prev->tv_usec;
	return (sec * 1000 + micro_sec / 1000);
}

long	get_elapsed_ms(struct timeval *start)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (get_delta_ms(start, &now));
}
