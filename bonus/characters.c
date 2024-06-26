/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramt <abouramt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:57:45 by abouramt          #+#    #+#             */
/*   Updated: 2024/04/19 07:27:35 by abouramt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_gound(t_ghlid *data, int x, int y)
{
	data->img = mlx_xpm_file_to_image(data->mlx, \
	"./bonus/textures/wall.xpm", &data->img_h, &data->img_w);
	mlx_put_image_to_window(data->mlx, data->win, data->img, x * 50, y * 50);
	mlx_destroy_image(data->mlx, data->img);
}

void	ft_green(t_ghlid *data, int x, int y)
{
	data->img_g = mlx_xpm_file_to_image(data->mlx, \
	"./bonus/textures/ground_2.xpm", &data->img_h, &data->img_w);
	mlx_put_image_to_window(data->mlx, data->win, data->img_g, x * 50, y * 50);
	mlx_destroy_image(data->mlx, data->img_g);
}

void	ft_coins(t_ghlid *data, int x, int y)
{
	data->img_g = mlx_xpm_file_to_image(data->mlx, \
	"./bonus/textures/ground_2.xpm", &data->img_h, &data->img_w);
	data->img_c = mlx_xpm_file_to_image(data->mlx, \
	"./bonus/textures/curama.xpm", &data->img_h, &data->img_w);
	mlx_put_image_to_window(data->mlx, data->win, data->img_g, x * 50, y * 50);
	mlx_put_image_to_window(data->mlx, data->win, data->img_c, x * 50, y * 50);
	mlx_destroy_image(data->mlx, data->img_g);
	mlx_destroy_image(data->mlx, data->img_c);
}

void	ft_door(t_ghlid *data, int x, int y)
{
	data->img_g = mlx_xpm_file_to_image(data->mlx, \
	"./bonus/textures/ground_2.xpm", &data->img_h, &data->img_w);
	data->img_d = mlx_xpm_file_to_image(data->mlx, \
	"./bonus/textures/door.xpm", &data->img_h, &data->img_w);
	mlx_put_image_to_window(data->mlx, data->win, data->img_g, x * 50, y * 50);
	mlx_put_image_to_window(data->mlx, data->win, data->img_d, x * 50, y * 50);
	mlx_destroy_image(data->mlx, data->img_g);
	mlx_destroy_image(data->mlx, data->img_d);
}
