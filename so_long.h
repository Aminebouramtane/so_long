#ifndef SO_LONG_H
#define SO_LONG_H

#include "minilibx-linux/mlx.h"
#include "get_next_line/get_next_line.h"

typedef struct list
{
    void *mlx;
    void *win;
    char **map;
    char *line;
    int map_width;
    int map_height;
    int height;
    int x;
    size_t y;

} t_list;

int ft_height(char *str);
void ft_store_line(t_list *data, char *str);


#endif