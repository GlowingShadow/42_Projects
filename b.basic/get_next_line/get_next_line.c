/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 08:41:32 by REDACTED          #+#    #+#             */
/*   Updated: 2014/11/17 22:39:35 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

void			ft_write(char **tab, char *s)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (tab[1][i] != '\n' && tab[1][i] != 0)
	{
		s[i] = tab[1][i];
		i++;
	}
	s[i] = '\0';
	i++;
	while (tab[1][i] != 0)
	{
		tab[1][j] = tab[1][i];
		i++;
		j++;
	}
	tab[1][j] = 0;
}

static int		ft_read(char **tab, int bytes, int const fd)
{
	char	*s;

	s = tab[1];
	tab[2] = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	bytes = read(fd, tab[2], BUFF_SIZE);
	tab[1] = ft_strjoin(tab[1], tab[2]);
	if (s)
	{
		free(s);
		s = NULL;
	}
	ft_strclr(tab[2]);
	free(tab[2]);
	return (bytes);
}

int				get_next_line(int const fd, char **line)
{
	static char	**tmp;
	static int	count;
	static int	bytes;

	if (BUFF_SIZE < 1 || count == -1)
		return (-1);
	count++;
	if (count == 1)
	{
		tmp = (char**)malloc(sizeof(char*) * 3);
		tmp[1] = (char*)malloc(sizeof(char) * 1);
		bytes = 1;
	}
	if (bytes == 0)
	{
		free(tmp[1]);
		free(tmp);
		count = -1;
		return (0);
	}
	while (ft_strchr(tmp[1], '\n') == NULL && bytes != 0)
		if ((bytes = ft_read(tmp, bytes, fd)) == -1)
			return (-1);
	ft_write(tmp, *line);
	return (1);
}
