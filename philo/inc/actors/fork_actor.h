/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_actor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:28:12 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/07 13:13:39 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_ACTOR_H
# define FORK_ACTOR_H

# include "actor.h"

enum			e_fork_sts
{
	FORK_AVAILABLE,
	FORK_HELD,
};

typedef struct s_fork_actor
{
	t_actor		*base;
	int			sts;
	t_actor		*holder;
}				t_fork_actor;

t_fork_actor	*fork_actor_new(int id);
void			free_fork(t_fork_actor **fork_ptr);
void			_on_request_fork(t_fork_actor *fork, t_actor *sender);
void			_on_release_fork(t_fork_actor *fork, t_actor *sender);

#endif