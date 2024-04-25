/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramt <abouramt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:39:22 by abouramt          #+#    #+#             */
/*   Updated: 2024/04/19 07:21:48 by abouramt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_draw(t_ghlid *data)
{
	data->y = 0;
	mlx_clear_window(data->mlx, data->win);
	while (data->y < data->height)
	{
		data->x = 0;
		while (data->x < ft_strlen(data->map[data->y]))
		{
			if (data->map[data->y][data->x] == '1')
				ft_gound(data, data->x, data->y);
			else if (data->map[data->y][data->x] == '0')
				ft_green(data, data->x, data->y);
			else if (data->map[data->y][data->x] == 'C')
				ft_coins(data, data->x, data->y);
			else if (data->map[data->y][data->x] == 'E')
				ft_door(data, data->x, data->y);
			else if (data->map[data->y][data->x] == 'P')
				ft_player(data, data->x, data->y);
			data->x++;
		}
		data->y++;
	}
	return (0);
}

void	check_images(t_ghlid *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, \
	"./mandatory/textures/wall.xpm", &data->img_h, &data->img_w);
	data->img_g = mlx_xpm_file_to_image(data->mlx, \
	"./mandatory/textures/ground_2.xpm", &data->img_h, &data->img_w);
	data->img_c = mlx_xpm_file_to_image(data->mlx, \
	"./mandatory/textures/curama.xpm", &data->img_h, &data->img_w);
	data->img_d = mlx_xpm_file_to_image(data->mlx, \
	"./mandatory/textures/door.xpm", &data->img_h, &data->img_w);
	data->img_p = mlx_xpm_file_to_image(data->mlx, \
	"./mandatory/textures/right.xpm", &data->img_h, &data->img_w);
	if (!data->img || !data->img_p || !data->img_g
		|| !data->img_c || !data->img_d)
	{
		ft_putstr("Error in images");
		ft_free_map(data);
		exit(1);
	}
}

int	key_close(t_ghlid *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

void	ft_valid_map(t_ghlid *data, char *av)
{
	check_path(av);
	check_images(data);
	ft_map_valid(data);
	ft_chec_characters(data);
	ft_chec_nb(data);
	flood_fill_e(data);
	ft_putstr("Move : ");
	put_nbr(data->move);
	ft_putstr("\n");
}
