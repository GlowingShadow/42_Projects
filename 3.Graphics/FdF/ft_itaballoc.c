/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itaballoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 01:26:05 by REDACTED          #+#    #+#             */
/*   Updated: 2015/01/07 05:02:24 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_read(char ***tab, int bytes, int const fd)
{
	char	*s;

	s = (*tab)[0];
	(*tab)[1] = (char*)malloc(sizeof(char) * 2048 + 1);
	if ((bytes = read(fd, (*tab)[1], 2048)) == -1)
		return (-1);
	(*tab)[1][bytes] = 0;
	(*tab)[0] = ft_strjoin((*tab)[0], (*tab)[1]);
	if (s)
	{
		free(s);
		s = NULL;
	}
	ft_strclr((*tab)[1]);
	free((*tab)[1]);
	return (bytes);
}

int				ft_itaballoc(char **av)
{
	int		i;
	char	**tab;
	int		bytes;
	int		fd;

	tab = (char**)malloc(sizeof(char*) * 3);
	tab[0] = (char*)malloc(sizeof(char) * 1);
	fd = open(av[1], O_RDONLY);
	bytes = 1;
	i = 0;
	while (bytes != 0)
		if ((bytes = ft_read(&tab, bytes, fd)) == -1)
			return (-1);
	bytes = 0;
	while (tab[0][i] != '\0')
	{
		if (tab[0][i] == '\n')
			bytes++;
		i++;
	}
	return (bytes);
}
