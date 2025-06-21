/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_calloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:04:40 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/20 21:04:17 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

void	*philo_calloc(size_t count, size_t size)
{
	void	*_block;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (size > SIZE_MAX / count)
		return (NULL);
	_block = malloc(count * size);
	if (!_block)
		return (NULL);
	philo_memset(_block, 0, count * size);
	return (_block);
}
