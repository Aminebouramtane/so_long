#include "so_long.h"

int ft_height(char *str)
{
    char *line;
    int height = 0;

    int fd = open(str, O_RDONLY);
    line = get_next_line(fd);
    while (line != NULL)
    {
        height++;
        line = get_next_line(fd);
    }
    return (height);
    close(fd);
}

void ft_store_line(t_list *data, char *str)
{
    char *line;
    int i;

    i = 0;
    int fd = open(str, O_RDONLY);
    data->height = ft_height(str);
    data->map = (char **)malloc(data->height * sizeof(char *));
    if (data->map == NULL)
        return;
    line = get_next_line(fd);
    while (i < data->height)
    {
        data->map[i] = line;
        line = get_next_line(fd);
        i++;
    }
    close(fd);
}

// void ft_draw(char str,t_list data)
// {
//     t_list
// }

int main(int argc, char **argv)
{
    (void)argc;
    t_list data;
    int i = 0;
    size_t j = 0;
    ft_store_line(&data, argv[1]);
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 2000, 700, "SO_long");
    void *img = mlx_xpm_file_to_image(data.mlx, "./ground.xpm", &data.map_width, &data.map_height);
    while (i < data.height)
    {
        j = 0;
        while (j < ft_strlen(data.map[i]))
        {
            if(data.map[i][j] == '1')
            {
                mlx_put_image_to_window(data.mlx, data.win, img, j * 40, i * 40);
            }
            j++;
        }
        printf("%zu\n", ft_strlen(data.map[i]));
        i++;
    }  
    mlx_loop(data.mlx);
}