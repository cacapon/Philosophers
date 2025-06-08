/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:47:07 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/08 18:26:45 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "philo_calloc.h"
# include "stddef.h"

typedef struct s_size_t_matrix
{
	size_t		**rows;
	size_t		*flat_data;
	size_t		row;
	size_t		col;
}				t_size_t_matrix;

void			free_matrix(t_size_t_matrix **m_ptr);
t_size_t_matrix	*create_matrix(size_t row, size_t col);

#endif