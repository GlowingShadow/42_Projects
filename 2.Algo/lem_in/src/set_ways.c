/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ways.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 20:35:26 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:55:04 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		new_way(t_env *e, int way[BUFF])
{
	int		memsize;

	e->ways_tested++;
	way[SIZE] = 1;
	way[ID] = e->ways_tested;
	memsize = e->rooms_amount - 1;
	while (memsize >= 0)
	{
		way[memsize] = -1;
		memsize--;
	}
	way[0] = e->start_room->id;
}

static void		new_branch(t_env *e, int way[BUFF], t_room *room)
{
	t_tube	*tube;
	int		way_tmp[BUFF];
	int		cpy[BUFF];

	ft_memcpy((void*)cpy, (void*)way, sizeof(int) * (BUFF + 1));
	tube = room->tubes;
	while (tube != NULL)
	{
		if (tube->room_dest->id != way[way[SIZE] - 2] \
			&& ft_int_strchr(way, way[SIZE], tube->room_dest->id) == -1)
		{
			if (tube->next == NULL)
				next_room(e, way, tube->room_dest);
			else
			{
				e->ways_tested++;
				ft_memcpy((void*)way_tmp, (void*)way, sizeof(int) * (BUFF + 1));
				way_tmp[ID] = e->ways_tested;
				next_room(e, way_tmp, tube->room_dest);
			}
		}
		tube = tube->next;
	}
}

static int		check_bad_way(t_env *e, int way[BUFF], t_room *room, int *cpy)
{
	t_tube		*ptr;

	ft_memcpy((void*)cpy, (void*)way, sizeof(int) * (BUFF + 1));
	cpy[cpy[SIZE]] = room->id;
	cpy[SIZE] += 1;
	ptr = room->tubes;
	if (room->tubes_amount >= 2)
		while (ptr != NULL)
		{
			if (ptr->room_dest->id != cpy[cpy[SIZE] - 2] && \
				ft_int_strchr(cpy, cpy[SIZE], ptr->room_dest->id) != -1)
				return (-1);
			ptr = ptr->next;
		}
	return (0);
}

void			next_room(t_env *e, int way[BUFF], t_room *room)
{
	int			cpy[BUFF];

	if (check_bad_way(e, way, room, cpy) == -1)
		return ;
	if (room->id == e->end_room->id)
	{
		add_way2(e, cpy);
		e->ways_found++;
		print_found_amount(e);
		return ;
	}
	else if (room->tubes_amount == 1)
		return ;
	else if (room->tubes_amount == 2)
	{
		if (room->tubes->room_dest->id == cpy[cpy[SIZE] - 2])
			room = room->tubes->next->room_dest;
		else
			room = room->tubes->room_dest;
		next_room(e, cpy, room);
		return ;
	}
	new_branch(e, cpy, room);
}

void			set_ways(t_env *e)
{
	int		ways[e->start_room->tubes_amount][BUFF];
	t_tube	*tube;
	int		i;

	tube = e->start_room->tubes;
	new_way(e, ways[0]);
	i = 0;
	while (tube != NULL)
	{
		next_room(e, ways[i], tube->room_dest);
		tube = tube->next;
		i++;
		if (tube != NULL)
		{
			e->ways_tested++;
			ft_memcpy((void*)ways[i], (void*)ways[0], sizeof(int) * (BUFF + 1));
			ways[i][ID] = e->ways_tested;
		}
	}
}
