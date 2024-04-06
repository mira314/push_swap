# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 09:13:01 by vrandria          #+#    #+#              #
#    Updated: 2024/04/06 07:58:35 by vrandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS = main.c utils_pile.c utils_pile_2.c \
		ft_swap.c \
		ft_rotate.c ft_push.c ft_reverse_rotate.c  \
		ft_input.c check_errors.c \
		algorithme.c algo3.c find_value.c

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
#	./push_swap "5 1 2 8 0 4 7 3 6 9 5"
	./push_swap "73 1 74 2 9 18 42 26 44 0 -1 21 84 -28 29 63 10 49 82"
#	./push_swap 0 53 14 78 35 60 3 46 89 12 67 70 45 99 50 23 1 58 36 79 5 93 18
#	./push_swap "73 96 18 55 37 68 21 84 29 63 10 49 82 6 91 27 42 53 14 78 35 60 3 46 89 12 67 24 57 39 81 19 75 8 61 32 94 15 70 45 99 50 23 64 1 58 36 79 5 93"
#	./push_swap "64 47 6 28 21 30 74 99 76 61 72 50 87 71 20 43 45 53 17 97 38 70 46 98 79 86 52 41 78 24 63 25 27 35 82 88 40 33 10 39 49 31 22 60 81 92 16 19 15 55 56 65 26 75 91 23 68 77 89 62 95 80 42 29 66 69 54 83 73 8 11 9 96 13 44 48 93 2 3 94 51 57 90 18 12 85 37 5 59 67 7 84 36 32 14 58 34 4 100 1 -1"
.PHONY: printf
