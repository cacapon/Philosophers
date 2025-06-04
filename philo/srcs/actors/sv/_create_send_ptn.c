/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _create_send_ptn.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:42:16 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/04 18:16:56 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sv_actor_utils.h"

static size_t	*_calloc_send_pattern(size_t n)
{
	size_t	*ptn;

	ptn = philo_calloc((n / 2) + 1, sizeof(size_t));
	if (!ptn)
		return (NULL);
	return (ptn);
}

static size_t	**_calloc_send_patterns(size_t n)
{
	size_t	i;
	size_t	size;
	size_t	**ptns;

	if (n % 2 == 0)
		size = 2;
	else
		size = n;
	ptns = philo_calloc(size + 1, sizeof(size_t *));
	if (!ptns)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptns[i] = _calloc_send_pattern(n);
		if (!ptns[i])
			return (free_send_patterns(&ptns), NULL);
	}
	ptns[i] = NULL;
	return (ptns);
}

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
	list[list_i] = -1;
}

void	free_send_patterns(size_t ***ptns_ptr)
{
	size_t	i;
	size_t	**ptns;

	ptns = *ptns_ptr;
	while (ptns[i])
		free(ptns[i++]);
	free(ptns);
	*ptns_ptr = NULL;
}

size_t	**_create_send_ptn(t_sv_actor *self, size_t n)
{
	size_t	i;
	size_t	**ptns;

	ptns = _calloc_send_patterns(n);
	if (!ptns)
		return (NULL);
	if (n % 2 == 0)
	{
		_create_range(ptns[0], 0, n, 0);
		_create_range(ptns[1], 1, n, 0);
	}
	else
	{
		i = 0;
		while (i < n)
		{
			_create_range(ptns[i], 1, n, i);
			i++;
		}
	}
	return (ptns);
}
