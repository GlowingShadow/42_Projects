#include "malloc.h"

t_block **get_block_by_size(size_t size)
{
	if (size <= TINY)
		return (&(g_start->tiny));
	else if (size > TINY && size <= SMALL)
		return (&(g_start->small));
	else
		return (&(g_start->big));
}

void	*add_last_block(t_block *add, t_block **start)//aloue la taile de lastuct
{
	t_block *i;

	if (add == NULL)
		return (NULL);
	add->next = NULL;	
	if ((*start) == NULL)
	{
		*start = add;
		return (add);
	}
	i = *start;
	while (i->next)
		i = i ->next;
	i->next = add;
//	add->next = NULL;
	return (add);
}
void	init_struct(void)
{
	static t_start g;
	
	puts("init");
	g_start = &g;
	g_start->tiny = NULL;	
	g_start->small = NULL;	
	g_start->big = NULL;	
}