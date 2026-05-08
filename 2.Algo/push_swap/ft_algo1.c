/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 16:54:49 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/17 20:47:47 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_smaller_on_top2(t_small sm, t_env *e)
{
	int	j;

	j = e->pile2.size;
	if (sm.i <= (j / 2))
		while (0 < sm.i)
		{
			if (sm.i == 1)
			{
				ft_sb(e);
				(sm.i)--;
			}
			else
			{
				ft_rb(e);
				(sm.i)--;
			}
		}
	else
		while (sm.i < j)
		{
			ft_rrb(e);
			(sm.i)++;
		}
}

void	ft_put_smaller_on_top1(t_small sm, t_env *e)
{
	int	j;

	j = e->pile1.size;
	if (sm.i <= (j / 2))
		while (0 < sm.i)
		{
			if (sm.i == 1)
			{
				ft_sa(e);
				(sm.i)--;
			}
			else
			{
				ft_ra(e);
				(sm.i)--;
			}
		}
	else
		while (sm.i < j)
		{
			ft_rra(e);
			(sm.i)++;
		}
}

t_mvt	ft_algo1(t_env e)
{
	t_small	sm;

	e.mvt.str = ft_strnew(200000000);
	e.start = 0;
	e.mvt.count = 0;
	while (ft_check_sort_int_tab(e.pile1.tab, e.pile1.size) == 0)
	{
		sm = ft_find_smaller_int(e.pile1.tab, e.pile1.size);
		ft_put_smaller_on_top1(sm, &e);
		if (ft_check_sort_int_tab(e.pile1.tab, e.pile1.size) == 0)
			ft_pb(&e);
	}
	while ((e.pile2.size) != 0)
		ft_pa(&e);
	if (ft_check_sort_int_tab(e.pile1.tab, e.pile1.size) == 1)
		ft_putstr("Algo1 OK\n");
	else
		ft_putstr("Algo1 Fail\n");
	return (e.mvt);
}
