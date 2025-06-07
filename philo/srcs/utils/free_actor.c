/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_actor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:04:40 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/07 14:19:59 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actor.h"

void	free_actor(t_actor **actor_ptr)
{
	t_actor	*a;

	a = *actor_ptr;
	if (!a)
		return ;
	queue_destroy(&a->msg_box);
	free(a);
	*actor_ptr = NULL;
}
