/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 16:59:51 by REDACTED          #+#    #+#             */
/*   Updated: 2016/07/01 16:59:53 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

static t_int		*register_team(t_int *registre, int player)
{
	t_int	*new_team;
	t_int	*ptr;

	ptr = registre;
	while (ptr != NULL)
	{
		if (ptr->alive == player)
			return (NULL);
		ptr = ptr->next;
	}
	if ((new_team = (t_int*)malloc(sizeof(t_int))) == NULL)
		ft_errexit("malloc failed", RED, MALLOC_FAILED);
	new_team->alive = player;
	new_team->msgq_id = 0;
	new_team->next = NULL;
	return (new_team);
}

void				grep_teams(t_env *e, t_int *registre, char *data)
{
	int		x;
	t_int	*ptr;

	x = 0;
	op_sem(e, e->map_mem, LOCK);
	while (x < WIDTH * HEIGHT)
	{
		if (data[x] != VOID_CHAR)
			ptr = register_team(registre, data[x]);
		if (ptr != NULL)
		{
			ptr->next = registre;
			registre = ptr;
		}
		x++;
	}
	op_sem(e, e->map_mem, UNLOCK);
	ptr = registre;
	while (ptr != NULL)
	{
		delete_ipcs(ptr->alive, sizeof(int) * TEAM_ADD_SIZE);
		ptr = ptr->next;
	}
	delete_ipcs(0, WIDTH * HEIGHT + INFOS_ADD_SIZE);
	exit(0);
}
