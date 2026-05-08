#include <lemin.h>

int	g_amount2 = 0;

static t_isstr	new_way(t_env *e)
{
	t_isstr		way;
	int			memsize;

	g_amount2++;
	way.size = 1;
	memsize = e->rooms_amount;
	way.id = g_amount2;
	memsize--;	
	while (memsize >= 0)
	{
		way.istr[memsize] = -1;
		memsize--;
	}
	way.istr[0] = e->start_room->id;
	return (way);
}

static void		add_way2(t_env *e, t_isstr way)
{
	t_isstr		*save;
	int			i;

	save = (t_isstr*)malloc(sizeof(t_isstr));
	save->id = way.id;
	save->size = way.size;
	save->next = NULL;
	i = 0;
	while (i < RNB)
	{
		save->istr[i] = (i < save->size) ? way.istr[i] : -1;
		i++;
	}
	if (e->ways2 == NULL)
		e->ways2 = save;
	else
		e->endways2->next = save;
	e->endways2 = save;
}

static void		next_room(t_env *e, t_isstr way, t_room *room);
static void		new_branch(t_env *e, t_isstr way, t_room *room)
{
	t_tube	*tube;

	tube = room->tubes;
	while (tube != NULL)
	{
		if (tube->room_dest->id != way.istr[way.size - 2] \
			&& ft_int_strchr(way.istr, way.size, tube->room_dest->id) == -1)// 1ere ligne obsolete, sert pour l'optimisation
		{
			if (tube->next == NULL)
				next_room(e, way, tube->room_dest);
			else
			{
				g_amount2++;
				way.id = g_amount2;
				next_room(e, way, tube->room_dest);
			}
		}
		tube = tube->next;
	}
}

static void		next_room(t_env *e, t_isstr way, t_room *room)
{
		// ft_putnbr(way.id);ft_putchar(10);
	static int	found = 0;
	static int	nb = 0;
	t_tube		*ptr;

	nb++;
	// ft_putchar('('); COLOR(RED); ft_putnbr(nb); COLOR(NOCOLOR); ft_putchar(')');
	ptr = room->tubes;
	way.istr[way.size] = room->id;
	way.size += 1;
	if (room->tubes_amount >= 2)
		while (ptr != NULL)
		{
			if (ptr->room_dest->id != way.istr[way.size - 2] && \
				ft_int_strchr(way.istr, way.size, ptr->room_dest->id) != -1)
				{
					// ft_putchar('.');
					return ;
				}
			ptr = ptr->next;
		}
	if (room->id == e->end_room->id)
	{
		add_way2(e, way);
		found++; ft_putnbr(e->recur); ft_putchar(32); ft_putnbr(found); ft_putchar(10);
		// ft_putnbr(way.size);
		// printistr2(e, way.istr, way.size);
		// ft_putstr(" : END reached!\n");
		return ;
	}
	else if (room->tubes_amount == 1)
		return ;
	else if (room->tubes_amount == 2)
	{
		if (room->tubes->room_dest->id == way.istr[way.size - 2])
			room = room->tubes->next->room_dest;
		else
			room = room->tubes->room_dest;
		next_room(e, way, room);
		return ;
	}
	new_branch(e, way, room);// 3+ tubes
}
void	set_ways2(t_env *e)
{
	t_isstr	way;
	t_tube	*tube;

	tube = e->start_room->tubes;
	way = new_way(e);// checker si sa ne change pas aussi le way precedent
	e->recur = 1;
	while (tube != NULL)
	{
		next_room(e, way, tube->room_dest);
		tube = tube->next;
		e->recur += 1;
	}
	ft_putstr("BIGEND\n");
}
