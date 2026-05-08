/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_best2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:52:02 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:52:04 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		free_ways(t_env *e, t_way *previous)
{
	t_way		*ptr;
	t_way		*tmp;

	ptr = e->ways;
	while (ptr != NULL)
	{
		if (ft_int_strchr(e->combi->ways->istr, e->combi->ways->size, \
			ptr->id) == -1)
		{
			free(ptr->istr);
			free(ptr->istr2);
			tmp = ptr;
			ptr = ptr->next;
			free(tmp);
			if (previous == NULL)
				e->ways = ptr;
			else
				previous->next = ptr;
		}
		else
		{
			previous = ptr;
			ptr = ptr->next;
		}
	}
}

void			clear_ways(t_env *e)
{
	t_way		*ptr;
	int			id;

	free_ways(e, NULL);
	ptr = e->ways;
	id = 0;
	while (ptr != NULL)
	{
		if (e->prints == 1)
		{
			ft_putnbr(id);
			printistr(e, ptr->istr, ptr->size);
			ft_putchar(10);
		}
		ptr->id = id;
		ptr = ptr->next;
		id++;
	}
	e->ways_amount = id;
	if (e->prints == 1)
		ft_putchar(10);
}

int				are_crossing(t_way *way1, t_way *way2)
{
	int	i;

	i = 1;
	while (i < way1->size - 1)
	{
		if (way2->istr2[way1->istr[i]] == 1)
			return (1);
		i++;
	}
	return (0);
}

char			**matrix(t_env *e, t_way *iways[WAYS_AMOUNT])
{
	char	**tab;
	int		i;
	int		j;

	tab = (char**)malloc(sizeof(char*) * (e->ways_amount + 1));
	i = e->ways_amount - 1;
	while (i >= 0)
	{
		j = i;
		tab[i] = (char*)malloc(sizeof(char) * (e->ways_amount + 1));
		while (j < e->ways_amount)
		{
			tab[i][j] = (i == j) ? 1 : are_crossing(iways[i], iways[j]);
			tab[j][i] = tab[i][j];
			j++;
		}
		tab[i][j] = 0;
		i--;
	}
	tab[e->ways_amount] = NULL;
	return (tab);
}

void			reset(int *istr, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		istr[i] = -1;
		i++;
	}
}
