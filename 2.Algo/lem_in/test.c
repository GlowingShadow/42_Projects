#include <lemin.h>

static t_istr	new_way(int memsize)
{
	t_istr	way;

	// way = (t_istr*)malloc(sizeof(t_istr));
	way.size = memsize;
	way.istr = (int*)malloc(sizeof(int) * memsize);
	memsize--;	
	while (memsize >= 0)
	{
		way.istr[memsize] = memsize;
		memsize--;
	}
	return (way);
}

void	prout(t_istr *way)
{
	int i = way->size;
		i--;
		COLOR(GREEN);
		while (i >= 0)
		{
			ft_putnbr(way->istr[i]);
			i--;
		}
		ft_putchar(10);
		COLOR(NOCOLOR);
}

void	fun1(t_istr way)
{
	way->size = 0;
}

int	main(void)
{
	t_istr	way;

	way.size = 4;
	ft_putnbr(way.size);ft_putchar(10);
	fun1(&way);
	ft_putnbr(way.size);ft_putchar(10);
	return 0;
}
