#include "so_long.h"

void move_player_up(t_ghlid *data)
{
    if ((data->map[data->player_y - 1][data->player_x] != '1' && data->map[data->player_y - 1][data->player_x] != 'E') || (data->map[data->player_y - 1][data->player_x] != '1' && ft_collect_coins(data) == 1))
	{
        data->map[data->player_y][data->player_x] = '0';
        data->player_y--;
        data->map[data->player_y][data->player_x] = 'P';
		data->move++;
		printf("moves : %d\n", data->move);
        system("leaks so_long");
    }
}
void move_player_down(t_ghlid *data) {
    if ((data->map[data->player_y + 1][data->player_x] != '1' && data->map[data->player_y + 1][data->player_x] != 'E') || (data->map[data->player_y + 1][data->player_x] != '1' && ft_collect_coins(data) == 1))
	{
        data->map[data->player_y][data->player_x] = '0';
        data->player_y++;
        data->map[data->player_y][data->player_x] = 'P';
		data->move++;
		printf("moves : %d\n", data->move);
        system("leaks so_long");
    }
}
void move_player_right(t_ghlid *data) {
    if ((data->map[data->player_y][data->player_x + 1] != '1' && data->map[data->player_y][data->player_x + 1] != 'E') || (data->map[data->player_y][data->player_x + 1] != '1' && ft_collect_coins(data) == 1))
	{
        data->map[data->player_y][data->player_x] = '0';
        data->player_x++;
        data->map[data->player_y][data->player_x] = 'P';
		data->move++;
		printf("moves : %d\n", data->move);
        system("leaks so_long");
    }
}
void move_player_left(t_ghlid *data) {
    if ((data->map[data->player_y][data->player_x - 1] != '1' && data->map[data->player_y][data->player_x - 1] != 'E') || (data->map[data->player_y][data->player_x - 1] != '1' && ft_collect_coins(data) == 1))
	{
        data->map[data->player_y][data->player_x] = '0';
        data->player_x--;
        data->map[data->player_y][data->player_x] = 'P';
		data->move++;
		printf("moves : %d\n", data->move);
        system("leaks so_long");
    }
}

int key_hook(int keycode, t_ghlid *data)
{
    if (keycode == 100)
    {
        move_player_right(data);
        ft_draw(data);
        printf("moved");
    }
    if (keycode == 119)
    {
        move_player_up(data);
        ft_draw(data);
        printf("moved");
    }
    if (keycode == 115)
    {
        move_player_down(data);
        ft_draw(data);
        printf("moved");
    }
    if (keycode == 97)
    {
        move_player_left(data);
        ft_draw(data);
        printf("moved");
    }
    return (0);
}
