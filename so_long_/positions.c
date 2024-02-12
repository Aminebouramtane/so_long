#include "so_long.h"

void ft_position(t_ghlid *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	data->player_x = 0;
	data->player_y = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
			}
			j++;
		}
		i++;
	}
}

int ft_collect_coins(t_ghlid *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map[i])
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


