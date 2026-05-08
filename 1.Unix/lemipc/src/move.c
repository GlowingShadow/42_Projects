/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 17:01:01 by REDACTED          #+#    #+#             */
/*   Updated: 2016/07/01 17:01:03 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

int			move_up(t_env *e)
{
	int		newpos;

	if (get_player(e, e->i - 1, e->j) != -1)
		return (-1);
	newpos = POS(e->i - 1, e->j);
	CMAP[e->pos] = VOID_CHAR;
	CMAP[newpos] = e->team;
	e->i = e->i - 1;
	e->pos = newpos;
	return (OK);
}

int			move_down(t_env *e)
{
	int		newpos;

	if (get_player(e, e->i + 1, e->j) != -1)
		return (-1);
	newpos = POS(e->i + 1, e->j);
	CMAP[e->pos] = VOID_CHAR;
	CMAP[newpos] = e->team;
	e->i = e->i + 1;
	e->pos = newpos;
	return (OK);
}

int			move_left(t_env *e)
{
	int		newpos;

	if (get_player(e, e->i, e->j - 1) != -1)
		return (-1);
	newpos = POS(e->i, e->j - 1);
	CMAP[e->pos] = VOID_CHAR;
	CMAP[newpos] = e->team;
	e->j = e->j - 1;
	e->pos = newpos;
	return (OK);
}

int			move_right(t_env *e)
{
	int		newpos;

	if (get_player(e, e->i, e->j + 1) != -1)
		return (-1);
	newpos = POS(e->i, e->j + 1);
	CMAP[e->pos] = VOID_CHAR;
	CMAP[newpos] = e->team;
	e->j = e->j + 1;
	e->pos = newpos;
	return (OK);
}

void		move(t_env *e)
{
	op_sem(e, e->map_mem, LOCK);
	check_dead(e);
	if (e->target->pos != -1)
	{
		if (e->ia == 2)
		{
			if (TEAM_LEFT > 2)
				approch(e, e->i - e->hidepos->i, e->j - e->hidepos->j);
			else
				chase_target(e);
		}
		else if (e->ia == 1)
			chase_target(e);
		else
			move_random(e);
	}
	op_sem(e, e->map_mem, UNLOCK);
}
