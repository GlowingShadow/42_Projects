/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/17 12:18:57 by REDACTED          #+#    #+#             */
/*   Updated: 2015/05/17 22:59:40 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_add_block(t_env *e, char *str, int i, int j)
{
	t_map	*lst;
	t_map	*tmp;

	lst = (t_map*)malloc(sizeof(t_map) * 1);
	tmp = e->map;
	while (e->map->next != NULL)
		e->map = e->map->next;
	e->map->next = lst;
	e->map = tmp;
	lst->wall = str[0] - 48;
	lst->x = i;
	lst->y = j;
	lst->up = NULL;
	lst->down = NULL;
	lst->left = NULL;
	lst->right = NULL;
	lst->next = NULL;
}

static void	ft_link(t_env *e, int i, int j)
{
	t_map	*save;
	t_map	*tmp;

	save = e->map;
	while (e->map->x != i || e->map->y != j)
	{
		if ((i - e->map->x) == 0 && (j - e->map->y) == 1)
		{
			e->map->right = e->map->next;
			e->map->right->left = e->map;
		}
		if ((i - e->map->x) == 1 && (j - e->map->y) == 0)
			tmp = e->map;
		e->map = e->map->next;
	}
	if ((i - e->map->x) == 0 && (j - e->map->y) == 0 && i != 0)
	{
		e->map->up = tmp;
		e->map->up->down = e->map;
	}
	e->map = save;
}

static void	ft_add_line(t_env *e, char *str, int i)
{
	int		j;
	char	**tab;

	tab = ft_strsplit(str, ' ');
	j = 0;
	while (tab[j] != NULL)
	{
		ft_add_block(e, tab[j], i, j);
		ft_link(e, i, j);
		free(tab[j]);
		j++;
	}
	free(tab);
}

void		ft_get_map(t_env *e)
{
	char	*str;
	int		fd;
	int		i;

	e->map = (t_map*)malloc(sizeof(t_map) * 1);
	e->map->wall = -1;
	e->map->next = NULL;
	e->map->x = 0;
	e->map->y = -1;
	fd = open("maps/level0.map", O_RDONLY);
	i = 0;
	while (get_next_line(fd, &str) == 1)
	{
	//	ft_putendl(str);
		ft_add_line(e, str, i);
		i++;
	}
	free(str);
	e->map = e->map->next;
}
