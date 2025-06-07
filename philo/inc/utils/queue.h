/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:56:11 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/07 13:13:17 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "message.h"
# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

// Standard library functions used
// stdlib.h -> malloc()
// unistd.h -> usleep()

typedef struct s_node	t_node;
typedef struct s_queue	t_queue;

typedef struct s_node
{
	t_msg				*msg;
	struct s_node		*next;
}						t_node;

typedef struct s_queue
{
	t_node				*head;
	t_node				*tail;
	pthread_mutex_t		mutex;
	bool				(*enqueue)(t_queue * self, t_msg * msg);
	t_msg				*(*dequeue)(t_queue *self);
}						t_queue;

t_queue					*queue_new(void);
void					queue_clear(t_queue **q);

#endif