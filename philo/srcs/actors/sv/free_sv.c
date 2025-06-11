/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:25:41 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/11 11:00:01 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h" 

void	free_sv_prop(t_sv_prop **prop_ptr)
{
	t_sv_prop	*prop;

	if (!prop_ptr || !*prop_ptr)
		return ;
	prop = *prop_ptr;
	free(prop->philos_ref);
	free_matrix(&prop->send_ptn);
	free(prop);
	*prop_ptr = NULL;
}

void	free_sv(t_sv_actor **sv_ptr)
{
	t_sv_actor	*sv;

	sv = *sv_ptr;
	if (!sv)
		return ;
	free_actor(&sv->base);
	free_matrix(&sv->prop->send_ptn);
	free_sv_prop(&sv->prop);
	free(sv);
	*sv_ptr = NULL;
}
