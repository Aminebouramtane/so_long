/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramt <abouramt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:57:45 by abouramt          #+#    #+#             */
/*   Updated: 2024/03/08 04:01:54 by abouramt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_image(void *mlx, void *img)
{
	mlx_destroy_image(mlx, img);
}

void	ft_gound(t_ghlid *data, int x, int y)
{
	data->img = mlx_xpm_file_to_image(data->mlx, "./images2/wall.xpm", \
				&data->img_h, &data->img_w);
	mlx_put_image_to_window(data->mlx, data->win, data->img, x * 50, y * 50);
	ft_destroy_image(data->mlx, data->img);
}

void	ft_green(t_ghlid *data, int x, int y)
{
	data->img = mlx_xpm_file_to_image(data->mlx, "./images2/ground_2.xpm", \
	&data->img_h, &data->img_w);
	mlx_put_image_to_window(data->mlx, data->win, data->img, x * 50, y * 50);
	ft_destroy_image(data->mlx, data->img);
}

void	ft_coins(t_ghlid *data, int x, int y)
{
	void	*img_ground;

	img_ground = mlx_xpm_file_to_image(data->mlx, "./images2/ground_2.xpm", \
	&data->img_h, &data->img_w);
	data->img = mlx_xpm_file_to_image(data->mlx, "./images2/curama.xpm", \
	&data->img_h, &data->img_w);
	mlx_put_image_to_window(data->mlx, data->win, img_ground, x * 50, y * 50);
	mlx_put_image_to_window(data->mlx, data->win, data->img, x * 50, y * 50);
	ft_destroy_image(data->mlx, img_ground);
	ft_destroy_image(data->mlx, data->img);
}

void	ft_door(t_ghlid *data, int x, int y)
{
	void	*img_ground;

	img_ground = mlx_xpm_file_to_image(data->mlx, "./images2/ground_2.xpm", \
	&data->img_h, &data->img_w);
	data->img = mlx_xpm_file_to_image(data->mlx, "./images2/door.xpm", \
	&data->img_h, &data->img_w);
	mlx_put_image_to_window(data->mlx, data->win, img_ground, x * 50, y * 50);
	mlx_put_image_to_window(data->mlx, data->win, data->img, x * 50, y * 50);
	ft_destroy_image(data->mlx, img_ground);
	ft_destroy_image(data->mlx, data->img);
}
