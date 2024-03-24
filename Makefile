# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 09:13:01 by vrandria          #+#    #+#              #
#    Updated: 2024/03/24 18:12:54 by vrandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS = main.c utils_pile.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap
CC = gcc

FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: ${NAME}

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $?

$(NAME)	: $(OBJS)  $(LIBFT) $(PRINTF)
	$(CC) $(FLAGS) $(OBJS)  -o $(NAME) $(LIBFT) $(PRINTF) 

clean : 
		-rm -f ${OBJS}
		@$(MAKE) -C $(PRINTF_DIR) clean
		@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		-rm -f ${NAME}
		@$(MAKE) -C $(PRINTF_DIR) fclean
		@$(MAKE) -C $(LIBFT_DIR) fclean

re : fclean all


.PHONY: printf
