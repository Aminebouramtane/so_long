/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramt <abouramt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:39:53 by abouramt          #+#    #+#             */
/*   Updated: 2024/03/08 04:02:29 by abouramt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_position_player(int *x, int *y, t_ghlid *data)
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
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	ft_map_chec(t_ghlid *data)
{
	int	i;
	int	j;

	i = 0;
	data->map_chec = (char **)malloc((data->height + 1) * sizeof(char *));
	if (!data->map_chec)
		return ;
	while (i < data->height)
	{
		data->map_chec[i] = (char *)malloc((data->width + 1) * sizeof(char));
		if (!data->map_chec[i])
			return ;
		j = 0;
		while (j < data->width)
		{
			data->map_chec[i][j] = data->map[i][j];
			j++;
		}
		data->map_chec[i][data->width] = '\0';
		i++;
	}
}

static void	flood_fill(t_ghlid *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->width || y >= data->height
		|| data->map_chec[y][x] == '1' || data->map_chec[y][x] == '2')
		return ;
	data->map_chec[y][x] = '2';
	flood_fill(data, x - 1, y);
	flood_fill(data, x + 1, y);
	flood_fill(data, x, y - 1);
	flood_fill(data, x, y + 1);
}

static int	ft_if_e(t_ghlid *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map_chec[i][j] == 'E' || data->map_chec[i][j] == 'C')
			{
				ft_putstr("map invalid !!\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	flood_fill_e(t_ghlid *data)
{
	int	x;
	int	y;

	ft_position_player(&x, &y, data);
	ft_map_chec(data);
	flood_fill(data, x, y);
	ft_if_e(data);
}
