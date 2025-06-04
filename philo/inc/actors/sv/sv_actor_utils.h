/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_actor_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:18:01 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/04 18:17:08 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SV_ACTOR_UTILS_H
# define SV_ACTOR_UTILS_H

# include "philo_calloc.h"
# include <stddef.h>
# include <stdint.h>

typedef struct s_sv_actor	t_sv_actor;

size_t						**_create_send_ptn(t_sv_actor *self, size_t n);

#endif