/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 19:36:21 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/13 19:36:23 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	get_map(t_env *e, char *file)
{
	int		fd;
	char	*line;
	int		i;

	if ((fd = open(file, O_RDONLY)) == -1)
		error("error\n", OPEN_FAILED);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		if (i > 130)
			error("Too much tetriminos\n", INVALID_LINE);
		if (i % 5 == 0)
		{
			if (ft_strlen(line) != 0)
				error("Invalid line\n", INVALID_LINE);
		}
		else if (ft_strlen(line) == 4)
			ft_strcat(e->pieces[i / 5], line);
		else
			error("Invalid line\n", INVALID_LINE);
	}
	(i % 5 != 0) ? error("Invalid line\n", INVALID_LINE) : NULL;
	e->pieces[26][0] = (i + 1) / 5;
	close(fd);
}

void	print_result(char *map, int size)
{
	int i;

	i = 0;
	while (i < size * size)
	{
		if (!map[i])
			write(1, ".", 1);
		else
			write(1, &map[i], 1);
		i++;
		if (i % size == 0)
			write(1, "\n", 1);
	}
}
