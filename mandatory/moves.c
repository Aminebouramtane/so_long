/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramt <abouramt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:40:31 by abouramt          #+#    #+#             */
/*   Updated: 2024/04/18 09:00:05 by abouramt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_up(t_ghlid *data)
{
	if ((data->map[data->player_y - 1][data->player_x] != '1'
		&& data->map[data->player_y - 1][data->player_x] != 'E')
		|| (data->map[data->player_y - 1][data->player_x] != '1'
		&& ft_collect_coins(data) == 1))
	{
		data->map[data->player_y][data->player_x] = '0';
		data->player_y--;
		data->map[data->player_y][data->player_x] = 'P';
		data->move++;
		ft_putstr("Move : ");
		put_nbr(data->move);
		ft_putstr("\n");
		ft_exit_(data);
	}
}

void	move_player_down(t_ghlid *data)
{
	if ((data->map[data->player_y + 1][data->player_x] != '1'
		&& data->map[data->player_y + 1][data->player_x] != 'E')
		|| (data->map[data->player_y + 1][data->player_x] != '1'
		&& ft_collect_coins(data) == 1))
	{
		data->map[data->player_y][data->player_x] = '0';
		data->player_y++;
		data->map[data->player_y][data->player_x] = 'P';
		data->move++;
		ft_putstr("Move : ");
		put_nbr(data->move);
		ft_putstr("\n");
		ft_exit_(data);
	}
}

void	move_player_right(t_ghlid *data)
{
	if ((data->map[data->player_y][data->player_x + 1] != '1'
		&& data->map[data->player_y][data->player_x + 1] != 'E')
		|| (data->map[data->player_y][data->player_x + 1] != '1'
		&& ft_collect_coins(data) == 1))
	{
		data->map[data->player_y][data->player_x] = '0';
		data->player_x++;
		data->map[data->player_y][data->player_x] = 'P';
		data->move++;
		ft_putstr("Move : ");
		put_nbr(data->move);
		ft_putstr("\n");
		ft_exit_(data);
		data->if_player = 1;
	}
}

void	move_player_left(t_ghlid *data)
{
	if ((data->map[data->player_y][data->player_x - 1] != '1'
		&& data->map[data->player_y][data->player_x - 1] != 'E')
		|| (data->map[data->player_y][data->player_x - 1] != '1'
		&& ft_collect_coins(data) == 1))
	{
		data->map[data->player_y][data->player_x] = '0';
		data->player_x--;
		data->map[data->player_y][data->player_x] = 'P';
		data->move++;
		ft_putstr("Move : ");
		put_nbr(data->move);
		ft_putstr("\n");
		ft_exit_(data);
		data->if_player = 0;
	}
}

int	key_hook(int keycode, t_ghlid *data)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 2)
	{
		move_player_right(data);
		ft_draw(data);
	}
	if (keycode == 13)
	{
		move_player_up(data);
		ft_draw(data);
	}
	if (keycode == 1)
	{
		move_player_down(data);
		ft_draw(data);
	}
	if (keycode == 0)
	{
		move_player_left(data);
		ft_draw(data);
	}
	return (0);
}
