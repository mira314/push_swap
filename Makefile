SRCS = main.c

OBJS = ${SRCS:.C=.o}

NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: ${NAME}

%.o %.c

	$(CC) $(FLAGS) - o $@ -c $?

${NAME}: $(OBJS)
		rcs $(NAME) $(OBJS)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all