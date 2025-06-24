# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/03 17:04:43 by ttsubo            #+#    #+#              #
#    Updated: 2025/06/24 21:32:54 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo

CC = cc
MAKEFLAGS += --no-print-directory

SRCS_DIR		= srcs/
OBJS_DIR		= objs/
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

UTILS_SRC	= philo_calloc.c philo_memset.c matrix.c philo_atoi.c get_elapsed_ms.c
SYS_SRC		= system.c system_run.c
FORK_SRC	= fork_actor.c fork_on_start.c fork_on_receive.c \
			  _on_release_fork.c _on_request_fork.c
PHILO_SRC	= philo_actor.c	philo_on_start.c philo_on_recieve.c philo_update.c \
 			  _philo_set_start.c _common_update.c _confirm_fork.c _eating.c _on_fork_released.c _sleeping.c _thinking.c
SV_SRC		= sv_actor.c sv_on_start.c sv_on_receive.c \
			  _on_actor_start_done.c _on_actor_stop_done.c _on_philo_eat_done.c \
			  _on_philo_dead.c _on_shut_down.c _on_update.c _on_monitor_msg.c _on_philo_finished_eating.c \
			  _create_send_ptn.c _send_grant_eat.c
MONITOR_SRC	= monitor_actor.c monitor_on_start.c monitor_on_receive.c \
			  _show_monitor.c	

SRCS = 	$(addprefix $(SRCS_DIR), main.c) \
		$(addprefix $(UTILS_DIR), $(UTILS_SRC)) \
		$(addprefix $(ACTORS_DIR), $(SYS_SRC)) \
		$(addprefix $(FORK_DIR), $(FORK_SRC)) \
		$(addprefix $(PHILO_DIR), $(PHILO_SRC)) \
		$(addprefix $(SV_DIR), $(SV_SRC)) \
		$(addprefix $(MONITOR_DIR), $(MONITOR_SRC))
OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

TESTS = \
	tests/test_all.c \
	tests/actors/fork/test_fork_actor.c \
	tests/actors/philo/test_philo_actor.c \
	tests/actors/sv/test_sv_actor.c \
	tests/unity/src/unity.c

TEST_ALL_OUT = tests/test_all.out

all: $(NAME)

$(NAME): $(OBJS) | $(L_FT_ACTOR)
	@echo -n "Creating $@..."
	@$(CC) $(W_FLG) $(I_FLG) $(OBJS) $(L_FLG) -o $@ && echo "✅" || echo "❌"
	@echo "$(NAME) has been created!"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	@echo -n "Creating $@..."
	@$(CC) -c $(W_FLG) $(I_FLG) $< -o $@ && echo "✅" || echo "❌"

$(L_FT_ACTOR):
	@$(MAKE) -sC $(L_FT_ACTOR_DIR)

clean:
	@$(MAKE) -sC $(L_FT_ACTOR_DIR) clean
	@echo -n "Deleting $(NAME) objs..."
	@rm -rf $(OBJS_DIR) && echo "✅" || echo "❌"

fclean:
	@$(MAKE) -sC $(L_FT_ACTOR_DIR) fclean
	@$(MAKE) clean
	@echo -n "Deleting $(NAME)..."
	@rm -f $(NAME) && echo "✅" || echo "❌"
	
re:
	@$(MAKE) fclean
	@$(MAKE) all

TEST_SRCS := $(filter-out $(SRCS_DIR)main.c,$(SRCS))
test: $(TEST_SRCS) | $(L_FT_ACTOR)
	@$(CC) $(W_FLG) $(I_FLG) $(TEST_SRCS) $(TESTS) $(L_FLG) -o $(TEST_ALL_OUT)
	./$(TEST_ALL_OUT)
	rm -f $(TEST_ALL_OUT)

.PHONY: all clean fclean re test
