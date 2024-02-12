#include "so_long.h"
#include "./get_next_line/get_next_line.h"

void	ft_draw(t_ghlid *data)
{
    data->y = 0;
    data->x = 0;

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
				ft_exit(data, data->x, data->y);
			else if (data->map[data->y][data->x] == 'P')
				ft_player(data, data->x, data->y);
			data->x++;
		}
		data->y++;
	}
}
