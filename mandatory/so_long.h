/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramt <abouramt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:54:00 by abouramt          #+#    #+#             */
/*   Updated: 2024/04/18 11:33:52 by abouramt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"

typedef struct lghlid
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_chec;
	int		height;
	int		width;
	int		img_h;
	int		img_w;
	size_t	x;
	int		y;
	int		player_x;
	int		player_y;
	void	*img;
	void	*img_d;
	void	*img_c;
	void	*img_g;
	void	*img_p;
	int		move;
	int		if_player;
	int		nb_exit;
	int		nb_player;
	int		nb_kurama;
}	t_ghlid;

void	ft_get_height_of_line(char *str, t_ghlid *data);
void	ft_line(char *str, t_ghlid *data);
int		ft_draw(t_ghlid *data);
void	ft_gound(t_ghlid *data, int x, int y);
void	ft_green(t_ghlid *data, int x, int y);
void	ft_coins(t_ghlid *data, int x, int y);
void	ft_door(t_ghlid *data, int x, int y);
void	ft_player(t_ghlid *data, int x, int y);
void	move_player_up(t_ghlid *data);
void	move_player_down(t_ghlid *data);
void	move_player_right(t_ghlid *data);
void	move_player_left(t_ghlid *data);
void	flood_fill_e(t_ghlid *data);
void	ft_map_valid(t_ghlid *data);
int		key_hook(int keycode, t_ghlid *data);
int		ft_collect_coins(t_ghlid *data);
void	ft_position(t_ghlid *data);
int		ft_is_door(t_ghlid *data);
void	ft_exit_(t_ghlid *data);
void	ft_free_map(t_ghlid *data);
void	ft_free_map_chec(t_ghlid *data);
void	ft_chec_characters(t_ghlid *data);
void	ft_chec_nb(t_ghlid *data);
void	ft_putstr(char *str);
void	put_nbr(int nbr);
void	ft_valid_map(t_ghlid *data, char *av);
void	ft_check_map_botop(t_ghlid *data);
void	ft_check_sides(t_ghlid *data);
int		ft_strcmp(char *ptr1, char *ptr2);
void	check_path(char *av);
int		key_close(t_ghlid *data);

#endif
