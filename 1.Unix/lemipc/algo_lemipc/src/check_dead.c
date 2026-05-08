#include <algo.h>

int		get_player(char **map, int y, int x)
{
	if (y < 0 || y >= 20 || x < 0 || x >= 20)
		return (-2);
	if (map[y][x] != '.')
		return (map[y][x]);
	return (-1);
}

static int		check_around(t_pl *player, int *ennemis)
{
	int		i;
	int		j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (ennemis[i] >= 0 && j < 7)
		{
			if (i != j && ennemis[j] >= 0 && ennemis[j] == ennemis[i] \
				&& ennemis[i] != player->team)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_dead(t_env *e, t_pl *player)
{
	int		ennemis[8];

	ennemis[0] = get_player(e->map, player->y - 1, player->x + 0);
	ennemis[1] = get_player(e->map, player->y - 1, player->x - 1);
	ennemis[2] = get_player(e->map, player->y - 1, player->x + 1);
	ennemis[3] = get_player(e->map, player->y + 1, player->x + 0);
	ennemis[4] = get_player(e->map, player->y + 1, player->x - 1);
	ennemis[5] = get_player(e->map, player->y + 1, player->x + 1);
	ennemis[6] = get_player(e->map, player->y + 0, player->x + 1);
	ennemis[7] = get_player(e->map, player->y + 0, player->x - 1);
	if (check_around(player, ennemis) == -1)
	{
		ft_putnbr(player->team);ft_putchar('|');
		ft_putnbr(player->id);ft_putendl(" DEAD");
		player->alive = 0;
		e->map[player->y][player->x] = '.';
		if (e->id_pl[player->team] == player->id)
			e->id_pl[player->team] = -1;
	}
}
