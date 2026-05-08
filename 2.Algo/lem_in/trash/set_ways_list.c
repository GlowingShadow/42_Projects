#include <lemin.h>

int	g_amount3 = 0;

static t_int	*new_way(t_env *e)
{
	t_int		*way;

	g_amount3++;
	way = (t_int*)malloc(sizeof(t_int));
	way->id = g_amount3;
	way->size = 1;
	way->room_id = e->start_room->id;
	way->next = NULL;
	return (way);
}

static t_int	*new_room(t_room *room)
{
	t_int		*way;

	way = (t_int*)malloc(sizeof(t_int));
	way->id = g_amount3;
	way->size = 1;
	way->room_id = room->id;
	way->next = NULL;
	return (way);
}

static t_int	*get_last_roomid(t_int *start, t_env *e)
{
	t_int	*ptr;

	ptr = start;
	while (ptr->next != NULL)
		ptr = ptr->next;
	(void)e;
	// ft_putstr_color(get_room(e, ptr->room_id)->name, CYAN);
	return (ptr);
}

static t_int	*get_prev_roomid(t_int *start)
{
	t_int	*ptr;

	ptr = start;
	while (ptr->next->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

static void		freelist(t_int *list)
{
	t_int	*ptr;

	ptr = list;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		free(list);
		list = ptr;
	}
}

static void		add_wayl(t_env *e, t_int *way)
{
	if (e->waysl == NULL)
		e->waysl = way;
	else
		e->endwaysl->next_way = way;
	e->endwaysl = way;
}

static void		add_wayl_free(t_env *e, t_int *way)
{
	if (e->waysl_free == NULL)
		e->waysl_free = way;
	else
		e->endwaysl_free->next_way = way;
	e->endwaysl_free = way;
}

static void		next_room(t_env *e, t_int *way, t_room *room);
static void		new_branch(t_env *e, t_int *way, t_room *room)
{
	t_tube	*tube;
	t_int	*way_tmp;

	tube = room->tubes;
	while (tube != NULL)
	{
		if (ft_int_listchr(way, tube->room_dest->id) == NULL)
		{
			if (tube->next == NULL)
				next_room(e, way, tube->room_dest);
			else
			{
				g_amount3++;
				way_tmp = ft_int_listdup(way);
				way->id = g_amount3;
				next_room(e, way_tmp, tube->room_dest);
			}
		}
		tube = tube->next;
	}
}

static void		next_room(t_env *e, t_int *way, t_room *room)
{
	static int	found = 0;
	static int	nb = 0;
	t_tube		*tube;

	// ft_putchar('('); COLOR(RED); ft_putnbr(nb); COLOR(NOCOLOR); ft_putchar(')');
	tube = room->tubes;
	get_last_roomid(way, e)->next = new_room(room);
	way->size += 1;
	if (room->tubes_amount >= 2)
		while (tube != NULL)
		{
			if (get_prev_roomid(way)->room_id != tube->room_dest->id &&
			ft_int_listchr(way, tube->room_dest->id) != NULL)
			{
				add_wayl_free(e, way);
				return ;
			}
			tube = tube->next;
		}
	if (room->id == e->end_room->id)
	{
		add_wayl(e, way);
		nb++;
		found++;
		if (nb == 1000){ft_putnbr(e->recur); ft_putchar(32); ft_putnbr(found); ft_putchar(10); nb = 0;}
		// printilist(e, way);
		// ft_putnbr(way->size);
		// ft_putstr(" : END reached!\n");
		return ;
	}
	else if (room->tubes_amount == 2)
	{
		if (ft_int_listchr(way, room->tubes->room_dest->id) != NULL)
			room = room->tubes->next->room_dest;
		else
			room = room->tubes->room_dest;
		next_room(e, way, room);
		return ;
	}
	new_branch(e, way, room);// 3+ tubes
}
static void		check_free(t_env *e)
{
	t_int	*ptr_f;
	t_int	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_putnbr(g_amount3); ft_putchar(10);
	ptr_f = e->waysl_free;
	while (ptr_f != NULL)
	{
		i++;
		if (i == 1000)
		{
			ft_putchar('.');
			i = 0;
			j++;
		}
		if (j == 100)
		{
			ft_putchar(10);
			j = 0;
		}
		ptr = e->waysl;
		while (ptr != NULL)
		{
			if (ptr_f->id == ptr->id)
				break;
			ptr = ptr->next_way;
			if (ptr == NULL)
				ptr_f->id = -2;
		}
		ptr_f = ptr_f->next_way;
	}
	ptr_f = e->waysl_free;
	while (ptr_f != NULL)
	{
		ptr = NULL;
		if (ptr_f->id == -2)
			ptr = ptr_f;
		ptr_f = ptr_f->next_way;
		if (ptr != NULL)
			freelist(ptr);
	}
}

void	set_waysl(t_env *e)
{
	t_int	*way;
	t_tube	*tube;

	tube = e->start_room->tubes;
	e->recur = 1;
	while (tube != NULL)
	{
		way = new_way(e);
		next_room(e, way, tube->room_dest);
		tube = tube->next;
		e->recur += 1;
	}
	check_free(e);
	while(1);
	ft_putstr("BIGEND\n");
}
