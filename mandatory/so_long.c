/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramt <abouramt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:56:19 by abouramt          #+#    #+#             */
/*   Updated: 2024/04/18 17:46:16 by abouramt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_height_of_line(char *str, t_ghlid *data)
{
	char	*my_line;
	int		i;
	int		fd;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("ERROR IN FILE_D");
		exit(1);
	}
	my_line = get_next_line(fd);
	while (my_line)
	{
		i++;
		free(my_line);
		my_line = get_next_line(fd);
	}
	close(fd);
	data->height = i;
	if (data->height == 0)
	{
		ft_putstr("MAP INVALIDE !!");
		exit(1);
	}
}

void	ft_line(char *str, t_ghlid *data)
{
	int		i;
	char	*my_line;
	int		fd;

	i = 0;
	ft_get_height_of_line(str, data);
	fd = open(str, O_RDONLY);
	data->map = (char **)malloc(data->height * sizeof(char *) + 1);
	if (!data->map)
	{
		ft_free_map(data);
		exit(1);
	}
	my_line = get_next_line(fd);
	while (my_line)
	{
		data->map[i] = my_line;
		my_line = get_next_line(fd);
		i++;
	}
	close(fd);
	data->width = ft_strlen(data->map[0]);
}

void	check_path(char *av)
{
	if (ft_strcmp(&av[ft_strlen(av) - 4], ".ber") != 0)
	{
		ft_putstr("MAP INVALIDE !!");
		exit(1);
	}
}

int	main(int argc, char **av)
{
	t_ghlid	data;
	int		size_x;
	int		size_y;

	data.move = 0;
	ft_line(av[1], &data);
	if (argc != 2)
	{
		ft_putstr("ERROR !!\n");
		return (1);
	}
	size_x = (data.width - 1) * 50;
	size_y = data.height * 50;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, size_x, size_y, "So_long");
	ft_valid_map(&data, av[1]);
	ft_position(&data);
	ft_draw(&data);
	mlx_hook(data.win, 2, 0, key_hook, &data);
	mlx_hook(data.win, 17, 0, key_close, &data);
	mlx_loop(data.mlx);
	ft_free_map(&data);
}
