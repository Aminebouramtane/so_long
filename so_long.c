#include "so_long.h"

void ft_get_height_of_line(char *str , t_ghlid *data)
{
    char    *my_line;
    int i;

    i = 0;
    int fd = open(str, O_RDONLY);
    while ((my_line = get_next_line(fd)) != NULL)
        i++;
    close(fd);
    data->height = i;
}

void    ft_line(char *str , t_ghlid *data)
{
	int	i;
	char	*my_line;
    int fd;
	i = 0;
    fd = open(str, O_RDONLY);

	ft_get_height_of_line(str,data);
	data->map = (char **)malloc(data->height * sizeof(char *) + 1);
	while ((my_line = get_next_line(fd)) != NULL)
	{
		data->map[i] = my_line;
		i++;
	}
    close(fd);
    data->width = strlen(data->map[0]);
}

int main(int argc, char **av)
{
    t_ghlid data;
    data.move = 0;
	ft_line(av[1] , &data);
    (void)argc;
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, (data.width * 20) - 20, data.height * 20, "So_long");
	ft_draw(&data);
    ft_position(&data);
    mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
    ft_draw(&data);
    // printf("moves : %d\n", data.move);
    // system("leaks so_long");
    mlx_loop(data.mlx);

}
