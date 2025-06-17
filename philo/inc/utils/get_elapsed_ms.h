/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elapsed_ms.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:45:07 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/17 22:48:00 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_ELAPSED_MS_H
# define GET_ELAPSED_MS_H

# include <sys/time.h>
# include <stddef.h>

long	get_elapsed_ms(struct timeval *start);

#endif