/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:54:03 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:54:04 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void			instant_move(t_env *e)
{
	t_ant	*ptr;

	print_map(e->map);
	ptr = e->ants;
	while (ptr != NULL)
	{
		ft_putchar('L');
		ft_putnbr(ptr->id);
		ft_putchar('-');
		ft_putstr(e->end_room->name);
		if (ptr->next != NULL)
			ft_putchar(32);
		ptr = ptr->next;
	}
	ft_putchar(10);
	exit(OK);
}

static void		calc_queues(t_env *e, int *queues)
{
	t_way	*ptr;
	t_way	*ptr2;
	int		len;
	int		i;

	i = 0;
	ptr = e->ways;
	while (ptr != NULL)
	{
		len = 0;
		ptr2 = e->ways;
		while (ptr2->id != ptr->id)
		{
			len += (ptr->size - ptr2->size);
			ptr2 = ptr2->next;
		}
		queues[i] = len;
		i++;
		ptr = ptr->next;
	}
}

static void		assign_way(t_env *e, t_way *way, int queue)
{
	t_ant		*ptr;

	if (e->ants_waiting > queue)
	{
		ptr = e->ants;
		if (e->neighbour == 1)
		{
			while (ptr != NULL)
			{
				e->ants_waiting -= 1;
				ptr->my_way = way;
				ptr = ptr->next;
			}
			return ;
		}
		while (ptr != NULL && ptr->my_way != NULL)
			ptr = ptr->next;
		if (ptr != NULL)
		{
			e->ants_waiting -= 1;
			ptr->my_way = way;
		}
	}
}

static void		launch_ants(t_env *e, int *queues)
{
	t_way	*ptr;
	int		i;

	i = 0;
	ptr = e->ways;
	while (ptr != NULL)
	{
		assign_way(e, ptr, queues[i]);
		ptr = ptr->next;
		i++;
	}
}

void			move(t_env *e)
{
	int		queues[e->ways_amount];

	print_map(e->map);
	calc_queues(e, queues);
	while (e->ants_left != 0)
	{
		if (e->ants_waiting > 0)
			launch_ants(e, queues);
		try_walk(e);
		ft_putchar(10);
	}
}
