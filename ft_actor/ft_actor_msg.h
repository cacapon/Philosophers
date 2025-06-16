/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actor_msg.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:58:39 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/16 19:56:20 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ACTOR_MSG_H
# define FT_ACTOR_MSG_H

// using NULL
# include <stddef.h>
# include "ft_actor_calloc.h"

typedef struct s_ft_actor	t_ft_actor;

typedef enum e_msg_type
{
	ACTOR_STOP,
	CUSTOM_MSG_START = 1000,
}						t_msg_type;

typedef struct s_msg
{
	t_msg_type	type;
	t_ft_actor	*sender;
	void		*args;
}				t_msg;

t_msg	*gen_msg(int type, t_ft_actor *sender, void *args);

#endif