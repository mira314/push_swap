# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 09:13:01 by vrandria          #+#    #+#              #
#    Updated: 2024/03/30 16:55:48 by vrandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS = main.c utils_pile.c utils_pile_2.c \
		ft_swap.c \
		ft_rotate.c ft_push.c ft_reverse_rotate.c  \
		ft_input.c check_errors.c \
		algorithme.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap
CC = gcc

FLAGS = -Wall -Wextra -Werror
####################################################
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

####################################################
all: ${NAME}

####################################################
$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR) all --no-print-directory

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all --no-print-directory

####################################################
%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $?

$(NAME)	: $(OBJS)  $(LIBFT) $(PRINTF)
	$(CC) $(FLAGS) $(OBJS)  -o $(NAME) $(LIBFT) $(PRINTF) 

#####################################################
clean : 
		-rm -f ${OBJS}
		@$(MAKE) -C $(PRINTF_DIR) clean --no-print-directory
		@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
		-rm -f ${NAME}
		@$(MAKE) -C $(PRINTF_DIR) fclean --no-print-directory
		@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re : fclean all

test :
	./push_swap "4 1 5 0"
##	"./push_swap" "73 42 96 18 55 37 68 21 84 29 63 10 49 82 6 91 27 53 14 78 35 60 3 46 89 12 67 24 57 39 81 19 75 8 61 32 94 15 70 45 99 50 23 64 1 58 36 79 5 93"

.PHONY: printf
