/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:52:13 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:52:17 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		add_way(t_env *e, int *combi, int id)
{
	t_way		*way;
	t_way		*ptr;
	int			i;

	way = (t_way*)malloc(sizeof(t_way));
	way->id = id;
	way->size = e->start_room->room_left + 1;
	way->istr = (int*)malloc(sizeof(int) * way->size);
	ft_memcpy((void*)way->istr, (void*)combi, sizeof(int) * (way->size));
	way->next = NULL;
	way->istr2 = NULL;
	if (e->ways == NULL)
		e->ways = way;
	else
	{
		i = 1;
		ptr = e->ways;
		while (ptr->next != NULL)
		{
			i++;
			ptr = ptr->next;
		}
		(i != id) ? ft_errexit("fkit\n", DATA_CORRUPT) : NULL;
		ptr->next = way;
	}
}

static void		write_way_dist(t_env *e, int way_id, int n, t_room *room)
{
	t_tube		*shorter;
	int			combi[e->start_room->room_left + 1];

	room = e->start_room;
	while (room->id != e->end_room->id)
	{
		print_found_simple(e, room, 1);
		combi[n] = room->id;
		shorter = room->tubes;
		while (shorter != NULL && (shorter->room_dest->room_left >= \
			room->room_left || shorter->room_dest->way_id != -1))
			shorter = shorter->next;
		if (shorter == NULL || ((shorter->room_dest->way_id != -1 || \
			room->room_left <= shorter->room_dest->room_left) \
			&& shorter->room_dest->id != e->end_room->id))
			return ;
		room = shorter->room_dest;
		(room->way_id != -1) ? ft_errexit("fk\n", DATA_CORRUPT) : NULL;
		if (room->id != e->end_room->id)
			room->way_id = way_id;
		n++;
	}
	combi[n] = room->id;
	print_found_simple(e, room, 2);
	add_way(e, combi, way_id);
}

static void		reset_distances(t_env *e)
{
	t_room		*ptr;

	ptr = e->rooms;
	while (ptr != NULL)
	{
		if (ptr->way_id == -1)
			ptr->room_left = -1;
		ptr = ptr->next;
	}
}

static void		set_distances_from_end2(t_room *room, int distance)
{
	t_tube	*ptr;

	ptr = room->tubes;
	if (room->room_left > distance || room->room_left == -1 || distance == 0)
	{
		room->room_left = distance;
		while (ptr != NULL)
		{
			if (ptr->room_dest->way_id == -1)
				set_distances_from_end2(ptr->room_dest, distance + 1);
			ptr = ptr->next;
		}
	}
}

void			algo_simple(t_env *e)
{
	int		x;

	ft_print_info(e, "Writing direct ways...\n");
	x = 0;
	write_way_dist(e, x, 0, NULL);
	reset_distances(e);
	x++;
	while (x < e->debit)
	{
		set_distances_from_end2(e->end_room, 0);
		write_way_dist(e, x, 0, NULL);
		reset_distances(e);
		x++;
	}
	ft_print_info(e, " Done.\n\n");
	e->ways_amount = x;
}
