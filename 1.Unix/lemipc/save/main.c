#include <lemipc.h>

static void			check_data(void)
{
	if (WIDTH > MAXWIDTH || HEIGHT > MAXHEIGHT)
		ft_errexit("Map's size too big.", RED, MAP_TOO_BIG);
}

static void			init_envv(t_env *e)
{
	e->msgq_id = 0;
	e->team = 0;
	e->leader_msgq_id = -1;
	e->teammates = NULL;
	e->i = 0;
	e->j = 0;
	e->pos = 0;
	e->target->j = -1;
	e->target->i = -1;
	e->target->pos = -1;
}

static t_env		*init_env(void)
{
	t_env	*e;

	check_data();
	if ((e = (t_env*)malloc(sizeof(t_env))) == NULL \
		|| (e->map_mem = (t_smem*)malloc(sizeof(t_smem))) == NULL \
		|| (e->team_mem = (t_smem*)malloc(sizeof(t_smem))) == NULL \
		|| (e->target = (t_target*)malloc(sizeof(t_target))) == NULL)
		ft_errexit("malloc failed", RED, MALLOC_FAILED);
	srand((int)e);
	e->map_mem->key = 0;
	e->map_mem->sema_id = 0;
	e->map_mem->shm_id = 0;
	e->map_mem->data = NULL;
	e->map_mem->cdata = NULL;
	e->map_mem->size = WIDTH * HEIGHT + INFOS_ADD_SIZE;
	e->team_mem->key = 0;
	e->team_mem->sema_id = 0;
	e->team_mem->shm_id = 0;
	e->team_mem->data = NULL;
	e->team_mem->cdata = NULL;
	e->team_mem->size = sizeof(int) * TEAM_ADD_SIZE;
	init_envv(e);
	return (e);
}

int					main(int ac, char **av)
{
	t_env	*e;
	int		i;

	printf("-----------------------------------------------\n");
	signal(SIGINT, stop_game);
	if (ac < 2 || ac > 4 || ft_isdigit_str(av[1]) == 0 || ft_strlen(av[1]) > 9)
		ft_errexit("Error\nUsage: lemipc team [x y]", NOCOLOR, FTOK_FAILED);
	e = init_env();
	init_ipcs(e, av + 1, av[0], 0);
	init_msgq(e);
	sleep(1);
	i = 0;
	while (TEAM_LEFT > 1)
	{
		usleep(REFRESH_TIME);
		check_leader(e);
		manage_messages(e);
		if (LEADER == e->msgq_id)
			search_target(e);
		move(e);
		i++;
		if (i == TIMEOUT)
			close_ipcs(e->map_mem, -1);
	}
	sleep(10);
	printf("%d \033[33;32mWON\033[33;37m\n", e->team);
	return (0);
}
