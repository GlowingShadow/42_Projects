/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:55:21 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:55:23 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int		check(t_way *list)
{
	t_way	*ptr;

	ptr = list;
	while (ptr->next != NULL)
	{
		if (ptr->size > ptr->next->size)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

t_int			*lst_swap(t_int *lst, t_int *prev1, t_int *prev2, t_int *ptr1)
{
	t_int	*ptr2;
	t_int	*tmp;

	ptr2 = prev2->next_way;
	if (prev1 == NULL)
	{
		tmp = ptr2->next_way;
		lst = ptr2;
		prev2->next_way = ptr1;
		ptr2->next_way = ptr1->next_way;
		ptr1->next_way = tmp;
	}
	else
	{
		tmp = ptr2->next_way;
		prev1->next_way = ptr2;
		prev2->next_way = ptr1;
		ptr2->next_way = ptr1->next_way;
		ptr1->next_way = tmp;
	}
	return (lst);
}

static t_way	*select_ways(t_way *ways, t_way *pointers[4], int minmax[2])
{
	while (minmax[0] <= minmax[1])
	{
		pointers[1] = ways;
		pointers[0] = NULL;
		while (pointers[1] != NULL)
		{
			if (pointers[1]->size == minmax[0])
			{
				if (pointers[0] == NULL)
					ways = pointers[1]->next;
				else
					pointers[0]->next = pointers[1]->next;
				if (pointers[2] == NULL)
					pointers[3] = pointers[1];
				else
					pointers[2]->next = pointers[1];
				pointers[2] = pointers[1];
			}
			else
				pointers[0] = pointers[1];
			pointers[1] = pointers[1]->next;
		}
		(minmax[0])++;
	}
	return (pointers[3]);
}

t_way			*sorting(t_env *e, t_way *ways, t_way *ptr, int *minmax)
{
	t_way	*pointers[4];

	pointers[0] = NULL;
	pointers[1] = NULL;
	pointers[2] = NULL;
	pointers[3] = NULL;
	ptr = select_ways(ways, pointers, minmax);
	ft_print_info(e, "\tcheck...");
	if (check(ptr) == 0)
		exit(DATA_CORRUPT);
	ft_print_info(e, " Ok.\n\n");
	return (ptr);
}

t_way			*sort_list(t_env *e, t_way *ways)
{
	t_way	*ptr;
	int		minmax[2];

	ptr = ways;
	minmax[0] = ptr->size;
	minmax[1] = ptr->size;
	ft_print_info(e, "\nCheck ways's len min/max: ");
	while (ptr != NULL)
	{
		if (ptr->size > minmax[1])
			minmax[1] = ptr->size;
		if (ptr->size < minmax[0])
			minmax[0] = ptr->size;
		ptr = ptr->next;
	}
	if (e->prints == 1)
	{
		ft_putnbr(minmax[0]);
		ft_putchar('-');
		ft_putnbr(minmax[1]);
		ft_putchar(10);
	}
	return (sorting(e, ways, ptr, minmax));
}
