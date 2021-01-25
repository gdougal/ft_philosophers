# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdougal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 19:45:38 by gdougal           #+#    #+#              #
#    Updated: 2021/01/24 19:45:39 by gdougal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            =	philo_one

CC              =	gcc

VPATH 			=	./srcs/:./srcs/utils/

SRCS			=	forks_take_and_drop.c \
					ft_puthbr_light.c \
					change_status.c \
					start_status.c \
					thread_start.c \
					wrap_writing.c \
					current_time.c \
					philo_print.c \
					clear_space.c \
					dead_status.c \
					true_usleep.c \
					init_philo.c \
					wrap_chngs.c \
					life_check.c \
					philo_life.c \
					print_dead.c \
					time_start.c \
					main_philo.c \
					philo_pars.c \
					lifecycle.c \
					after_eat.c \
					ft_atoi.c

HEADERS_DIR		=	./srcs/includes/

HEAD		=	$(addprefix $(HEADERS_DIR), philo_one.h)

INCLUDES        =   -I$(HEADERS_DIR)

FLAGS           =   $(INCLUDES) -Wall -Wextra -Werror -O2

OBJ_DIR         =   ./obj/

O_FILE          =   $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

.PHONY: all

all: $(NAME)

$(NAME): $(OBJ_DIR) $(O_FILE)
	$(CC) $(FLAGS) $(O_FILE) -o $(NAME)

$(O_FILE): $(OBJ_DIR)%.o: %.c $(HEAD)
	$(CC) -c $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

.PHONY: clean

clean:
	@rm -f $(O_FILE)
	@rm -f $(D_FILE)
	@rm -rf $(OBJ_DIR)

PHONY: fclean

fclean: clean
	@rm -f $(NAME)

.PHONY: re

re:     fclean all
