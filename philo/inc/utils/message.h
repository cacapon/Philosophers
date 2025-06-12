/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:58:39 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/12 13:03:16 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
# define MESSAGE_H

// using NULL malloc()
# include <stddef.h>
# include <stdlib.h>

typedef struct s_actor	t_actor;

typedef enum e_msg_type
{
	INIT_DONE,
	GRANT_EAT,
	MONITOR,
	UPDATE,
	PHILO_EAT_DONE,
	PHILO_DEAD,
	GRANT_FORK,
	REQUEST_FORK,
	RELEASE_FORK,
	FORK_RELEASED,
}						t_msg_type;

// TODO: argsの型がきまっていないのでvoid*としています。->actorの内部情報しか渡してない
typedef struct s_msg
{
	t_msg_type			type;
	t_actor				*sender;
	void				*args;
}						t_msg;

t_msg	*gen_msg(t_msg_type type, t_actor *sender, void *args);

#endif