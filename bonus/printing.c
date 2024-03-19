/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramt <abouramt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:41:40 by abouramt          #+#    #+#             */
/*   Updated: 2024/03/08 07:03:56 by abouramt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	put_nbr(int nbr)
{
	if (nbr >= 0 && nbr <= 9)
	{
		nbr += 48;
		write(1, &nbr, 1);
	}
	else
	{
		put_nbr(nbr / 10);
		put_nbr(nbr % 10);
	}
}

void	ft_check_map_botop(t_ghlid *data)
{
	int	i;

	i = 0;
	while (i < data->width)
	{
		if (data->map[0][i] == '0' || data->map[0][i] == 'P'
			|| data->map[0][i] == 'C' || data->map[0][i] == 'X'
			|| data->map[data->height - 1][i] == '0'
			|| data->map[data->height - 1][i] == 'P'
			|| data->map[data->height - 1][i] == 'X'
			|| data->map[data->height - 1][i] == 'C')
		{
			ft_putstr("data map bottom and top is invalid !!\n");
			free(data->map);
			exit(1);
		}
		i++;
	}
}

void	ft_check_sides(t_ghlid *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		if (data->map[0][i] == '0' || data->map[0][i] == 'P'
			|| data->map[0][i] == 'C' || data->map[0][i] == 'X'
			|| data->map[data->height - 1][i] == '0'
			|| data->map[data->height - 1][i] == 'P'
			|| data->map[data->height - 1][i] == 'X'
			|| data->map[data->height - 1][i] == 'C')
		{
			ft_putstr("data map sides is invalid !!\n");
			free(data->map);
			exit(1);
		}
		i++;
	}
}

int	ft_strcmp(char *ptr1, char *ptr2)
{
	int	i;

	i = 0;
	while (ptr1[i] == ptr2[i] && ptr1[i] != '\0' && ptr2[i] != '\0')
		i++;
	return (ptr1[i] - ptr2[i]);
}
