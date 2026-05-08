/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:54:24 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:54:25 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	print_found(t_env *e, int *set_tmp, t_matrix matx)
{
	int		x;

	if (e->prints == 0)
		return ;
	ft_putstr_color("\nFound (id):\t", CYAN);
	x = 0;
	while (x < matx.debit)
	{
		ft_putnbr(set_tmp[x]);
		ft_putchar(32);
		x++;
	}
}

void	print_found_amount(t_env *e)
{
	if (e->prints == 1)
	{
		ft_putnbr(e->ways_found);
		ft_putchar(32);
	}
}

void	print_found_simple(t_env *e, t_room *room, int k)
{
	if (e->prints == 1 && k == 1)
	{
		ft_putstr_color(room->name, RED);
		ft_putchar(32);
	}
	if (e->prints == 1 && k == 2)
		ft_putstr_color("end found.\n", CYAN);
}

void	print_map(t_str *map)
{
	t_str	*ptr;

	ptr = map;
	while (ptr != NULL)
	{
		ft_putendl(ptr->str);
		ptr = ptr->next;
	}
	ft_putchar(10);
}
