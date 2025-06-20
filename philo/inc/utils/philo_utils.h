/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:59:55 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/20 21:06:13 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_UTILS_H
# define PHILO_UTILS_H

# include <stdlib.h>
# include <stdint.h>
# include <sys/time.h>
# include <stddef.h>

int		philo_atoi(const char *str);
void	*philo_memset(void *b, int c, size_t len);
void	*philo_calloc(size_t count, size_t size);
long	get_delta_ms(struct timeval *prev, struct timeval *now);
long	get_elapsed_ms(struct timeval *start);

#endif