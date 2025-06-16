# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/03 17:04:43 by ttsubo            #+#    #+#              #
#    Updated: 2025/06/16 23:05:17 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo

CC = cc
MAKEFLAGS += --no-print-directory

SRCS_DIR		= srcs/
LIBS_DIR		= libs/
INCS_DIR		= inc/
UTILS_DIR 		= $(SRCS_DIR)utils/
ACTORS_DIR		= $(SRCS_DIR)actors/
FORK_DIR		= $(ACTORS_DIR)fork/
PHILO_DIR		= $(ACTORS_DIR)philo/
SV_DIR			= $(ACTORS_DIR)sv/
MONITOR_DIR 	= $(ACTORS_DIR)monitor/
L_FT_ACTOR_DIR	= $(LIBS_DIR)ft_actor/ 

W_FLG = -Wall -Wextra -Werror
I_FLG = -I$(INCS_DIR) \
		-I$(INCS_DIR)utils \
		-I$(INCS_DIR)actors \
		-I$(LIBS_DIR)ft_actor \
		-Itests/unity/src \
		-Itests/inc
L_FLG = -L$(LIBS_DIR)ft_actor -lft_actor

L_FT_ACTOR		= $(L_FT_ACTOR_DIR)ft_actor.a 

UTILS_SRC	= philo_calloc.c matrix.c	philo_atoi.c
SYS_SRC		= system.c
FORK_SRC	= fork_actor.c	_fork_actor_methods.c
PHILO_SRC	= philo_actor.c	_philo_actor_methods1.c	_philo_actor_methods2.c
SV_SRC		= sv_actor.c	sv_del.c \
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
	tests/actors/fork/test_fork_actor.c \
	tests/actors/philo/test_philo_actor.c \
	tests/actors/sv/test_sv_actor.c \
	tests/unity/src/unity.c

TEST_ALL_OUT = tests/test_all.out

all: $(NAME)

$(NAME): $(L_FT_ACTOR)
	$(CC) $(W_FLG) $(I_FLG) srcs/main.c $(SRCS) $(L_FLG) -o $@

$(L_FT_ACTOR):
	@$(MAKE) -C $(L_FT_ACTOR_DIR)

clean:
	@$(MAKE) -C $(L_FT_ACTOR_DIR) clean
	rm -f $(NAME)
	rm -f $(TEST_ALL_OUT)

fclean:
	@$(MAKE) -C $(L_FT_ACTOR_DIR) fclean
	@$(MAKE) clean
	
re:
	@$(MAKE) fclean
	@$(MAKE) all

test: $(SRC) $(TESTS)
	@$(MAKE) -C $(L_FT_ACTOR_DIR) re
	@$(CC) $(W_FLG) $(I_FLG) $(SRCS) $(TESTS) $(L_FLG) -o $(TEST_ALL_OUT)
	./$(TEST_ALL_OUT)

.PHONY: all clean fclean re test
