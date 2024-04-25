/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramt <abouramt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:57:45 by abouramt          #+#    #+#             */
/*   Updated: 2024/04/19 07:18:03 by abouramt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_gound(t_ghlid *data, int x, int y)
{
	data->img = mlx_xpm_file_to_image(data->mlx, \
	"./mandatory/textures/wall.xpm", &data->img_h, &data->img_w);
	mlx_put_image_to_window(data->mlx, data->win, data->img, x * 50, y * 50);
	mlx_destroy_image(data->mlx, data->img);
}

void	ft_green(t_ghlid *data, int x, int y)
{
	data->img_g = mlx_xpm_file_to_image(data->mlx, \
	"./mandatory/textures/ground_2.xpm", &data->img_h, &data->img_w);
	mlx_put_image_to_window(data->mlx, data->win, data->img_g, x * 50, y * 50);
	mlx_destroy_image(data->mlx, data->img_g);
}

void	ft_coins(t_ghlid *data, int x, int y)
{
	data->img_g = mlx_xpm_file_to_image(data->mlx, \
	"./mandatory/textures/ground_2.xpm", &data->img_h, &data->img_w);
	data->img_c = mlx_xpm_file_to_image(data->mlx, \
	"./mandatory/textures/curama.xpm", &data->img_h, &data->img_w);
	mlx_put_image_to_window(data->mlx, data->win, data->img_g, x * 50, y * 50);
	mlx_put_image_to_window(data->mlx, data->win, data->img_c, x * 50, y * 50);
	mlx_destroy_image(data->mlx, data->img_g);
	mlx_destroy_image(data->mlx, data->img_c);
}

void	ft_door(t_ghlid *data, int x, int y)
{
	data->img_g = mlx_xpm_file_to_image(data->mlx, \
	"./mandatory/textures/ground_2.xpm", &data->img_h, &data->img_w);
	data->img_d = mlx_xpm_file_to_image(data->mlx, \
	"./mandatory/textures/door.xpm", &data->img_h, &data->img_w);
	mlx_put_image_to_window(data->mlx, data->win, data->img_g, x * 50, y * 50);
	mlx_put_image_to_window(data->mlx, data->win, data->img_d, x * 50, y * 50);
	mlx_destroy_image(data->mlx, data->img_g);
	mlx_destroy_image(data->mlx, data->img_d);
}

void	ft_player(t_ghlid *data, int x, int y)
{
	data->img_g = mlx_xpm_file_to_image(data->mlx, \
	"./mandatory/textures/ground_2.xpm", &data->img_h, &data->img_w);
	if (data->if_player == 1 && ft_collect_coins(data) == 1)
		data->img_p = mlx_xpm_file_to_image(data->mlx, \
		"./mandatory/textures/right.xpm", &data->img_h, &data->img_w);
	else if (data->if_player == 0 && ft_collect_coins(data) == 1)
		data->img_p = mlx_xpm_file_to_image(data->mlx, \
		"./mandatory/textures/left.xpm", &data->img_h, &data->img_w);
	else if (data->if_player == 1)
		data->img_p = mlx_xpm_file_to_image(data->mlx, \
	"./mandatory/textures/naruto_right.xpm", &data->img_h, &data->img_w);
	else if (data->if_player == 0)
		data->img_p = mlx_xpm_file_to_image(data->mlx, \
	"./mandatory/textures/naruto_left.xpm", &data->img_h, &data->img_w);
	mlx_put_image_to_window(data->mlx, data->win, data->img_g, x * 50, y * 50);
	mlx_put_image_to_window(data->mlx, data->win, data->img_p, x * 50, y * 50);
	mlx_destroy_image(data->mlx, data->img_g);
	mlx_destroy_image(data->mlx, data->img_p);
}
