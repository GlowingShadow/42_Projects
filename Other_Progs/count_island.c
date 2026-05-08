/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:02:18 by REDACTED          #+#    #+#             */
/*   Updated: 2015/01/27 08:19:56 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"

int	ft_linelen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int	ft_count_line(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	return (n);
}		

char	**ft_convert(char **map, char *str)
{
	int	i;
	int	j;
	int	x;

	map = (char**)malloc(sizeof(char*) * ft_count_line(str) + 1);
	x = 0;
	while (str[x] != '\0')
	{
		map[i] = (char*)malloc(sizeof(char) * ft_linelen(str + x) + 1);
		j = 0;
		while (str[x] != '\n')
		{
			map[i][j] = str[x];
			x++;
			j++;
		}
		map[i][j] = '\0';
		i++;
		x++;
	}
	map[i] = NULL;
	return (map);
}

char	**ft_read_map(char **map, char **av)
{
	char	*buf;
	char	*tmp;
	int	fd;

	buf = (char*)malloc(sizeof(char) * 1025);
	tmp = "";
	ft_bzero(buf, 1025);
	fd = open(av[1], O_RDONLY);
	while (read(fd, buf, 1025) != 0)
	{
		tmp = ft_strjoin(tmp, buf);
		ft_strclr(buf);
	}
	free(buf);
	map = ft_convert(map, tmp);
	return (map);
}

void	ft_fill_island(char ***map, int i, int j, int isle)
{
	(*map)[i][j] = isle + 48;
	if (i > 0)
		if ((*map)[i - 1][j] == 'X')
			ft_fill_island(map, i - 1, j, isle);
	if (i < 13) // nb de lignes
		if ((*map)[i + 1][j] == 'X')
			ft_fill_island(map, i + 1, j, isle);
	if (j > 0)
		if ((*map)[i][j - 1] == 'X')
			ft_fill_island(map, i, j - 1, isle);
	if (j < 66) // taille d'une ligne - 1
		if ((*map)[i][j + 1] == 'X')
			ft_fill_island(map, i, j + 1, isle);
}

int	ft_fill(char ***map)
{
	int	i;
	int	j;
	int	isle;

	i = 0;
	isle = 0;
	while ((*map)[i] != NULL)
	{
		j = 0;
		while ((*map)[i][j] != '\0')
		{
			if ((*map)[i][j] == 'X')
			{
				if (isle == 10)
					return (-1);
				ft_fill_island(map, i, j, isle);
				isle++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_valid_map(char **map)
{
	int	len;
	int	i;

	i = 0;
	if (map[i] != NULL)
		len = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		if (len != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	**map;

	if (ac != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	map = ft_read_map(map, av);
	if (map[0] != NULL && ft_valid_map(map) == 1 && ft_fill(&map) == 0)
		ft_puttab(map);
	else
		ft_putstr("\n");
	return (0);
}
