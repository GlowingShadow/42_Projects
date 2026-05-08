/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_tubes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:56:29 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:56:30 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int		are_start_end(t_env *e, t_room *room1, t_room *room2)
{
	if (room1->id != e->start_room->id && room1->id != e->end_room->id)
		return (0);
	if (room2->id != e->start_room->id && room2->id != e->end_room->id)
		return (0);
	return (1);
}

static int		islink(t_room *room1, t_room *room2)
{
	t_tube		*ptr;

	ptr = room1->tubes;
	while (ptr != NULL)
	{
		if (ptr->room_dest->id == room2->id)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

static t_tube	*new_tube(t_room *room)
{
	t_tube	*tube;

	tube = (t_tube*)malloc(sizeof(t_tube));
	tube->room_dest = room;
	tube->next = NULL;
	return (tube);
}

static void		add_tube2(t_room *start, t_room *dest)
{
	t_tube	*tmp;

	if (start->tubes_amount == 0)
		start->tubes = new_tube(dest);
	else
	{
		tmp = start->tubes;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_tube(dest);
	}
	start->tubes_amount += 1;
}

int				add_tube(t_env *e, char *line)
{
	t_room	*start;
	t_room	*dest;

	if ((start = find_room(e, line)) != NULL && \
		(dest = find_room(e, line + ft_strlen(line) + 1)) != NULL)
	{
		if ((islink(start, dest) == 0 && islink(dest, start) == 0) \
			|| are_start_end(e, start, dest) == 1)
		{
			add_tube2(start, dest);
			add_tube2(dest, start);
		}
	}
	else
		return (-1);
	return (0);
}
