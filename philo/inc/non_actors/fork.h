/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:28:12 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/30 18:51:19 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

# include <pthread.h>
# include "philo_utils.h"

typedef struct s_fork	t_fork;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	void			(*take)(t_fork *self);
	void			(*put)(t_fork *self);
}					t_fork;

t_fork	*fork_new(void);
void	fork_del(t_fork **fork);

#endif