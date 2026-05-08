/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:54:31 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:54:33 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		del_tube(t_env *e, int dest_id, t_room *room)
{
	t_tube		*ptr;
	t_tube		*previous;

	previous = NULL;
	ptr = room->tubes;
	while (ptr->room_dest->id != dest_id)
	{
		previous = ptr;
		ptr = ptr->next;
		if (ptr == NULL)
			exit(DATA_CORRUPT);
	}
	if (previous == NULL)
		room->tubes = (ptr->next == NULL ? NULL : ptr->next);
	else
		previous->next = (ptr->next == NULL ? NULL : ptr->next);
	free(ptr);
	if ((room->tubes_amount -= 1) == 1 \
		&& room->id != e->end_room->id && room->id != e->start_room->id)
	{
		del_tube(e, room->id, ptr->room_dest);
		free(room->tubes);
		room->tubes = NULL;
		room->tubes_amount = 0;
	}
}

static void		delete_deadends(t_env *e)
{
	t_room	*ptr;

	ft_print_info(e, "Deleting dead-ends...");
	ptr = e->rooms;
	while (ptr != NULL)
	{
		if (ptr->id != e->start_room->id && ptr->id != e->end_room->id \
			&& ptr->tubes_amount == 1)
		{
			del_tube(e, ptr->id, ptr->tubes->room_dest);
			free(ptr->tubes);
			ptr->tubes = NULL;
			ptr->tubes_amount = 0;
			delete_deadends(e);
			return ;
		}
		ptr = ptr->next;
	}
	ft_print_info(e, " Done\n");
}

static void		check_debit(t_env *e)
{
	t_tube		*ptr;

	ptr = e->start_room->tubes;
	while (ptr != NULL)
	{
		if (ptr->room_dest->id == e->end_room->id)
		{
			e->start_room->room_left = 1;
			e->neighbour = 1;
			e->debit = 1;
			return ;
		}
		ptr = ptr->next;
	}
	e->debit = e->start_room->tubes_amount;
	if (e->end_room->tubes_amount < e->debit)
		e->debit = e->end_room->tubes_amount;
	delete_deadends(e);
	set_distances_from_end(e->end_room, 0);
}

static void		checks(t_env *e, char *line, char *error)
{
	if (line != NULL)
		ft_putstr(line);
	if (error != NULL)
		ft_putstr_color(error, RED);
	ft_print_info(e, "\nResolving with current data.\n");
	if (e->start_room == NULL || e->end_room == NULL)
		ft_errexit("ERROR: Start room or End room not set.", NO_START_END);
	check_debit(e);
	if (e->start_room->room_left == -1)
		ft_errexit("ERROR: Start and End rooms not linked.", NO_WAY);
}

void			ft_resolve(t_env *e, char *line, char *error)
{
	checks(e, line, error);
	fuck(e);
	if ((e->debit > 1 && e->neighbour == 0 && e->algo != 2) || e->algo == 1)
	{
		if (e->rooms_amount > 200)
			ft_errexit("Too many rooms for this algorithm.", ROOM_OVERFLOW);
		ft_print_info(e, "Number of ways found: ");
		set_ways(e);
		e->ways = sort_list(e, e->ways);
		print_ways(e);
		e->ways_amount = ft_count_ways(e, e->ways);
		algo_best(e);
		print_combis(e);
		clear_ways(e);
	}
	else if (e->neighbour != 1 || e->algo == 2)
		algo_simple(e);
	else if (e->neighbour == 1)
		instant_move(e);
	else
		ft_errexit("Error: unknow case\n", ERROR);
	move(e);
}
