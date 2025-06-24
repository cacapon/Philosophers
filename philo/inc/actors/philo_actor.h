/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:28:12 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 22:33:15 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ACTOR_H
# define PHILO_ACTOR_H

# include "philo_define.h"
# include "ft_actor.h"
# include "philo_msg.h"

typedef struct s_main_args	t_main_args;

enum			e_philo_sts
{
	PHILO_STS_THINKING,
	PHILO_STS_EATING,
	PHILO_STS_SLEEPING,
	PHILO_STS_WAITING,
	PHILO_STS_DEAD,
};

typedef struct s_philo_bar
{
	long	max;
	long	now;
}			t_philo_bar;

typedef struct s_philo_actor
{
	t_ft_actor	*base;
	t_ft_actor	*sv;
	t_ft_actor	*l_fork;
	t_ft_actor	*r_fork;
	int			sts;
	t_philo_bar	hp;
	t_philo_bar	eat;
	t_philo_bar	slp;
	int			max_eat_count;
	int			eat_count;
	size_t		no;
	bool		has_l_fork;
	bool		has_r_fork;
	bool		can_eat;
	bool		run_update;
	t_timeval	last_update_time;
}				t_philo_actor;

t_philo_actor	*philo_actor_new(size_t no, t_main_args args);
void			philo_actor_del(t_philo_actor **philo_ptr);
void			philo_on_start(t_ft_actor *self);
bool			philo_on_receive(t_ft_actor *self, t_ft_msg *msg);
void			philo_update(t_ft_actor *self);
// methods
void			_philo_sync_start(t_philo_actor *self, t_ft_msg *msg);
void			_common_update(t_philo_actor *self, long delta);
void			_thinking(t_philo_actor *self);
void			_eating(t_philo_actor *self, long delta);
void			_sleeping(t_philo_actor *self, long delta);
void			_confirm_fork(t_philo_actor *self, t_ft_actor *sender);
void			_on_fork_released(t_philo_actor *self, t_ft_actor *sender);

#endif