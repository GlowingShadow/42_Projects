/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 19:37:55 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/13 19:37:56 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			get_size_mini(int sum_piece)
{
	int i;

	i = 2;
	while (i < 60000)
	{
		if (i * i >= sum_piece)
			return (i);
		i++;
	}
	return (0);
}

static inline int	put_piece(char *piece, char *map,
	int size, t_fln t)
{
	int i;
	int	put;

	i = 0;
	put = 0;
	while (i < 16)
	{
		if (piece[i] == '#' && !map[i % 4 + (i / 4) * size])
		{
			if (size - (1 + t.left + i % 4) < 0 || t.lefty + i / 4 >= size)
			{
				return (0);
			}
			map[i % 4 + (i / 4) * size] = t.letter;
			put++;
			if (put == 4)
				return (1);
		}
		i++;
	}
	return (0);
}

static inline void	remove_piece(char *piece, char *map, int size, char letter)
{
	int i;
	int	put;

	i = 0;
	put = 0;
	while (i < 16)
	{
		if (piece[i] != '.' && map[i % 4 + (i / 4) * size] == letter)
		{
			map[i % 4 + (i / 4) * size] = 0;
			put++;
			if (put == 4)
				return ;
		}
		i++;
	}
	return ;
}

static inline int	solve(char tab[27][17], int piecenb, char *map)
{
	int const	sizemax = tab[26][1] * tab[26][1];
	int			i;
	t_fln		fln;

	if (piecenb == tab[26][0])
		return (1);
	i = 0;
	while (i < sizemax)
	{
		fln.letter = piecenb + 'A';
		fln.left = i % tab[26][1];
		fln.lefty = i / tab[26][1];
		if (put_piece(tab[piecenb], map + i, tab[26][1], fln))
			if (solve(tab, piecenb + 1, map))
				return (1);
		remove_piece(tab[piecenb], map + i, tab[26][1], piecenb + 'A');
		i++;
	}
	return (0);
}

void				result(t_env *e)
{
	char map[36 * 16];

	e->pieces[26][1] = get_size_mini(e->pieces[26][0] * 4);
	ft_bzero(map, 16 * 36);
	while (!solve(e->pieces, 0, map))
	{
		ft_bzero(map, 36 * 16);
		e->pieces[26][1]++;
	}
	print_result(map, e->pieces[26][1]);
}
