/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actor_msg.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:58:39 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/24 21:07:44 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ACTOR_MSG_H
# define FT_ACTOR_MSG_H

// using NULL timeval
# include <sys/time.h>
# include <stddef.h>
# include "ft_actor_calloc.h"

typedef struct s_ft_actor	t_ft_actor;

enum e_msg_type
{
	SYSTEM_STOP,
	SHUT_DOWN,
	ACTOR_START,
	ACTOR_STOP,
	ACTOR_START_DONE,
	ACTOR_STOP_DONE,
	CUSTOM_MSG_START = 1000,
};

typedef union u_ft_msg_data
{
	int				i;
	long			l;
	struct timeval	tv;
}			t_ft_msg_data;

typedef struct s_ft_msg
{
	int				type;
	t_ft_actor		*sender;
	t_ft_msg_data	data;	
}				t_ft_msg;

t_ft_msg	*msg_new(int type, t_ft_actor *sender);
void		msg_del(t_ft_msg **msg);	

#endif