/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramt <abouramt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:40:14 by abouramt          #+#    #+#             */
/*   Updated: 2024/03/08 06:24:54 by abouramt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_ghlid *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	ft_free_map_chec(t_ghlid *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->map_chec[i]);
		i++;
	}
	free(data->map_chec);
}

void	ft_chec_nb(t_ghlid *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == 'E')
				data->nb_exit += 1;
			else if (data->map[i][j] == 'C')
				data->nb_kurama += 1;
			else if (data->map[i][j] == 'P')
				data->nb_player += 1;
			j++;
		}
		i++;
	}
	if (data->nb_exit != 1 || data->nb_kurama <= 0 || data->nb_player != 1)
	{
		ft_putstr("data Number characters invalid !!\n");
		ft_free_map(data);
		exit(0);
	}
}

void	ft_chec_characters(t_ghlid *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] != 'P' && data->map[i][j] != 'E'
			&& data->map[i][j] != 'C' && data->map[i][j] != '1'
			&& data->map[i][j] != '0' && data->map[i][j] != '\n')
			{
				ft_putstr("data characters invalid !!\n");
				ft_free_map(data);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
