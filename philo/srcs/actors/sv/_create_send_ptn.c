/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _create_send_ptn.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:42:16 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/08 18:42:01 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor.h"

static void	_create_range(size_t *list, size_t st, size_t ed, size_t add)
{
	size_t	list_i;
	size_t	step;

	list_i = 0;
	step = 0;
	while (st + step < ed)
	{
		list[list_i] = (st + step + add) % ed;
		list_i++;
		step += 2;
	}
}

t_size_t_matrix	*_create_send_ptn(size_t n)
{
	size_t			i;
	t_size_t_matrix	*ptns;

	if (n % 2 == 0)
		ptns = create_matrix(2, (n / 2));
	else
		ptns = create_matrix(n, (n / 2));
	if (!ptns)
		return (NULL);
	if (n % 2 == 0)
	{
		_create_range(ptns->rows[0], 0, n, 0);
		_create_range(ptns->rows[1], 1, n, 0);
	}
	else
	{
		i = 0;
		while (i < n)
		{
			_create_range(ptns->rows[i], 1, n, i);
			i++;
		}
	}
	return (ptns);
}
