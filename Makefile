NAME	= so_long

CC      = gcc

CFLAGS  = -Wall -Wextra -Werror -g
LINKS = -Lmlx -lmlx -lGL -lX11 -lXext

SRCS	= $(wildcard game/*.c) $(wildcard utils/*.c) main.c
LIB	=	mlx/

OBJS    = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LINKS) -o $(NAME)

all: $(NAME)
	make -C $(LIB)

RM      = rm -f

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make clean -C $(LIB)

re: fclean all

.PHONY: all clean fclean re
