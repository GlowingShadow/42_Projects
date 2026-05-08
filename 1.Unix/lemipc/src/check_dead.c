/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 16:59:31 by REDACTED          #+#    #+#             */
/*   Updated: 2016/07/01 16:59:36 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

static void		check_last_ipcs(t_env *e)
{
	int		i;

	i = 0;
	while (i < MAP_SIZE)
	{
		if (CMAP[i] != VOID_CHAR)
		{
			op_sem(e, e->map_mem, UNLOCK);
			return ;
		}
		i++;
	}
	op_sem(e, e->map_mem, UNLOCK);
	close_ipcs(e->map_mem, -1);
}

static void		self_destruct(t_env *e)
{
	printf("DEAD: %d\tmsgq_id: %d\t%d %d", e->team, e->msgq_id, e->i, e->j);
	CMAP[e->pos] = VOID_CHAR;
	if (LEADER == e->msgq_id)
		LEADER = -1;
	else
		send_msg(e->leader_msgq_id, MSG_DEAD, ft_itoa(e->msgq_id));
	if (msgctl(e->msgq_id, IPC_RMID, 0) == -1)
		close_ipcs(e->team_mem, e->msgq_id);
	op_sem(e, e->team_mem, LOCK);
	PLAYER_LEFT -= 1;
	printf("\tleft: %d\n", PLAYER_LEFT);
	if (PLAYER_LEFT == 0)
	{
		close_ipcs(e->team_mem, e->msgq_id);
		TEAM_LEFT -= 1;
	}
	else
		op_sem(e, e->team_mem, UNLOCK);
	check_last_ipcs(e);
	if (shmdt(e->map_mem->data) == -1)
		ft_errexit("shmdt failed", RED, SHMDT_FAILED);
	free(e);
	exit(PLAYER_DEAD);
}

int				get_player(t_env *e, int i, int j)
{
	int		pos;

	if (i < 0 || i >= HEIGHT || j < 0 || j >= WIDTH)
		return (-2);
	pos = POS(i, j);
	if (CMAP[pos] != VOID_CHAR)
		return (CMAP[pos]);
	return (-1);
}

static void		check_around(t_env *e, int *players)
{
	int		i;
	int		j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (players[i] >= 0 && j < 7)
		{
			if (i != j && players[j] >= 0 && players[j] == players[i] \
				&& players[i] != e->team)
				self_destruct(e);
			j++;
		}
		i++;
	}
}

void			check_dead(t_env *e)
{
	int		i;
	int		j;
	int		players[8];

	i = e->i;
	j = e->j;
	players[0] = get_player(e, i - 1, j + 0);
	players[1] = get_player(e, i - 1, j - 1);
	players[2] = get_player(e, i - 1, j + 1);
	players[3] = get_player(e, i + 1, j + 0);
	players[4] = get_player(e, i + 1, j - 1);
	players[5] = get_player(e, i + 1, j + 1);
	players[6] = get_player(e, i + 0, j + 1);
	players[7] = get_player(e, i + 0, j - 1);
	check_around(e, players);
}
