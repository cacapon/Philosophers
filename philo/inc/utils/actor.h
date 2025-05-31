/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actor.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:34:30 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/30 19:34:45 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTOR_H
# define ACTOR_H

# include "queue.h"
# include <pthread.h>

typedef struct s_actor
{
	int		id;
	t_queue	*msg_box;
	void	*ref;
	bool	(*on_recieve)(t_msg * msg);
}			t_actor;

#endif