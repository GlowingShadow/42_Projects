#include <algo.h>

void	ft_puttab2(char **tab)
{
	int	i = 0;

	while (tab[i] != 0)
	{
		int	j = 0;
		while (tab[i][j] != 0)
		{
			if (tab[i][j] == '.')
				ft_putchar('.');
			else
				ft_putchar(tab[i][j] + 48);
			ft_putchar(32);
			j++;
		}
		ft_putchar(10);
		i++;
	}
	ft_putchar(10);
}

char	**build_map(void)
{
	char	**map;

	map = (char**)malloc(sizeof(char*) * 21);
	int	i = 0;
	while (i < 20)
	{
		map[i] = (char*)malloc(sizeof(char) * 21);
		int	j = 0;
		while (j < 20)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

t_pl	*fill_data(char ***map, int y, int x, int team)
{
	t_pl		*ptr;
	static int	i = 0;

	i++;
	ptr = (t_pl*)malloc(sizeof(t_pl));
	ptr->id = i;
	ptr->alive = 1;
	ptr->x = x;
	ptr->y = y;
	ptr->team = team;
	ptr->next = NULL;
	(*map)[y][x] = team;
	return (ptr);
}

t_pl	*build_players(char ***map)
{
	t_pl	*players;
	t_pl	*ptr;

	ptr = fill_data(map, 1, 1, 1); players = ptr;
	ptr->next = fill_data(map, 1, 2, 1); ptr = ptr->next;
	ptr->next = fill_data(map, 2, 2, 1); ptr = ptr->next;
	ptr->next = fill_data(map, 2, 1, 1); ptr = ptr->next;
	ptr->next = fill_data(map, 17, 1, 2); ptr = ptr->next;
	ptr->next = fill_data(map, 17, 2, 2); ptr = ptr->next;
	ptr->next = fill_data(map, 16, 1, 2); ptr = ptr->next;
	ptr->next = fill_data(map, 16, 2, 2); ptr = ptr->next;
	ptr->next = fill_data(map, 1, 16, 3); ptr = ptr->next;
	ptr->next = fill_data(map, 1, 17, 3); ptr = ptr->next;
	ptr->next = fill_data(map, 2, 16, 3); ptr = ptr->next;
	ptr->next = fill_data(map, 2, 17, 3); ptr = ptr->next;
	ptr->next = fill_data(map, 16, 16, 4); ptr = ptr->next;
	ptr->next = fill_data(map, 16, 17, 4); ptr = ptr->next;
	ptr->next = fill_data(map, 17, 16, 4); ptr = ptr->next;
	ptr->next = fill_data(map, 17, 17, 4); ptr = ptr->next;
	return (players);
}

t_env	*init_env()
{
	t_env	*e = (t_env*)malloc(sizeof(t_env));
	
	e->map = build_map();
	e->players = build_players(&(e->map));
	e->id_pl[0] = -1;
	e->id_pl[1] = -1;
	e->id_pl[2] = -1;
	e->id_pl[3] = -1;
	e->id_pl[4] = -1;
	e->target[0] = NULL;
	e->target[1] = NULL;
	e->target[2] = NULL;
	e->target[3] = NULL;
	e->target[4] = NULL;
	return (e);
}

int		main(void)
{
	t_env	*e = init_env();
	t_pl	*ptr;
	ft_puttab2(e->map);
	while (1)
	{
		// sleep(1);
		ptr = e->players;
		while (ptr != NULL)
		{
			ft_putstr("Play: ");ft_putnbr(ptr->team);ft_putchar('|');
			ft_putnbr(ptr->id);ft_putstr(": ");
			ft_putnbr(ptr->x);ft_putstr("-");ft_putnbr(ptr->y);
			ft_putstr("\n");
			play(e, ptr);
			ptr = ptr->next;
			ft_puttab2(e->map);
		}
		ft_puttab2(e->map);
	}
	return 0;
}
