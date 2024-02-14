#ifndef SO_LONG_H
	#define SO_LONG_H

#include "minilibx-linux/mlx.h" 
# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"


typedef struct lghlid {
	void	*mlx;
	void	*win;
	char **map;
	int	height;
	int	width;
	int img_h;
	int img_w;
	size_t	x;
	int	y;
	int player_x;
	int player_y;
	void *img;
	int move;
} t_ghlid;


void	ft_get_height_of_line(char *str , t_ghlid *data);
void	ft_line(char *str , t_ghlid *data);
void	ft_draw(t_ghlid *data);
void	ft_gound(t_ghlid *data, int x, int y);
void	ft_green(t_ghlid *data, int x, int y);
void	ft_coins(t_ghlid *data, int x, int y);
void	ft_exit(t_ghlid *data, int x, int y);
void	ft_player(t_ghlid *data, int x, int y);
void	move_player_up(t_ghlid *data);
void	move_player_down(t_ghlid *data);
void	move_player_right(t_ghlid *data);
void	move_player_left(t_ghlid *data);
int	key_hook(int keycode, t_ghlid *data);
int ft_collect_coins(t_ghlid *data);
void ft_position(t_ghlid *data);
int ft_collect_coins(t_ghlid *data);
int key_hook(int keycode, t_ghlid *data);
void ft_position(t_ghlid *data);

#endif
