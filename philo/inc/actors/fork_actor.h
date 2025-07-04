/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_actor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:28:12 by ttsubo            #+#    #+#             */
/*   Updated: 2025/07/04 19:53:51 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_ACTOR_H
# define FORK_ACTOR_H

# include <pthread.h>
# include "philo_msg.h"
# include "philo_utils.h"
# include "ft_actor.h"

typedef enum e_fork_sts
{
	FORK_AVAILABLE,
	FORK_HELD,
}	t_fork_sts;

typedef struct s_fork_actor
{
	t_ft_actor		*base;
	int				sts;
	t_ft_actor		*holder;
	t_ft_queue		*wait;
	pthread_mutex_t	mutex;	
}					t_fork_actor;

t_fork_actor	*fork_actor_new(void);
void			fork_actor_del(t_fork_actor **fork_ptr);
void			fork_on_start(t_ft_actor *self);
bool			fork_on_receive(t_ft_actor *self, t_ft_msg *msg);
void			_on_request_fork(t_fork_actor *fork, t_ft_actor *sender);
void			_on_release_fork(t_fork_actor *fork, t_ft_actor *sender);
// methods
void			_set_fork_sts(t_fork_actor *self, t_fork_sts sts);

#endif