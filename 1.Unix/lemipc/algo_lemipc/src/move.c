#include <algo.h>

int		move_down(t_pl *player, char **map)
{
	if (player->y + 1 < 20 && \
		map[player->y + 1][player->x] == '.')
	{
		map[player->y + 1][player->x] = player->team;
		map[player->y][player->x] = '.';
		player->y += 1;
		return (0);
	}
	return (-1);
}

int		move_up(t_pl *player, char **map)
{
	if (player->y - 1 >= 0 && \
		map[player->y - 1][player->x] == '.')
	{
		map[player->y - 1][player->x] = player->team;
		map[player->y][player->x] = '.';
		player->y -= 1;
		return (0);
	}
	return (-1);
}

int		move_left(t_pl *player, char **map)
{
	if (player->x - 1 >= 0 && \
		map[player->y][player->x - 1] == '.')
	{
		map[player->y][player->x - 1] = player->team;
		map[player->y][player->x] = '.';
		player->x -= 1;
		return (0);
	}
	return (-1);
}

int		move_right(t_pl *player, char **map)
{
	if (player->x + 1 < 20 && \
		map[player->y][player->x + 1] == '.')
	{
		map[player->y][player->x + 1] = player->team;
		map[player->y][player->x] = '.';
		player->x += 1;
		return (0);
	}
	return (-1);
}
