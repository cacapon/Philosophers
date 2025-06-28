/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:06:27 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/28 16:15:49 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_USLEEP_H
# define FT_USLEEP_H

// using gettimeofday(), NULL, usleep()
# include <sys/time.h>
# include <stddef.h>
# include <unistd.h>

void	ft_usleep(long ms);

#endif
