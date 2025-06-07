# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/03 17:04:43 by ttsubo            #+#    #+#              #
#    Updated: 2025/06/07 12:36:30 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo

CC = cc

W_FLG = -Wall -Wextra -Werror
I_FLG = -Iinc/utils -Itests/unity/src -Itests/inc

SRC = srcs/utils/queue.c

TESTS = \
	tests/test_all.c \
	tests/utils/test_queue.c \
	tests/unity/src/unity.c

TEST_ALL_OUT = tests/test_all.out

all: $(NAME)

$(NAME):
	@echo "TODO"

clean:
	rm -f $(TEST_ALL_OUT)

fclean:
	$(MAKE) clean

re:
	$(MAKE) fclean
	$(MAKE) all

test: $(SRC) $(TESTS)
	@$(CC) $(W_FLG) $(I_FLG) $(SRC) $(TESTS) -o $(TEST_ALL_OUT)
	./$(TEST_ALL_OUT)

.PHONY: all clean fclean re test
