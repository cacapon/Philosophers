/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:58:39 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/26 19:35:47 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
# define MESSAGE_H

typedef enum e_msg_type
{
	PHILO_READY,
	GRANT_EAT,
	MONITOR,
	UPDATE,
	PHILO_EAT_DONE,
	PHILO_DEAD,
	GRANT_FORK,
	RELEASE_FORK,
	FORK_RELEASED,
}				t_msg_type;

// TODO: senderの型がきまっていないのでvoid*としています。
// TODO: argsの型がきまっていないのでvoid*としています。->actorの内部情報しか渡してない
typedef struct s_msg
{
	t_msg_type	type;
	void		*sender;
	void		*args;
}				t_msg;

#endif