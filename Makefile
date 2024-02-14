NAME = so_long

SRC  = so_long.c draw_map.c moves.c positions.c characters.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) libmlx.a libmlx_Linux.a -Lmlx_linux -L/usr/X11R6/lib -lXext -lX11 -lm -lz -o so_long

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
