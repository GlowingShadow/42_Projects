/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 22:40:21 by REDACTED          #+#    #+#             */
/*   Updated: 2015/01/22 18:27:38 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*ft_get_nbr(char **tmp)
{
	int		i;
	int		j;
	int		*lin;

	i = 1;
	j = 0;
	lin = (int*)malloc(sizeof(int) * ft_tablen(tmp) + 1);
	lin[0] = ft_tablen(tmp) + 1;
	while (i < lin[0])
	{
		lin[i] = ft_atoi(tmp[j]);
		i++;
		j++;
	}
	return (lin);
}

int		**ft_get_coo(char **av, int i)
{
	char	*line;
	int		fd;
	int		**tab;
	char	**tmp;
	int		j;

	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		perror("");
		exit(-1);
	}
	j = ft_itaballoc(av);
	tab = (int**)malloc(sizeof(int*) * (j + 1));
	while (get_next_line(fd, &line) == 1 && i < j)
	{
		ft_valid_line(&line);
		tmp = ft_strsplit(line, ' ');
		ft_valid_tab(&tmp);
		tab[i] = ft_get_nbr(tmp);
		ft_clear_tab(&tmp);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
