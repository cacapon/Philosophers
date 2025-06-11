/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:54:41 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/09 18:44:14 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	free_matrix(t_size_t_matrix **m_ptr)
{
	t_size_t_matrix	*m;

	if (!m_ptr || !*m_ptr)
		return ;
	m = *m_ptr;
	free(m->rows);
	free(m->flat_data);
	free(m);
	*m_ptr = NULL;
}

t_size_t_matrix	*create_matrix(size_t row, size_t col)
{
	size_t			i;
	t_size_t_matrix	*m;

	m = philo_calloc(1, sizeof(t_size_t_matrix));
	if (!m)
		return (NULL);
	m->row = row;
	m->col = col;
	m->flat_data = philo_calloc(row * col, sizeof(size_t));
	m->rows = philo_calloc(row, sizeof(size_t *));
	if (!m->flat_data || !m->rows)
		return (free_matrix(&m), NULL);
	i = 0;
	while (i < row)
	{
		m->rows[i] = &m->flat_data[i * col];
		i++;
	}
	return (m);
}
