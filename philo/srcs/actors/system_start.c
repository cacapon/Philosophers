/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:27:01 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/12 14:03:29 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

// TODO:UPDATEのメッセージがたまりすぎる可能性がある。間隔調整も検討の余地あり
void	system_start(t_system *sys)
{
	actor_start(sys->sv->base);
	while (!sys->sv->base->is_ready)
		;
	while (sys->sv->base->is_ready)
		sys->sv->base->vtable->tell(sys->sv->base, gen_msg(UPDATE, NULL, NULL));
}
