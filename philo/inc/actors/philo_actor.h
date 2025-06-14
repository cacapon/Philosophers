/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:28:12 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/10 16:05:00 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ACTOR_H
# define PHILO_ACTOR_H

# include "actor.h"

typedef struct s_main_args	t_main_args;

enum			e_philo_sts
{
	PHILO_STS_THINKING,
	PHILO_STS_EATING,
	PHILO_STS_SLEEPING,
	PHILO_STS_WAITING,
	PHILO_STS_DEAD,
};

typedef struct s_philo_actor
{
	t_actor		*base;
	t_actor		*sv;
	t_actor		*l_fork;
	t_actor		*r_fork;
	int			sts;
	size_t		max_hp;
	size_t		now_hp;
	size_t		max_eat;
	size_t		now_eat;
	size_t		max_slp;
	size_t		now_slp;
	int			max_eat_count;
	int			eat_count;
	size_t		no;
	bool		has_l_fork;
	bool		has_r_fork;
	bool		can_eat;
}				t_philo_actor;

t_philo_actor	*philo_actor_new(int id, t_main_args args);
void			free_philo(t_philo_actor **philo_ptr);
void			_common_update(t_philo_actor *self, t_actor *sender);
void			_thinking(t_philo_actor *self);
void			_eating(t_philo_actor *self, t_actor *sender);
void			_sleeping(t_philo_actor *self);
void			_confirm_fork(t_philo_actor *self, t_actor *sender);
void			_on_fork_released(t_philo_actor *self, t_actor *sender);

#endif