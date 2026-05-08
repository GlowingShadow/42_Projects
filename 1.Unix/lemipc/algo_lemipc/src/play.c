#include <algo.h>

void	orbit(t_pl *player, t_pl *target, char **map)
{
	(void)player;
	(void)target;
	(void)map;
}

void	approch(t_pl *player, t_pl *target, char **map)
{
	int		ydist;
	int		xdist;
	int		(*moves[2])(t_pl *, char **);

	ydist = player->y - target->y;
	xdist = player->x - target->x;

	moves[0] = move_down;
	if (ydist > 0)
		moves[0] = move_up;

	moves[1] = move_right;
	if (xdist > 0)
		moves[1] = move_left;
	
	if (ft_abs(ydist) < ft_abs(xdist))
	{
		if (ydist == 0 || moves[0](player, map) == -1)
			if (moves[1](player, map) == -1)
				moves[0](player, map);
	}
	else
	{
		if (xdist == 0 || moves[1](player, map) == -1)
			if (moves[0](player, map) == -1)
				moves[1](player, map);
	}
}

void	chase_target(t_pl *player, t_pl *target, char **map)
{
	int		ydist;
	int		xdist;

	if (map[target->y][target->x] == player->team || \
		map[target->y][target->x] == '.')
		target = search_target(target, map);
	if (!target)
	{
		ft_putendl("No alternative target found");
		return ;
	}
	ydist = player->y - target->y;
	xdist = player->x - target->x;
	if (xdist <= 1 && ydist <= 1)
		approch(player, target, map);//orbit
	else
		approch(player, target, map);
}

void	play(t_env *e, t_pl	*player)
{
	if (player->alive == 1)
		check_dead(e, player);
	if (player->alive == 0) 
		return ;
	usleep(200000);
	if (e->id_pl[player->team] == -1 || e->id_pl[player->team] == player->id)
	{
		e->id_pl[player->team] = player->id;
		e->target[player->team] = search_target(player, e->map);
	}
	if (e->target[player->team])
		chase_target(player, e->target[player->team], e->map);
}