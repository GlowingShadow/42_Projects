/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 09:34:21 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/16 17:57:47 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_good(char s, char o)
{
	if (o == '0' && (s == '0' || s == '8'))
		return (0);
	if (o == '1' && (s == '1' || s == '8'))
		return (0);
	if (o == '2' && s == '6')
		return (0);
	if (o == '3' && s == '7')
		return (0);
	if (o == '4' && s == '5')
		return (0);
	if (o == '5' && s == '4')
		return (0);
	if (o == '6' && s == '2')
		return (0);
	if (o == '7' && s == '3')
		return (0);
	if (o == '8' && (s == '8' || s == '0' || s == '1'))
		return (0);
	if (o == '9' && s == ':')
		return (0);
	if (o == ':' && s == '9')
		return (0);
	return (1);
}

int	ft_check_ops(t_env *e, char **str)
{
	char	*ops;
	t_itab	tmp1;
	t_itab	tmp2;

//ft_putstr(*str);
	tmp1 = ft_int_tab_dup(e->pile1.tab, e->pile1.size);
	tmp2 = ft_int_tab_dup(e->pile2.tab, e->pile2.size);
	ops = ft_read_op(*str);
	if (ft_check_mvt(tmp1, tmp2, ops) == 1)
	{
		e->found = ft_strdup(*str);
		return (1);
	}
//	free(ops);
//	free(tmp1.tab);
//	free(tmp2.tab);
//ft_putstr("_\n");
	return (0);
}

int		ft_next_index(t_env *e, char *str, int ind, int op_n)
{
	int		i;

	i = 0;
	while (i < e->oplen)
	{
		if (ind > 0)
			while ((ft_is_good(str[ind - 1], (e->op)[i])) == 0 && i < e->oplen)
				i++;
		if (i >= e->oplen)
			break ;
		str[ind] = (e->op)[i];
		if (ind == op_n - 1)
		{
			if (ft_check_ops(e, &str) == 1)
				return (1);
		}
		else
		{
			if (ft_next_index(e, str, ind + 1, op_n) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

int		ft_brute_force(t_env *e, int op_max)
{
	char	*buf;
	int		i;

	i = 1;
	buf = ft_strnew(op_max + 1);
	while (i <= op_max)
	{
		if (ft_next_index(e, buf, 0, i) == 1)
		{
			return (1);
		}
		i++;
	}
//	free(buf);
	return (0);
}

t_mvt	ft_algo3(t_env e, int i)
{
	if (ft_check_sort_int_tab(e.pile1.tab, e.pile1.size) == 1)
	{
		e.mvt.str = ft_strdup("");
		e.mvt.count = 0;
		return (e.mvt);
	}
	e.op = "0123456789:";
	e.oplen = ft_strlen(e.op);
	e.found = ft_strdup("");
	ft_brute_force(&e, i);
	if (ft_strlen(e.found) > 0)
	{
		e.mvt.str = ft_read_op(e.found);
		e.mvt.count = ft_strlen(e.found);
		return (e.mvt);
	}
	e.mvt.count = 2147483647;
	e.mvt.str = ft_strdup("not found");
	return (e.mvt);
}
