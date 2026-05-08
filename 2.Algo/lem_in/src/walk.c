/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:56:36 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:56:40 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		print_move(t_ant *ptr, int color)
{
	ft_putchar('L');
	if (color == 1)
		COLOR(MAGENTA);
	ft_putnbr(ptr->id);
	if (color == 1)
		COLOR(NOCOLOR);
	ft_putchar('-');
	if (color == 1)
		ft_putstr_color(ptr->room_pos->name, RED);
	else
		ft_putstr(ptr->room_pos->name);
	ft_putchar(32);
}

void			try_walk(t_env *e)
{
	t_ant	*ptr;
	t_way	*ptr2;
	int		i;

	ptr = e->ants;
	while (ptr != NULL)
	{
		ptr2 = ptr->my_way;
		i = 0;
		if (ptr2 != NULL && ptr->room_pos->id != e->end_room->id)
		{
			while (ptr2->istr[i] != ptr->room_pos->id)
				i++;
			ptr->room_pos->ant = NULL;
			ptr->room_pos = get_room(e, ptr2->istr[i + 1]);
			if (ptr->room_pos->id != e->end_room->id \
				&& ptr->room_pos->ant != NULL)
				exit(DATA_CORRUPT);
			ptr->room_pos->ant = ptr;
			print_move(ptr, e->color);
			if (ptr->room_pos->id == e->end_room->id)
				e->ants_left -= 1;
		}
		ptr = ptr->next;
	}
}
