#include <lemin.h>

int	g_amount = 0;

static t_way	*new_way(t_env *e)
{
	t_way		*way;
	int			memsize;

	g_amount++;
	if ((way = (t_way*)malloc(sizeof(t_way))) == NULL)
		exit(MALLOC_FAILED);
	way->size = 1;
	memsize = e->rooms_amount;
	if ((way->istr = (int*)malloc(sizeof(int) * memsize)) == NULL)
		exit(MALLOC_FAILED);
	way->id = g_amount;
	memsize--;	
	while (memsize >= 0)
	{
		way->istr[memsize] = -1;
		memsize--;
	}
	way->istr[0] = e->start_room->id;
	return (way);
}

void	freelist(t_way *way)
{
//	ft_putnbr(way->id);
//	ft_putendl(" freeing");
	free(way->istr);
	free(way);
}

static void		add_way(t_env *e, t_way *way)
{
	if (e->ways == NULL)
		e->ways = way;
	else
		e->endways->next = way;
	e->endways = way;
}

static void		next_room(t_env *e, t_way *way, t_room *room);
static void		new_branch(t_env *e, t_way *way, t_room *room)
{
	t_way	*way_tmp;
	t_tube	*tube;

	tube = room->tubes;
	while (tube != NULL)
	{
		if (tube->room_dest->id != way->istr[way->size - 2] \
			&& ft_int_strchr(way->istr, way->size, tube->room_dest->id) == -1)// 1ere ligne obsolete, sert pour l'optimisation
		{
			if (tube->next == NULL)
				next_room(e, way, tube->room_dest);
			else
			{
				(void)way_tmp;
				// way_tmp = ft_int_strdup(way->istr, e->rooms_amount);// checker si sa ne change pas aussi le way_tmp precedent
				// way_tmp->size = way->size;
				// g_amount++;
				// way->id = g_amount;
				// next_room(e, way_tmp, tube->room_dest);
			//	freelist(way);
			}
		}
		tube = tube->next;
	}
}

static void		next_room(t_env *e, t_way *way, t_room *room)
{
	static int	found = 0;
	t_tube		*ptr = room->tubes;

	way->istr[way->size] = room->id;
	way->size += 1;
	if (room->tubes_amount >= 2)
		while (ptr != NULL)
		{
			if (ptr->room_dest->id != way->istr[way->size - 2] && \
				ft_int_strchr(way->istr, way->size, ptr->room_dest->id) != -1)
			{
			// freelist(way);
				return ;
			}
			ptr = ptr->next;
		}
	if (room->id == e->end_room->id)
	{
		add_way(e, way);
		found++; ft_putnbr(found); ft_putchar(32);
		ft_putnbr(way->size);
		printistr(e, way->istr, way->size);
		ft_putstr(" : END reached!\n");
		// freelist(way);
		return ;
	}
	else if (room->tubes_amount == 1)
	{
		//freelist(way);
		return ;
	}
	else if (room->tubes_amount == 2)
	{
		if (room->tubes->room_dest->id == way->istr[way->size - 2])
			room = room->tubes->next->room_dest;
		else
			room = room->tubes->room_dest;
		next_room(e, way, room);
		return ;
	}
	new_branch(e, way, room);// 3+ tubes
}

void	set_ways(t_env *e)
{
	t_way	*way;
	t_tube	*tube;

	tube = e->start_room->tubes;
	while (tube != NULL)
	{
		way = new_way(e);// checker si sa ne change pas aussi le way precedent
		next_room(e, way, tube->room_dest);
		tube = tube->next;
	}
	ft_putstr("BIGEND\n");
}
