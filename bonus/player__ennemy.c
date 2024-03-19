/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_&_ennemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramt <abouramt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:48:33 by abouramt          #+#    #+#             */
/*   Updated: 2024/03/08 03:41:09 by abouramt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player(t_ghlid *data, int x, int y)
{
	void	*img_ground;

	img_ground = mlx_xpm_file_to_image(data->mlx, "./images2/ground_2.xpm", \
	&data->img_h, &data->img_w);
	if (data->if_player == 1 && ft_collect_coins(data) == 1)
		data->img = mlx_xpm_file_to_image(data->mlx, "./images2/right.xpm", \
		&data->img_h, &data->img_w);
	else if (data->if_player == 0 && ft_collect_coins(data) == 1)
		data->img = mlx_xpm_file_to_image(data->mlx, "./images2/left.xpm", \
		&data->img_h, &data->img_w);
	else if (data->if_player == 1)
		data->img = mlx_xpm_file_to_image(data->mlx, \
	"./images2/naruto_right-removebg-preview.xpm", &data->img_h, &data->img_w);
	else if (data->if_player == 0)
		data->img = mlx_xpm_file_to_image(data->mlx, \
	"./images2/naruto_left-removebg-preview.xpm", &data->img_h, &data->img_w);
	mlx_put_image_to_window(data->mlx, data->win, img_ground, x * 50, y * 50);
	mlx_put_image_to_window(data->mlx, data->win, data->img, x * 50, y * 50);
	ft_destroy_image(data->mlx, img_ground);
	ft_destroy_image(data->mlx, data->img);
}

void	ft_put(t_ghlid *data, int x, int y, void *img_ground)
{
	mlx_put_image_to_window(data->mlx, data->win, img_ground, x * 50, y * 50);
	mlx_put_image_to_window(data->mlx, data->win, data->img, x * 50, y * 50);
	ft_destroy_image(data->mlx, img_ground);
	ft_destroy_image(data->mlx, data->img);
}

void	ft_ennemy(t_ghlid *data, int x, int y)
{
	void	*img_ground;

	img_ground = mlx_xpm_file_to_image(data->mlx, \
	"./images2/ground_2.xpm", &data->img_h, &data->img_w);
	if (data->frame < 5)
		data->img = mlx_xpm_file_to_image(data->mlx, \
		"./images2/itachi/1.xpm", &data->img_h, &data->img_w);
	else if (data->frame < 15)
		data->img = mlx_xpm_file_to_image(data->mlx, \
		"./images2/itachi/3.xpm", &data->img_h, &data->img_w);
	else if (data->frame < 20)
		data->img = mlx_xpm_file_to_image(data->mlx, \
		"./images2/itachi/4.xpm", &data->img_h, &data->img_w);
	else if (data->frame < 35)
		data->img = mlx_xpm_file_to_image(data->mlx, \
		"./images2/itachi/7.xpm", &data->img_h, &data->img_w);
	else if (data->frame < 45)
	{
		data->img = mlx_xpm_file_to_image(data->mlx, \
		"./images2/itachi/9.xpm", &data->img_h, &data->img_w);
		data->frame = 0;
	}
	ft_put(data, x, y, img_ground);
}
