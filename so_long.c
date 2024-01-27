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

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        t_list  data;
        int i = 0;

        ft_store_line(&data, argv[1]);
        printf("%d\n", data.height);
        while (i < 9)
        {
            printf("%s\n",data.map[i]);
            i++;
        }
    }
}