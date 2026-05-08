/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_strchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:53:14 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:53:16 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		ft_int_strchr(int *istr, int size, int n)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (istr[i] == n)
			return (i);
		i++;
	}
	return (-1);
}

t_int	*ft_int_listchr(t_int *start, int n)
{
	t_int	*ptr;

	ptr = start;
	while (ptr != NULL)
	{
		if (n == ptr->room_id)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

t_int	*ft_int_listdup(t_int *start)
{
	t_int	*list;
	t_int	*ptr;
	t_int	*ptr2;
	t_int	*prev;

	list = (t_int*)malloc(sizeof(t_int));
	ptr2 = list;
	ptr = start;
	while (ptr != NULL)
	{
		if (ptr2 == NULL)
		{
			ptr2 = (t_int*)malloc(sizeof(t_int));
			prev->next = ptr2;
		}
		ptr2->id = ptr->id;
		ptr2->size = ptr->size;
		ptr2->room_id = ptr->room_id;
		ptr2->next = NULL;
		prev = ptr2;
		ptr = ptr->next;
		ptr2 = ptr2->next;
	}
	return (list);
}
