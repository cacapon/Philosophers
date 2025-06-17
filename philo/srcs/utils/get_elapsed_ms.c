/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elapsed_ms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:44:20 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/17 23:05:13 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_elapsed_ms.h"

long	get_elapsed_ms(struct timeval *start)
{
	struct timeval	now;
	long			sec;
	long			micro_sec;

	gettimeofday(&now, NULL);
	sec = now.tv_sec - start->tv_sec;
	micro_sec = now.tv_usec - start->tv_usec;
	return (sec * 1000 + micro_sec / 1000);
}
