#ifndef ALGO_H
# define ALGO_H

# include <libft.h>

typedef struct	s_pl
{
	int			id;
	int			alive;
	int			x;
	int			y;
	int			team;
	struct s_pl	*next;
}				t_pl;

typedef struct	s_env
{
	char	**map;
	t_pl	*players;
	int		id_pl[5];
	t_pl	*target[5];
}				t_env;

t_pl	*search_target(t_pl *leader, char **map);
void	ft_puttab2(char **tab);
void	check_dead(t_env *e, t_pl *player);
void	play(t_env *e, t_pl	*player);
int		move_up(t_pl *player, char **map);
int		move_down(t_pl *player, char **map);
int		move_left(t_pl *player, char **map);
int		move_right(t_pl *player, char **map);

#endif
