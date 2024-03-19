/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramt <abouramt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:40:31 by abouramt          #+#    #+#             */
/*   Updated: 2024/03/08 06:44:21 by abouramt         ###   ########.fr       */
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

int key_hook(int keycode, t_ghlid *data)
{
    if (keycode == 65307)
        exit(0);
    else if (keycode == 100)
	{
        move_player_right(data);
        ft_draw(data);
    }
    else if (keycode == 119)
	{
        move_player_up(data);
        ft_draw(data);
    }
    else if (keycode == 115)
	{
        move_player_down(data);
        ft_draw(data);
    }
    else if (keycode == 97)
	{
        move_player_left(data);
        ft_draw(data);
    }
    return 0;
}
