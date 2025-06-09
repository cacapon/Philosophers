/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:25:41 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/09 19:26:31 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h" 

void	free_sv(t_sv_actor **sv_ptr)
{
	t_sv_actor	*sv;

	sv = *sv_ptr;
	if (!sv)
		return ;
	free_actor(&sv->base);
	free_matrix(&sv->prop->send_ptn);
	free(sv->prop);
	free(sv);
	*sv_ptr = NULL;
}
