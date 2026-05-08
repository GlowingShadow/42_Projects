/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 16:58:35 by REDACTED          #+#    #+#             */
/*   Updated: 2016/07/01 17:02:01 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

static void		orbit(t_env *e, int idist, int jdist)
{
	if (idist == 1 && jdist == -1)
		move_up(e);
	else if (idist == 0 && jdist == -1)
		move_up(e);
	else if (idist == -1 && jdist == -1)
		move_right(e);
	else if (idist == -1 && jdist == 0)
		move_right(e);
	else if (idist == -1 && jdist == 1)
		move_down(e);
	else if (idist == 0 && jdist == 1)
		move_down(e);
	else if (idist == 1 && jdist == 1)
		move_left(e);
	else if (idist == 1 && jdist == 0)
		move_left(e);
}

void			approch(t_env *e, int idist, int jdist)
{
	int		(*moves[2])(t_env *);

	moves[0] = move_down;
	if (idist > 0)
		moves[0] = move_up;
	moves[1] = move_right;
	if (jdist > 0)
		moves[1] = move_left;
	if (ft_abs(idist) >= ft_abs(jdist))
	{
		if (idist == 0 || moves[0](e) == -1)
			if (moves[1](e) == -1)
				moves[0](e);
	}
	else
	{
		if (jdist == 0 || moves[1](e) == -1)
			if (moves[0](e) == -1)
				moves[1](e);
	}
}

void			chase_target(t_env *e)
{
	int		idist;
	int		jdist;

	idist = e->i - e->target->i;
	jdist = e->j - e->target->j;
	if (ft_abs(jdist) <= 1 && ft_abs(idist) <= 1)
		orbit(e, idist, jdist);
	else
		approch(e, idist, jdist);
}

void			move_random(t_env *e)
{
	int		r;

	r = rand() * rand() - rand();
	if (r < 0)
	{
		if (r == -2147483648)
			r++;
		r = -r;
	}
	if (r % 4 == 0 && get_player(e, e->i - 1, e->j) == -1)
		move_up(e);
	else if (r % 4 == 1 && get_player(e, e->i + 1, e->j) == -1)
		move_down(e);
	else if (r % 4 == 2 && get_player(e, e->i, e->j - 1) == -1)
		move_left(e);
	else if (r % 4 == 3 && get_player(e, e->i, e->j + 1) == -1)
		move_right(e);
}
