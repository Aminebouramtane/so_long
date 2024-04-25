/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player__ennemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramt <abouramt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:48:33 by abouramt          #+#    #+#             */
/*   Updated: 2024/04/19 09:34:12 by abouramt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player(t_ghlid *data, int x, int y)
{
	data->img_g = mlx_xpm_file_to_image(data->mlx, \
	"./bonus/textures/ground_2.xpm", &data->img_h, &data->img_w);
	if (data->if_player == 1 && ft_collect_coins(data) == 1)
		data->img_p = mlx_xpm_file_to_image(data->mlx, \
		"./bonus/textures/right.xpm", &data->img_h, &data->img_w);
	else if (data->if_player == 0 && ft_collect_coins(data) == 1)
		data->img_p = mlx_xpm_file_to_image(data->mlx, \
		"./bonus/textures/left.xpm", &data->img_h, &data->img_w);
	else if (data->if_player == 1)
		data->img_p = mlx_xpm_file_to_image(data->mlx, \
	"./bonus/textures/naruto_right.xpm", &data->img_h, &data->img_w);
	else if (data->if_player == 0)
		data->img_p = mlx_xpm_file_to_image(data->mlx, \
	"./bonus/textures/naruto_left.xpm", &data->img_h, &data->img_w);
	mlx_put_image_to_window(data->mlx, data->win, data->img_g, x * 50, y * 50);
	mlx_put_image_to_window(data->mlx, data->win, data->img_p, x * 50, y * 50);
	mlx_destroy_image(data->mlx, data->img_g);
	mlx_destroy_image(data->mlx, data->img_p);
}

static	void	ft_put(t_ghlid *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img_g, x * 50, y * 50);
	mlx_put_image_to_window(data->mlx, data->win, data->img_e, x * 50, y * 50);
	mlx_destroy_image(data->mlx, data->img_g);
	mlx_destroy_image(data->mlx, data->img_e);
}

static	void	fn_enemy_move_right(t_ghlid *data)
{
	if (data->map[data->enemy_y][data->enemy_x + 1] != '1'
	&& data->map[data->enemy_y][data->enemy_x + 1] != 'E'
	&& data->map[data->enemy_y][data->enemy_x + 1] != 'C'
	&& data->frame == 35 && data->a == 1)
	{
		data->map[data->enemy_y][data->enemy_x] = '0';
		data->enemy_x++;
		if (data->map[data->enemy_y][data->enemy_x] == 'P')
		{
			ft_putstr("Game Over !!");
			exit(0);
		}
		data->map[data->enemy_y][data->enemy_x] = 'X';
	}
}

static	void	fn_enemy_move_left(t_ghlid *data)
{
	if (data->map[data->enemy_y][data->enemy_x - 1] != '1'
	&& data->map[data->enemy_y][data->enemy_x - 1] != 'E'
	&& data->map[data->enemy_y][data->enemy_x - 1] != 'C'
	&& data->frame == 35 && data->a == 0)
	{
		data->map[data->enemy_y][data->enemy_x] = '0';
		data->enemy_x--;
		if (data->map[data->enemy_y][data->enemy_x] == 'P')
		{
			ft_putstr("Game Over !!");
			exit(0);
		}
		data->map[data->enemy_y][data->enemy_x] = 'X';
		if ((data->map[data->enemy_y][data->enemy_x - 1] == '1'
			|| data->map[data->enemy_y][data->enemy_x - 1] == 'E'
			|| data->map[data->enemy_y][data->enemy_x - 1] == 'C')
			&& data->frame == 35 && data->a == 0)
			data->a = 1;
	}
	else if ((data->map[data->enemy_y][data->enemy_x + 1] == '1'
		|| data->map[data->enemy_y][data->enemy_x + 1] == 'E'
		|| data->map[data->enemy_y][data->enemy_x + 1] == 'C')
		&& data->frame == 35 && data->a == 1)
		data->a = 0;
}

void	ft_ennemy(t_ghlid *data, int x, int y)
{
	fn_enemy_move_right(data);
	fn_enemy_move_left(data);
	data->img_g = mlx_xpm_file_to_image(data->mlx, \
	"./bonus/textures/ground_2.xpm", &data->img_h, &data->img_w);
	if (data->frame < 5)
		data->img_e = mlx_xpm_file_to_image(data->mlx, \
		"./bonus/textures/itachi/1.xpm", &data->img_h, &data->img_w);
	else if (data->frame < 15)
		data->img_e = mlx_xpm_file_to_image(data->mlx, \
		"./bonus/textures/itachi/3.xpm", &data->img_h, &data->img_w);
	else if (data->frame < 20)
		data->img_e = mlx_xpm_file_to_image(data->mlx, \
		"./bonus/textures/itachi/4.xpm", &data->img_h, &data->img_w);
	else if (data->frame < 35)
		data->img_e = mlx_xpm_file_to_image(data->mlx, \
		"./bonus/textures/itachi/7.xpm", &data->img_h, &data->img_w);
	else if (data->frame < 45)
	{
		data->img_e = mlx_xpm_file_to_image(data->mlx, \
		"./bonus/textures/itachi/9.xpm", &data->img_h, &data->img_w);
		data->frame = 0;
	}
	ft_put(data, x, y);
}
