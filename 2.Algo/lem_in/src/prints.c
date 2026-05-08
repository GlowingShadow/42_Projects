/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:54:17 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:54:19 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	ft_print_info(t_env *e, char *msg)
{
	if (e->prints == 1)
	{
		ft_putstr(msg);
	}
}

void	printistr(t_env *e, int *istr, int size)
{
	int	i;

	i = 0;
	COLOR(RED);
	while (i < size)
	{
		ft_putstr(get_room(e, istr[i])->name);
		ft_putchar(32);
		i++;
	}
	COLOR(NOCOLOR);
}

void	print_ways(t_env *e)
{
	t_way	*ptr;

	if (e->prints == 0)
		return ;
	ft_putstr("WAYS:\nsize");
	ft_putstr_color(" rooms name\n", RED);
	ptr = e->ways;
	while (ptr != NULL)
	{
		ft_putnbr(ptr->size);
		printistr(e, ptr->istr, ptr->size);
		ft_putchar(10);
		ptr = ptr->next;
	}
}

void	print_combis(t_env *e)
{
	int			x;

	if (e->prints == 0)
		return ;
	ft_putchar(10);
	x = 0;
	COLOR(CYAN);
	ft_putnbr(e->combi->total_len);
	ft_putchar(32);
	COLOR(NOCOLOR);
	while (x < e->combi->ways->size)
	{
		ft_putnbr(e->combi->ways->istr[x]);
		ft_putchar(32);
		x++;
	}
	ft_putchar(10);
}

void	print_matrix(t_env *e, char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_putstr("Matrix describing if ways (listed with their ID here)");
	ft_putstr(" are crossing or not\n");
	ft_putstr_color("\t0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17\n", GREEN);
	while (i < e->ways_amount)
	{
		j = 0;
		COLOR(GREEN);
		ft_putnbr(i);
		ft_putchar('\t');
		COLOR(NOCOLOR);
		while (j < e->ways_amount)
		{
			ft_putnbr(tab[i][j]);
			ft_putchar(32);
			j++;
		}
		ft_putchar(10);
		i++;
	}
}
