/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 10:02:19 by exam              #+#    #+#             */
/*   Updated: 2015/03/05 10:39:56 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>

int		is_sorted(t_list *lst)
{
	while (lst->next != NULL)
	{
		if (lst->data > lst->next->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*i;
	int		tmp;

	while (is_sorted(lst) != 1)
	{
		i = lst;
		while (i->next != NULL)
		{
			if (cmp(i->data, i->next->data) == 0)
			{
				tmp = i->data;
				i->data = i->next->data;
				i->next->data = tmp;
			}
			i = i->next;
		}
	}
	i = lst;
	return (i);
}
