NAME = so_long

SRC  = so_long.c draw_map.c moves.c positions.c printing.c characters.c player__ennemy.c flood_fill.c free.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
