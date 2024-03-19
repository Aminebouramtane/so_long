/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramt <abouramt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:39:22 by abouramt          #+#    #+#             */
/*   Updated: 2024/03/08 15:12:42 by abouramt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_draw(t_ghlid *data)
{
	data->y = 0;
	data->frame++;
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
			else if (data->map[data->y][data->x] == 'X')
				ft_ennemy(data, data->x, data->y);
			data->x++;
		}
		data->y++;
	}
	mlx_string_put(data->mlx, data->win, 20, 20, 0xFFFFFF, "Hello, World!");
	return (0);
}

void	ft_valid_map(t_ghlid *data, char *av)
{
	check_path(av);
	ft_map_valid(data);
	ft_chec_characters(data);
	ft_chec_nb(data);
	flood_fill_e(data);
	ft_putstr("Move : ");
	put_nbr(data->move);
	ft_putstr("\n");

}
