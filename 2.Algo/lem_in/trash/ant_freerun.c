#include <lemin.h>

static void		try_walk(t_env *e, t_ant *ant)// need optimisation? fouilli..
{
	t_tube	*shorter;
	t_tube	*ptr;

	shorter = ant->room_pos->tubes;
	while (shorter != NULL && (shorter->room_dest->ant != NULL \
		|| shorter->room_dest->room_left >= ant->room_pos->room_left)) // > change meme si dist est la mm // >= change pas meme si dist est la mm
		shorter = shorter->next;
	if (shorter == NULL)
		return ;
	ft_putchar('(');ft_putstr(ant->room_pos->name);ft_putstr(" -> ");ft_putstr(shorter->room_dest->name);ft_putstr(") ");
	ptr = ant->room_pos->tubes;
	while (ptr != NULL)
	{
		if (shorter->room_dest->room_left > ptr->room_dest->room_left)
			shorter = ptr;
		ptr = ptr->next;
	}
	if (shorter->room_dest->ant != NULL && \
		ft_strcmp(shorter->room_dest->name, e->end_room->name) != 0)
	{	ft_putnbr(ant->id);	ft_putchar(10);	return ; }
	ft_putnbr(ant->id);
	ft_putstr(": Yes\n");
	ant->room_pos->ant = NULL;
	ant->room_pos = shorter->room_dest;
	if (ft_strcmp(ant->room_pos->name, e->end_room->name) != 0)
		ant->room_pos->ant = ant;
	else
	{
		e->ants_left -= 1;
		ft_putendl("Ant arrived!"); // ajouter les ants a une liste? pour garder une trace
	}
	ant->rooms_taken += 1;
}

void		move_ants(t_env *e)
{
	t_ant	*ptr;

	if (e->neighbour == 1)
	{
		ft_putstr_color("Start and End are neighbouring.\n", MAGENTA);
		exit(OK);
	}
	COLOR(MAGENTA);
	ptr = e->ants;
	while (ptr != NULL)
	{
		if (ft_strcmp(ptr->room_pos->name, e->end_room->name) != 0)
			try_walk(e, ptr);
		ptr = ptr->next;
	}
}
