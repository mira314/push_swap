# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 09:13:01 by vrandria          #+#    #+#              #
#    Updated: 2024/04/12 09:57:44 by vrandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS = main.c utils_pile.c utils_pile_2.c \
		ft_swap.c \
		ft_rotate.c ft_push.c ft_reverse_rotate.c  \
		ft_input.c check_errors.c check_errors_utils.c\
		algorithme.c algo3.c find_value.c agorithime_utils.c \
		split.c

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

TESTEUR = "62 77 84 79 40 65 53 66 23 46 75 47 85 56 45 -90 55 21 58 5 69 99 51 72 9 31 7 71 8 57 50 14 89 80 11 0 61 73 95 15 22 87 39 94 59 67 41 81 29 27 6 48 19 37 76 96 13 83 70 52 33 98 24 86 64 25 97 32 10 82 88 54 3 92 35 36 42 18 49 30 28 78 20 38 34 60 1 74 12 43 68 91 2 44 17 26 100 93 4 16"

test:
		ARG=$(TESTEUR); ./push_swap $$ARG | ./checker $$ARG
#		ARG=$(TESTEUR); ./push_swap $$ARG | wc -l
#		ARG=$(TESTEUR); valgrind ./push_swap $$ARG
.PHONY: printf
