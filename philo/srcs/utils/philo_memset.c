/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_memset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:04:40 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/20 21:04:05 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

void	*philo_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	if (!b)
		return (b);
	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
		ptr[i++] = (unsigned char)c;
	return (b);
}
