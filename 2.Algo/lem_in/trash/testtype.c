#include <lemin.h>

#define BUF	100

void	fun(int way[BUF])
{
	int i = 0;
	while (i < 5)
	{
		way[i] = 1;
		i++;
	}
}

int	main(void)
{
	int		way[BUF];
	int		way2[BUF];

	int i = 0;
	while (i < 10)
	{
		way[i] = 4;
		i++;
	}
	
	ft_memcpy((void*)way2, (void*)way, sizeof(int) * BUF);
	i = 0;
	while (i < 10)
	{
		ft_putnbr(way2[i]);
		ft_putchar(32);
		i++;
	}
	ft_putchar(10);

	fun(way2);
	i = 0;
	while (i < 10)
	{
		ft_putnbr(way2[i]);
		ft_putchar(32);
		i++;
	}
	ft_putchar(10);

	return (0);
}

