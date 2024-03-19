/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player__ennemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramt <abouramt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:48:33 by abouramt          #+#    #+#             */
/*   Updated: 2024/03/08 06:26:01 by abouramt         ###   ########.fr       */
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
