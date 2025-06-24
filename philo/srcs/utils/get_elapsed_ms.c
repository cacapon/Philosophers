/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elapsed_ms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:44:20 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 21:21:17 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

long	tvtol(t_timeval *tv)
{
	return (tv->tv_sec * 1000 + tv->tv_usec / 1000);
}

long	get_delta_ms(t_timeval *prev, t_timeval *now)
{
	return (tvtol(now) - tvtol(prev));
}

long	get_elapsed_ms(t_timeval *start)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	return (get_delta_ms(start, &now));
}
