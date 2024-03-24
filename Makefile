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


all: ${NAME}

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $?

$(NAME)	: $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean : 
		-rm -f ${OBJS}

fclean: clean
		-rm -f ${NAME}

re : fclean all


.PHONY: printf
