/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_rooms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:56:21 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:56:22 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		ft_check_coo(char *line)
{
	char	*error;

	error = " : Room's coo can't have more than 5 digits.\n";
	if (ft_strlen(line + ft_strlen(line) + 1) > 5 || \
		ft_strlen(line + ft_strlen(line) + 1 + \
		ft_strlen(line + ft_strlen(line) + 1) + 1) > 5)
	{
		line[ft_strlen(line)] = 32;
		line[ft_strlen(line)] = 32;
		COLOR(RED);
		ft_putstr(line);
		ft_putstr(error);
		COLOR(NOCOLOR);
		exit(BAD_ROOM_COO);
	}
}

static void		ft_check_coo2(t_env *e, t_room *new_room)
{
	t_room	*ptr;
	char	*error;

	error = " : Room's coo already taken by another room.\n";
	ptr = e->rooms;
	while (ptr != NULL)
	{
		if (ptr->x == new_room->x && ptr->y == new_room->y)
		{
			COLOR(RED);
			ft_putstr(new_room->name);
			ft_putchar(32);
			ft_putnbr(new_room->x);
			ft_putchar(32);
			ft_putnbr(new_room->y);
			ft_putstr(error);
			COLOR(NOCOLOR);
			exit(BAD_ROOM_COO);
		}
		ptr = ptr->next;
	}
}

static t_room	*new_room(t_env *e, char *line)
{
	t_room	*room;

	room = (t_room*)malloc(sizeof(t_room));
	room->id = e->rooms_amount;
	room->name = ft_strdup(line);
	room->x = ft_atoi(line + ft_strlen(line) + 1);
	room->y = ft_atoi(line + ft_strlen(line) + 1 + \
		ft_strlen(line + ft_strlen(line) + 1) + 1);
	room->ant = NULL;
	room->tubes_amount = 0;
	room->way_id = -1;
	room->room_left = -1;
	room->tubes = NULL;
	room->next = NULL;
	ft_check_coo2(e, room);
	return (room);
}

int				add_room(t_env *e, char *line)
{
	t_room	*tmp;

	if (ft_isdigit_str(line + ft_strlen(line) + 1) == 1 && \
		ft_isdigit_str(line + ft_strlen(line) + 1 + \
		ft_strlen(line + ft_strlen(line) + 1) + 1) == 1)
	{
		ft_check_coo(line);
		if (find_room(e, line) != NULL)
			room_name_taken(line);
		if (line[0] == 'L' || line[0] == '#')
			room_name_invalid(line);
		if (e->rooms_amount == 0)
			e->rooms = new_room(e, line);
		else
		{
			tmp = e->rooms;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new_room(e, line);
		}
		e->rooms_amount += 1;
	}
	else
		return (-1);
	return (0);
}
