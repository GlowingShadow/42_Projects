/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 18:38:16 by REDACTED          #+#    #+#             */
/*   Updated: 2015/04/04 06:28:49 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	ft_count_degree(char **tab, int *max)
{
	int			i;
	int			tmp;

	i = 2;
	while (tab[i] != NULL)
	{
		if ((tmp = ft_atoi(tab[i] + 2)) > *max)
			*max = tmp;
		if (tab[i] + 1 == NULL)
			break ;
		i += 4;
	}
}

void	ft_stock1(t_env *e, char **tab, int *i)
{
	while (tab[*i] != NULL)
	{
		if (*i == 0 || ft_strcmp(tab[*i - 1], "+") == 0)
			(e->power.itab)[ft_atoi(tab[*i + 2] + 2)] += atof(tab[*i]);
		else if (ft_strcmp(tab[*i - 1], "-") == 0)
			(e->power.itab)[ft_atoi(tab[*i + 2] + 2)] -= atof(tab[*i]);
		else
		{
			ft_putstr_color("Error: invalid sign: ", RED);
			ft_putendl(tab[*i - 1]);
			exit(-1);
		}
		if (tab[*i + 3] == NULL)
			break ;
		*i += 4;
	}
}

void	ft_stock2(t_env *e, char **tab, int *i)
{
	while (tab[*i] != NULL)
	{
		if (tab[*i - 1] == NULL || ft_strcmp(tab[*i - 1], "+") == 0)
			(e->power.itab)[ft_atoi(tab[*i + 2] + 2)] -= atof(tab[*i]);
		else if (ft_strcmp(tab[*i - 1], "-") == 0)
			(e->power.itab)[ft_atoi(tab[*i + 2] + 2)] += atof(tab[*i]);
		else
		{
			ft_putstr_color("Error: invalid sign: ", RED);
			ft_putendl(tab[*i - 1]);
			exit(-1);
		}
		if (tab[*i + 3] == NULL)
			break ;
		*i += 4;
	}
}

void	ft_stock_value(t_env *e, char **tab)
{
	int		i;

	i = 0;
	ft_count_degree(tab, &i);
	ft_count_degree(tab + ft_tablen(tab) + 1, &i);
	e->degree = i;
	e->power.itab = (double*)malloc(sizeof(double) * (i + 1));
	e->power.size = i + 1;
	ft_bzero(e->power.itab, (sizeof(double) * e->power.size));
	i = 0;
	ft_stock1(e, tab, &i);
	i += 4;
	ft_stock2(e, tab, &i);
}
