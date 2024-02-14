#include "so_long.h"

void ft_gound(t_ghlid *data, int x, int y)
{
    data->img = mlx_xpm_file_to_image(data->mlx,"./images/i.xpm",&data->img_h,&data->img_w);
	mlx_put_image_to_window(data->mlx,data->win,data->img,x*20,y*20);
}

void ft_green(t_ghlid *data, int x, int y)
{
    data->img = mlx_xpm_file_to_image(data->mlx,"./images/ii.xpm",&data->img_h,&data->img_w);
	mlx_put_image_to_window(data->mlx,data->win,data->img,x*20,y*20);
}

void ft_coins(t_ghlid *data, int x, int y)
{
    data->img = mlx_xpm_file_to_image(data->mlx,"./images/iii.xpm",&data->img_h,&data->img_w);
	mlx_put_image_to_window(data->mlx,data->win,data->img, x*20, y*20);
}

void ft_exit(t_ghlid *data, int x, int y)
{
    data->img = mlx_xpm_file_to_image(data->mlx,"./images/iiii.xpm",&data->img_h,&data->img_w);
	mlx_put_image_to_window(data->mlx,data->win,data->img, x*20, y*20);
}

void ft_player(t_ghlid *data, int x, int y)
{
    data->img = mlx_xpm_file_to_image(data->mlx,"./images/iiiii.xpm",&data->img_h,&data->img_w);
	mlx_put_image_to_window(data->mlx, data->win, data->img, x*20, y*20);
}
