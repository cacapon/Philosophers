/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:56:11 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/28 22:22:57 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_H
# define FT_QUEUE_H

# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

// Standard library functions used
// pthread.h	-> mutex_*
// stdlib.h 	-> malloc() free()
// unistd.h 	-> usleep()

typedef struct s_ft_node	t_ft_node;
typedef struct s_ft_queue	t_ft_queue;
typedef void				(*t_ft_deleter)(void **);

typedef struct s_ft_node
{
	void		*msg;
	t_ft_node	*next;
}				t_ft_node;

typedef struct s_ft_queue
{
	t_ft_node		*head;
	t_ft_node		*tail;
	pthread_mutex_t	mutex;
	bool			(*enq)(t_ft_queue * self, void *msg);
	void			*(*deq)(t_ft_queue *self);
	t_ft_deleter	del_func;
}					t_ft_queue;

t_ft_queue	*ft_queue_new(t_ft_deleter del_func);
void		ft_queue_del(t_ft_queue **q);

#endif