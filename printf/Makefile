SRCS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_put_hex.c ft_putptr.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: ${NAME}

%.o: %.c

	$(CC) $(FLAGS) -o $@ -c $?
  
${NAME}:  $(OBJS) 
	ar rcs $(NAME) $(OBJS)
	
clean:
	rm -f ${OBJS}
	
fclean: clean
	rm -f ${NAME}   
	
re:  fclean all
