/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 19:36:12 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/13 19:36:14 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		move_up(t_env *e)
{
	int		i;

	i = 0;
	while (i < e->pieces[26][0])
	{
		if (ft_strcmp(e->pieces[i], "................") == 0)
			error("Error: invalid piece\n", INVALID_PIECE);
		while (ft_strncmp(e->pieces[i], "....", 4) == 0)
		{
			ft_strcpy(e->pieces[i], e->pieces[i] + 4);
			ft_strcpy(e->pieces[i] + 12, "....");
		}
		i++;
	}
}

static void		move_left(t_env *e, int i)
{
	int		j;
	int		x;

	i = 0;
	while (i < e->pieces[26][0])
	{
		while (e->pieces[i][0] == 46 && e->pieces[i][4] == 46 \
			&& e->pieces[i][8] == 46 && e->pieces[i][12] == 46)
		{
			x = 0;
			while (x < 3)
			{
				j = 0;
				while (j < 4)
				{
					e->pieces[i][j * 4 + x] = e->pieces[i][j * 4 + x + 1];
					if (e->pieces[i][j * 4 + x] == '#')
						e->pieces[i][j * 4 + x + 1] = '.';
					j++;
				}
				x++;
			}
		}
		i++;
	}
}

static void		check(t_env *e)
{
	int		valid;
	int		i;
	int		x;

	i = 0;
	while (i < e->pieces[26][0])
	{
		valid = 0;
		x = 0;
		while (x < 19)
		{
			if (ft_strcmp(e->list[x], e->pieces[i]) == 0)
				valid++;
			x++;
		}
		if (valid != 1)
			error("Error: invalid piece\n", INVALID_PIECE);
		i++;
	}
}

void			adjust_map(t_env *e)
{
	move_up(e);
	move_left(e, 0);
	check(e);
}
