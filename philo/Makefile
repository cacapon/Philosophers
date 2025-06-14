# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/03 17:04:43 by ttsubo            #+#    #+#              #
#    Updated: 2025/06/11 10:56:43 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo

CC = cc
MAKEFLAGS += --no-print-directory

W_FLG = -Wall -Wextra -Werror
I_FLG = -Iinc/ \
		-Iinc/utils \
		-Iinc/actors \
		-Itests/unity/src \
		-Itests/inc \

SRCS_DIR	= srcs/
UTILS_DIR 	= $(SRCS_DIR)utils/
ACTORS_DIR	= $(SRCS_DIR)actors/
FORK_DIR	= $(ACTORS_DIR)fork/
PHILO_DIR	= $(ACTORS_DIR)philo/
SV_DIR		= $(ACTORS_DIR)sv/
MONITOR_DIR = $(ACTORS_DIR)monitor/

UTILS_SRC	= queue.c	philo_calloc.c	message.c	free_actor.c	actor.c \
			  matrix.c	philo_atoi.c
SYS_SRC		= system_create.c system_destroy.c
FORK_SRC	= fork_actor.c	_fork_actor_methods.c
PHILO_SRC	= philo_actor.c	_philo_actor_methods1.c	_philo_actor_methods2.c
SV_SRC		= sv_actor.c	free_sv.c \
			  _create_send_ptn.c	_advance_to_next_phase.c _sv_prop.c
MONITOR_SRC	= monitor_actor.c	

SRCS = 	$(addprefix $(UTILS_DIR), $(UTILS_SRC)) \
		$(addprefix $(ACTORS_DIR), $(SYS_SRC)) \
		$(addprefix $(FORK_DIR), $(FORK_SRC)) \
		$(addprefix $(PHILO_DIR), $(PHILO_SRC)) \
		$(addprefix $(SV_DIR), $(SV_SRC)) \
		$(addprefix $(MONITOR_DIR), $(MONITOR_SRC))

TESTS = \
	tests/test_all.c \
	tests/utils/test_queue.c \
	tests/actors/fork/test_fork_actor.c \
	tests/actors/philo/test_philo_actor.c \
	tests/actors/sv/test_sv_actor.c \
	tests/unity/src/unity.c

TEST_ALL_OUT = tests/test_all.out

all: $(NAME)

$(NAME):
	$(CC) $(W_FLG) $(I_FLG) srcs/main.c $(SRCS) -o $@

clean:
	rm -f $(NAME)
	rm -f $(TEST_ALL_OUT)

fclean:
	@$(MAKE) clean

re:
	@$(MAKE) fclean
	@$(MAKE) all

test: $(SRC) $(TESTS)
	@$(CC) $(W_FLG) $(I_FLG) $(SRCS) $(TESTS) -o $(TEST_ALL_OUT)
	./$(TEST_ALL_OUT)

.PHONY: all clean fclean re test
