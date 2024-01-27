NAME = so_long

SRC  = so_long.c 

OBJ = $(SRC:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) libmlx.a libmlx_Linux.a -Lmlx_linux -L/usr/X11R6/lib -lXext -lX11 -lm -lz -o so_long

clean:
	rm -rf $(OBJ) so_long

fclean: clean
	rm -rf $(NAME) so_long

re: fclean all