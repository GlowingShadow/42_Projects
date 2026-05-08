/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 17:15:08 by REDACTED          #+#    #+#             */
/*   Updated: 2014/11/15 14:29:36 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int				ft_replace(char **line)
{
	int	x;

	x = 0;
	while ((*line)[x] != '\0')
	{
		if ((*line)[x] == '\n')
			(*line)[x] = '\0';
		x++;
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	int			bytes;
	static int	count;
	char		*tmp;
	static int	carac;

	if (BUFF_SIZE < 1)
		return (-1);
	if (count++ == -1)
		return (0);
	bytes = 0;
	if (count == 1)
		bytes = 1;
	while (bytes != 0)
	{
		tmp = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
		bytes = read(fd, tmp, BUFF_SIZE);
		*line = ft_strjoin(*line, tmp);
		ft_strclr(tmp);
		free(tmp);
	}
	if (count == 1)
	{
		carac = ft_strlen(*line);
		ft_replace(line);
	}
	if (carac == 0)
	{
		*line = *line + ft_strlen(*line);
		return (0);
	}
	if (count > 1)
	{
		carac = carac - ft_strlen(*line) - 1;
		*line = *line + ft_strlen(*line) + 1;
	}
	return (1);
}
