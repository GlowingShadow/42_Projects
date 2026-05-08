/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:54:37 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:54:41 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int			ft_count_ways(t_env *e, t_way *ways)
{
	int	n;

	n = 0;
	while (ways != NULL)
	{
		ways->id = n;
		n++;
		ways = ways->next;
	}
	if (e->prints == 0)
		return (n);
	COLOR(GREEN);
	ft_putnbr(n);
	ft_putstr(" ways listed\n\n");
	COLOR(NOCOLOR);
	return (n);
}

void		set_distances_from_end(t_room *room, int distance)
{
	t_tube	*ptr;

	ptr = room->tubes;
	if (room->room_left > distance || room->room_left == -1)
	{
		room->room_left = distance;
		while (ptr != NULL)
		{
			set_distances_from_end(ptr->room_dest, distance + 1);
			ptr = ptr->next;
		}
	}
}
