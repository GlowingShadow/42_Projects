/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:53:54 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:53:56 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		init_algo(t_env *e, int ac, char **av)
{
	if (ac > 1 && ft_strlen(av[1]) == 1)
	{
		if (av[1][0] == '1')
			e->algo = 1;
		else if (av[1][0] == '2')
			e->algo = 2;
	}
}

static t_env	*init_env(int ac, char **av)
{
	t_env	*e;

	e = (t_env*)malloc(sizeof(t_env));
	e->map = NULL;
	e->command_id = 0;
	e->rooms_amount = 0;
	e->ants_amount = 0;
	e->ants = NULL;
	e->start_room = NULL;
	e->end_room = NULL;
	e->rooms = NULL;
	e->ways = NULL;
	e->neighbour = 0;
	e->algo = 0;
	e->combi = NULL;
	e->prints = 0;
	e->color = 0;
	e->matrix = 0;
	e->ways_tested = 0;
	e->ways_found = 0;
	init_algo(e, ac, av);
	return (e);
}

static void		resume_stats(t_env *e, t_room *ptr, t_tube *tube)
{
	COLOR(RED);
	ft_putnbr(e->ants_amount);
	ft_putstr(" ants, ");
	ft_putnbr(e->rooms_amount);
	ft_putstr(" rooms\n");
	ft_putstr_color("rooms name ", YELLOW);
	ft_putstr_color("linked rooms\n", CYAN);
	while (ptr != NULL)
	{
		COLOR(YELLOW);
		ft_putstr(ptr->name);
		ft_putchar(32);
		if (ptr->tubes_amount != 0)
			tube = ptr->tubes;
		COLOR(CYAN);
		while (tube != NULL)
		{
			ft_putstr(tube->room_dest->name);
			ft_putchar(32);
			tube = tube->next;
		}
		ft_putchar(10);
		ptr = ptr->next;
	}
}

void			fuck(t_env *e)
{
	t_room	*ptr;

	if (e->prints == 0)
		return ;
	ptr = e->rooms;
	resume_stats(e, ptr, NULL);
	COLOR(RED);
	ft_putstr("Start room:\t");
	ft_putendl(e->start_room->name);
	ft_putstr("End room:\t");
	ft_putendl(e->end_room->name);
	ft_putchar(10);
	COLOR(NOCOLOR);
}

int				main(int ac, char **av)
{
	t_env	*e;

	e = init_env(ac, av);
	ft_get_map(e);
	e->ra_coef = e->rooms_amount * 10;
	ft_resolve(e, NULL, NULL);
	return (0);
}
