/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_pile_bulle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 06:29:02 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/09 06:38:03 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_pile2(t_env *e)
{
	t_small	sm;

	while (ft_check_rsort_int_tab(e->pile2.tab, e->pile2.size) == 0)
	{
		if ((e->pile2.tab)[0] < (e->pile2.tab)[1])
		{
			ft_swap(&(e->pile2));
			(e->count)++;
			if (ft_check_rsort_int_tab(e->pile2.tab, e->pile2.size) == 0)
			{
				sm = ft_find_bigger_int(e->pile2.tab, e->pile2.size);
				ft_put_smaller_on_top2(sm, e);
			}
		}
		else
		{
			ft_rot(&(e->pile2));
			e->count++;
		}
	}
}

void	ft_sort_pile1(t_env *e)
{
	t_small sm;

	while (ft_check_sort_int_tab(e->pile1.tab, e->pile1.size) == 0)
	{
		if ((e->pile1.tab)[0] > (e->pile1.tab)[1])
		{
			ft_swap(&(e->pile1));
			(e->count)++;
			if (ft_check_sort_int_tab(e->pile1.tab, e->pile1.size) == 0)
			{
				sm = ft_find_smaller_int(e->pile1.tab, e->pile1.size);
				ft_put_smaller_on_top1(sm, e);
			}
		}
		else
		{
			ft_rot(&(e->pile1));
			e->count++;
		}
	}
}
