/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:25:41 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/20 22:37:19 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h" 

void	sv_prop_del(t_sv_prop **prop_ptr)
{
	t_sv_prop	*prop;

	if (!prop_ptr || !*prop_ptr)
		return ;
	prop = *prop_ptr;
	free(prop->philos_ref);
	free(prop->forks_ref);
	free_matrix(&prop->send_ptn);
	free(prop);
	*prop_ptr = NULL;
}

void	sv_actor_del(t_sv_actor **sv_ptr)
{
	t_sv_actor	*sv;

	sv = *sv_ptr;
	if (!sv)
		return ;
	ft_actor_del(&sv->base);
	free_matrix(&sv->prop->send_ptn);
	sv_prop_del(&sv->prop);
	free(sv);
	*sv_ptr = NULL;
}
