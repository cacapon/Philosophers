/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:58:39 by ttsubo            #+#    #+#             */
/*   Updated: 2025/07/03 11:35:48 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_MSG_H
# define PHILO_MSG_H

# include "ft_actor_msg.h"

typedef enum e_philo_msg_type
{
	E_PHILO_TOP = CUSTOM_MSG_START,
	SYNC_START,
	PHILO_EAT_START,
	PHILO_DEAD,
	GRANT_FORK,
	REQUEST_FORK,
	RELEASE_FORK,
	FORK_RELEASED,
	PHILO_FINISHED_EATING,
	MONITOR_MSG_START,
	MONITOR_TAKEN_FORK,
	MONITOR_EATING,
	MONITOR_SLEEPING,
	MONITOR_THINKING,
	MONITOR_DIED,
	MONITOR_MSG_END,
}	t_philo_msg_type;

#endif