/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 17:03:24 by REDACTED          #+#    #+#             */
/*   Updated: 2016/07/01 17:03:27 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc_aff.h>

static t_env		*init_env(void)
{
	t_env	*e;

	if ((e = (t_env*)malloc(sizeof(t_env))) == NULL)
		ft_errexit("malloc failed", RED, MALLOC_FAILED);
	e->game_won = -1;
	e->winner = NULL;
	e->game_paused = 0;
	e->end_game = 0;
	e->mapcpy = NULL;
	e->key = 0;
	e->sema1_id = 0;
	e->shm1_id = 0;
	e->data = NULL;
	e->cdata = NULL;
	e->size = WIDTH * HEIGHT + 1;
	if ((e->logos = (t_img*)malloc(sizeof(t_img) * NB_LOGOS)) == NULL)
		ft_errexit("malloc failed", RED, MALLOC_FAILED);
	if ((e->color = (t_img*)malloc(sizeof(t_img) * 10)) == NULL)
		ft_errexit("malloc failed", RED, MALLOC_FAILED);
	e->teams = NULL;
	e->end_team = NULL;
	e->team_ind = -1;
	return (e);
}

int					main(int ac, char **av)
{
	t_env	*e;

	if (ac != 2)
		ft_errexit("Error\nUsage: aff_lemipc lemipc path", \
		NOCOLOR, FTOK_FAILED);
	e = init_env();
	init_ipcs(e, av[1], 0);
	op_sem(e, LOCK);
	e->mapcpy = ft_strdup(e->cdata);
	register_teams(e);
	op_sem(e, UNLOCK);
	launch_mlx(e);
	return (0);
}
