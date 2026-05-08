#include <snake.h>

void	ft_print(int **map, int len)
{
	int	i;
	int	j;
(void)len;
	i = 0;
	while (i < MAP_X + 2)
	{
		ft_putchar('X');
		i++;
	}
	ft_putchar(10);
	i = 0;
	while (i < MAP_Y)
	{
		ft_putchar('X');
		j = 0;
		while (j < MAP_X)
		{
			if (map[i][j] != 0)
				ft_putnbr(map[i][j]);
			else
				ft_putchar(' ');

			// if (map[i][j] == 0)
			// 	ft_putchar(32);
			// if (map[i][j] == len)
			// 	ft_putstr_color("O", YELLOW);
			// if (map[i][j] > 0 && map[i][j] != len)
			// 	ft_putstr_color("o", GREEN);
			// if (map[i][j] == -1)
			// 	ft_putstr_color("b", RED);
			j++;
		}
		ft_putstr("X\n");
		i++;
	}
	i = 0;
	while (i < MAP_X + 2)
	{
		ft_putchar('X');
		i++;
	}
	ft_putchar(10);
}

void	ft_init_map(int ***map, int len)
{
	int	i;
	int	j;

	(*map) = (int**)malloc(sizeof(int*) * (MAP_Y + 1));
	i = 0;
	while (i < MAP_Y)
	{
		j = 0;
		(*map)[i] = (int*)malloc(sizeof(int) * (MAP_X + 1));
		while (j < MAP_X)
		{
			(*map)[i][j] = 0;
			j++;
		}
		i++;
	}
	(*map)[i] = NULL;
	(*map)[8][2] = len;
	(*map)[8][3] = len - 1;
	(*map)[8][4] = len - 2;
	(*map)[4][8] = -1;
}

void	ft_read(char *line, int *dir)
{
	if (line[2] == 65)
		*dir = UP;
	if (line[2] == 66)
		*dir = DOWN;
	if (line[2] == 67)
		*dir = RIGHT;
	if (line[2] == 68)
		*dir = LEFT;
}

void	ft_update(int ***map, int len, int *head, int eat)
{
	int	i;
	int	j;

	i = 0;
	(*map)[head[0]][head[1]] = len;
	while (i < MAP_Y)
	{
		j = 0;
		while (j < MAP_X)
		{
			if ((*map)[i][j] > 0 && eat == 0 && (i != head[0] || j != head[1]))
				(*map)[i][j] += -1;
			j++;
		}
		i++;
	}
}

void	ft_move(int ***map, int *len, int **head, int dir)
{
	if (dir == UP)
		(*head)[0] += -1;
	if (dir == DOWN)
		(*head)[0] += 1;
	if (dir == RIGHT)
		(*head)[1] += 1;
	if (dir == LEFT)
		(*head)[1] += -1;
	if ((*map)[(*head)[0]][(*head)[1]] == -1)
	{
		(*len)++;
		(*map)[(*head)[0]][(*head)[1]] = *len;
		ft_update(map, *len, (*head), 1);
	}
	else
	{
		(*map)[(*head)[0]][(*head)[1]] = *len;
		ft_update(map, *len, (*head), 0);
	}
}

int		main(void)
{
	int		**map;
	int		len;
	int		dir;
	int		*head;
	char	*line;

	head = (int*)malloc(sizeof(int) * 2);
	head[0] = 8;
	head[1] = 2;
	dir = DOWN;
	len = 3;
	ft_init_map(&map, len);
	system("clear");
	ft_print(map, len);
	int	i = 0;(void)i;
	while (get_next_line(0, &line) > 0)
	{
		ft_read(line, &dir);
		ft_move(&map, &len, &head, dir);
		system("clear");
		ft_print(map, len);
	}
	return (OK);
}