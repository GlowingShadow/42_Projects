/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 11:46:51 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/15 21:59:34 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_push_small_numbers(t_env *e, int mid, int i)
{
	int	len;

	len = e->pile2.size + (e->pile1.size) / (i + 1);
	while (e->pile2.size != len)
	{
		if (ft_check_sort_int_tab(e->pile1.tab, e->pile1.size) == 1 && \
				e->pile2.size == 0)
			break ;
		if ((e->pile1.tab)[0] <= mid)
			ft_pb(e);
		else
			ft_ra(e);
	}
}

int			ft_find_middle(t_env e, int i)
{
	t_itab	cpy;
	int		mid;

	(void)i;
	cpy = ft_int_tab_dup(e.pile1.tab, e.pile1.size);
	ft_sort_int_tab(cpy.tab, cpy.size);
	mid = (cpy.tab)[(cpy.size) / (i + 1) - 1];
	return (mid);
}

void		ft_push_all_in(t_env *e, int i)
{
	if (i == 1)
		while ((e->pile2.size) != 0)
			ft_pa(e);
	else if (i == 2)
		while ((e->pile1.size) != 0)
			ft_pb(e);
}

void		ft_launch(t_env *e, int *i)
{
	e->mvt.str = ft_strnew(200000000);
	e->start = 0;
	e->mvt.count = 0;
	*i = e->ac / 100;
	*i == 0 ? (*i)++ : (void)i;
}

t_mvt		ft_algo2(t_env e, t_small sm, int i, int mid)
{
	ft_launch(&e, &i);
	while (ft_check_sort_int_tab(e.pile1.tab, e.pile1.size) != 1)
	{
		while (0 < i)
		{
			mid = ft_find_middle(e, i);
			ft_push_small_numbers(&e, mid, i);
			i--;
		}
		if (ft_check_sort_int_tab(e.pile1.tab, e.pile1.size) == 1 && \
				e.pile2.size == 0)
			;
		else
		{
			ft_push_all_in(&e, 2);
			while (e.pile2.size != 0)
			{
				sm = ft_find_bigger_int(e.pile2.tab, e.pile2.size);
				ft_put_smaller_on_top2(sm, &e);
				ft_pa(&e);
			}
		}
	}
	if (ft_check_sort_int_tab(e.pile1.tab, e.pile1.size) == 1)
		ft_putstr("Algo2 OK\n");
	else
		ft_putstr("Algo2 Fail\n");
	return (e.mvt);
}
