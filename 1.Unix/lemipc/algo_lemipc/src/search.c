#include <algo.h>

char	**ft_tabdup(char **tab)
{
	char	**cpy;
	int		i = 0;

	while (tab[i] != NULL)
		i++;
	cpy = (char**)malloc(sizeof(char*) * (i + 1));
	i = 0;
	while (tab[i] != NULL)
	{
		cpy[i] = ft_strdup(tab[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

void	check_target(t_pl *leader, t_pl *target, int y, int x)
{
	if (target->team == -1 || \
		ft_abs(leader->x - x) + ft_abs(leader->y - y) < \
		ft_abs(leader->x - target->x) + ft_abs(leader->y - target->y))
	{	target->x = x;
		target->y = y;
		target->team = 1;
	}
}

t_pl	*search_target(t_pl *leader, char **map)
{
	t_pl	*target = (t_pl*)malloc(sizeof(t_pl));
	int		x;
	int		y;

	target->team = -1;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != 0)
		{
			if (map[y][x] != '.' && map[y][x] != leader->team)
				check_target(leader, target, y, x);
			x++;
		}
		y++;
	}
	if (target->team == -1)
	{
		ft_putendl("No target found");
		free(target);
		return (NULL);
	}
	ft_putstr("\tFound: ");
	ft_putnbr(target->y);
	ft_putstr(" ");
	ft_putnbr(target->x);
	ft_putchar(10);
	return (target);
}