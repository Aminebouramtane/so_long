/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramt <abouramt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:39:22 by abouramt          #+#    #+#             */
/*   Updated: 2024/04/19 08:36:54 by abouramt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_draw_characters(t_ghlid *data)
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
}

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
			ft_draw_characters(data);
			data->x++;
		}
		data->y++;
	}
	data->moves = ft_itoa(data->move);
	mlx_string_put(data->mlx, data->win, 20, 20, 0xFFFFFF, "moves :");
	mlx_string_put(data->mlx, data->win, 100, 20, 0xFFFFFF, data->moves);
	free(data->moves);
	return (0);
}

int	key_close(t_ghlid *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

void	ft_valid_map(t_ghlid *data, char *av)
{
	data->nb_exit = 0;
	data->nb_kurama = 0;
	data->nb_player = 0;
	data->nb_enmy = 0;
	check_path(av);
	check_images(data);
	ft_map_valid(data);
	ft_chec_nb(data);
	ft_chec_characters(data);
	flood_fill_e(data);
	ft_putstr("Move : ");
	put_nbr(data->move);
	ft_putstr("\n");
	ft_position(data);
	ft_position_enemy(data);
}
