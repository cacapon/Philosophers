/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:25:22 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/30 19:57:07 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork.h"

static void	_put_fork(t_fork *self)
{
	pthread_mutex_unlock(&self->mutex);
	__builtin_printf("put fork\n");
}

static void	_take_fork(t_fork *self)
{
	pthread_mutex_lock(&self->mutex);
	__builtin_printf("take fork\n");
}

void	fork_del(t_fork **fork)
{
	t_fork	*_fork;

	if (!fork || !*fork)
		return ;
	_fork = *fork;
	free(_fork);
	*fork = NULL;
}

t_fork	*fork_new(void)
{
	t_fork	*fork;

	fork = philo_calloc(1, sizeof(t_fork));
	if (!fork)
		return (NULL);
	fork->take = _take_fork;
	fork->put = _put_fork;
	return (fork);
}
