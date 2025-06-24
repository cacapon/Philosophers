/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:59:55 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 21:20:45 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_UTILS_H
# define PHILO_UTILS_H

# include <stdlib.h>
# include <stdint.h>
# include <sys/time.h>
# include <stddef.h>
# include "philo_define.h"

int		philo_atoi(const char *str);
void	*philo_memset(void *b, int c, size_t len);
void	*philo_calloc(size_t count, size_t size);
long	tvtol(t_timeval *tv);
long	get_delta_ms(t_timeval *prev, t_timeval *now);
long	get_elapsed_ms(t_timeval *start);

#endif