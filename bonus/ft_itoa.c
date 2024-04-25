/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramt <abouramt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:20:48 by abouramt          #+#    #+#             */
/*   Updated: 2024/04/19 07:29:36 by abouramt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_len(long int c)
{
	int	i;

	i = 1;
	if (c < 0)
	{
		i = i + 1;
		c = -c;
	}
	while (c / 10)
	{
		i++;
		c = c / 10;
	}
	return (i);
}

static void	convert(char *p, long int nb, int len)
{
	while (nb)
	{
		p[len - 1] = (nb % 10) + 48;
		nb = nb / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int			len;
	int			i;
	char		*p;
	long int	nb;

	nb = n;
	len = count_len(nb);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	if (nb == 0)
		p[i] = '0';
	if (nb < 0)
	{
		p[i] = '-';
		i++;
		nb = -nb;
	}
	p[len] = '\0';
	convert(p, nb, len);
	return (p);
}

void	ft_position_enemy(t_ghlid *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'X')
			{
				data->enemy_x = j;
				data->enemy_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	check_images(t_ghlid *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, \
	"./mandatory/textures/wall.xpm", &data->img_h, &data->img_w);
	data->img_g = mlx_xpm_file_to_image(data->mlx, \
	"./mandatory/textures/ground_2.xpm", &data->img_h, &data->img_w);
	data->img_c = mlx_xpm_file_to_image(data->mlx, \
	"./mandatory/textures/curama.xpm", &data->img_h, &data->img_w);
	data->img_d = mlx_xpm_file_to_image(data->mlx, \
	"./mandatory/textures/door.xpm", &data->img_h, &data->img_w);
	data->img_p = mlx_xpm_file_to_image(data->mlx, \
	"./mandatory/textures/right.xpm", &data->img_h, &data->img_w);
	data->img_e = mlx_xpm_file_to_image(data->mlx, \
	"./mandatory/textures/itachi/1.xpm", &data->img_h, &data->img_w);
	if (!data->img || !data->img_p || !data->img_g
		|| !data->img_c || !data->img_d || !data->img_e)
	{
		ft_putstr("Error in images");
		ft_free_map(data);
		exit(1);
	}
}
