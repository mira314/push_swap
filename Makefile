# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 09:13:01 by vrandria          #+#    #+#              #
#    Updated: 2024/04/07 15:15:18 by vrandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS = main.c utils_pile.c utils_pile_2.c \
		ft_swap.c \
		ft_rotate.c ft_push.c ft_reverse_rotate.c  \
		ft_input.c check_errors.c \
		algorithme.c algo3.c find_value.c agorithime_utils.c

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

test:
		./push_swap 62 77 84 79 40 65 53 66 23 46 75 47 85 56 45 90 55 21 58 5 69 99 51 72 9 31 7 71 8 57 50 14 89 80 11 0 61 73 95 15 22 87 39 94 59 67 41 81 29 27 6 48 19 37 76 96 13 83 70 52 33 98 24 86 64 25 97 32 10 82 88 54 3 92 35 36 42 18 49 30 28 78 20 38 34 60 1 74 12 43 68 91 2 44 17 26 100 93 4 16
#		./push_swap "-47045 -7308 -62293 -53446 -38039 -54828 -50219 -88770 -57551 -66705 -32125 74685 53498 96666 16328 -92060 42871 -92855 -27634 63675 -57969 69154 3779 -93734 -7554 4597 -20394 20240 91844 -53366 -79141 -55202 -33584 -41434 -81559 -44534 3738 -31778 -33303 -26723 1517 -38339 -52039 82105 -41674 64289 17134 28286 -1477 89500 -8040 40555 58653 95739 -26090 -48902 -72575 53516 -1573 46358 -99851 19287 18245 -33435 4942 36686 22032 35770 -95092 88729 -90954 -66486 -49611 84097 -84382 -64196 -24526 -40159 -8821 73998 -50660 83139 14552 35082 5966 88462 13269 -39520 41977 -88304 -93163 -30785 -41928 25082 35781 -9897 -38232 84902 -74128 93766"
.PHONY: printf
