NAME = so_long

NAME_BONUS = so_long_bonus

SRC  = mandatory/so_long.c mandatory/draw_map.c mandatory/moves.c mandatory/positions.c mandatory/printing.c mandatory/characters.c mandatory/flood_fill.c \
 mandatory/free.c mandatory/get_next_line/get_next_line.c mandatory/get_next_line/get_next_line_utils.c

SRC_BONUS  = bonus/so_long.c bonus/draw_map.c bonus/moves.c bonus/positions.c bonus/printing.c bonus/characters.c bonus/ft_itoa.c bonus/player__ennemy.c \
bonus/flood_fill.c bonus/free.c bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus : $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

all: $(NAME) bonus

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re: fclean all

.PHONY : bonus
