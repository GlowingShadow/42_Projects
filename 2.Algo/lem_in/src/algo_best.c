/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_best.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:51:49 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:51:54 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int		check_crossing(t_matrix matx, int *set)
{
	int	i;

	i = 0;
	while (set[i] != -1)
	{
		if (matx.tab[set[i]][matx.j] == 1)
			return (1);
		i++;
	}
	return (0);
}

static void		add_combi(t_env *e, int size, int *set, int x)
{
	int		len;

	len = 0;
	while (x < size)
		len += get_way(e, set[x++])->size;
	if (e->combi != NULL && len >= e->combi->total_len)
		return ;
	if (e->combi != NULL)
	{
		free(e->combi->ways->istr);
		free(e->combi->ways);
	}
	else
		e->combi = (t_combi*)malloc(sizeof(t_combi));
	e->combi->ways = (t_istr*)malloc(sizeof(t_istr));
	e->combi->ways->istr = (int*)malloc(sizeof(int) * size);
	e->combi->ways->size = size;
	e->combi->total_len = len;
	x = 0;
	while (x < size)
	{
		e->combi->ways->istr[x] = set[x];
		x++;
	}
}

static void		search_ways(t_env *e, int *set, t_matrix matx)
{
	int		set_tmp[matx.debit];
	int		x;

	while (matx.j < e->ways_amount)
	{
		if (check_crossing(matx, set) == 0)
		{
			ft_memcpy((void*)set_tmp, (void*)set, 4 * (matx.debit + 1));
			x = 0;
			while (set_tmp[x] != -1)
				x++;
			set_tmp[x] = matx.j;
			if (x == matx.debit - 1)
			{
				add_combi(e, matx.debit, set_tmp, 0);
				print_found(e, set_tmp, matx);
				if (e->ways_amount > e->ra_coef)
					return ;
			}
			search_ways(e, set_tmp, matx);
		}
		(matx.j)++;
	}
}

static void		match_ways(t_env *e, char **tab, int debit)
{
	t_matrix	matx;
	int			set[debit];

	if (e->matrix == 1)
		print_matrix(e, tab);
	ft_print_info(e, "\nMax number of ways to be found: ");
	if (e->prints == 1)
	{
		ft_putnbr(debit);
		ft_putchar(10);
	}
	while (e->combi == NULL)
	{
		matx.i = 0;
		matx.j = 0;
		matx.debit = debit;
		matx.tab = tab;
		reset(set, debit);
		search_ways(e, set, matx);
		debit--;
	}
}

void			algo_best(t_env *e)
{
	char	**tab;
	t_way	*iways[WAYS_AMOUNT];
	t_way	*ptr;

	if (e->debit > 1)
	{
		ptr = e->ways;
		while (ptr != NULL)
		{
			iways[ptr->id] = ptr;
			ptr = ptr->next;
		}
		tab = matrix(e, iways);
		match_ways(e, tab, e->debit);
		ft_free_tab(tab);
	}
	else
	{
		e->combi = (t_combi*)malloc(sizeof(t_combi));
		e->combi->ways = (t_istr*)malloc(sizeof(t_istr));
		e->combi->ways->istr = (int*)malloc(sizeof(int));
		e->combi->ways->size = 1;
		e->combi->ways->istr[0] = 0;
		e->combi->total_len = e->ways->size;
	}
}
