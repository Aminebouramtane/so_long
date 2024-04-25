/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramt <abouramt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:41:22 by abouramt          #+#    #+#             */
/*   Updated: 2024/04/18 11:38:54 by abouramt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_position(t_ghlid *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ft_collect_coins(t_ghlid *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_door(t_ghlid *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_exit_(t_ghlid *data)
{
	if (ft_collect_coins(data) && ft_is_door(data))
	{
		ft_putstr("You Win !!\n");
		exit(0);
	}
}

void	ft_map_valid(t_ghlid *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		if (ft_strlen(data->map[0]) != ft_strlen(data->map[i]))
		{
			ft_putstr("data width is invalid !!\n");
			exit(1);
		}
		i++;
	}
	ft_check_map_botop(data);
	ft_check_sides(data);
}
