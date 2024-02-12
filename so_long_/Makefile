NAME = so_long

SRC  = so_long.c draw_map.c moves.c positions.c characters.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
