# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/03 17:04:43 by ttsubo            #+#    #+#              #
#    Updated: 2025/06/16 21:16:41 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_actor.a

CC = cc
MAKEFLAGS += --no-print-directory

W_FLG = -Wall -Wextra -Werror

SRCS = ft_actor.c ft_actor_msg.c ft_queue.c ft_actor_calloc.c \
		_ft_actor_tell.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
	@echo -n "$(NAME) has been created!"

$(NAME): $(OBJS)
	@echo -n "Creating $@..."
	@ar rc $@ $^ && echo "✅" || echo "❌"

%.o: %.c
	@echo -n "Creating $@..."
	@$(CC) $(W_FLG) -c $< -o $@ && echo "✅" || echo "❌"

clean:
	@echo -n "Deleting ft_actor objs..."
	@rm -f $(OBJS) && echo "✅" || echo "❌"

fclean:
	@$(MAKE) clean
	@echo -n "Deleting $(NAME)..."
	@rm -f $(NAME) && echo "✅" || echo "❌"

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
