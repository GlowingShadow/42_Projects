/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 19:46:12 by REDACTED          #+#    #+#             */
/*   Updated: 2015/02/19 11:49:18 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_exist_error(char **argv)
{
	t_stat		*buf;
	int			i;

	i = 0;
	ft_tabsort(&argv);
	buf = (struct stat*)malloc(sizeof(struct stat) * 1);
	while (argv[i])
	{
		if (lstat(argv[i], buf) == -1)
			perror(ft_strjoin_free("ls: ", ft_grep_name(argv[i]), 2));
		i++;
	}
}

int				ft_exist(char *arg)
{
	t_stat		*buf;

	buf = (struct stat*)malloc(sizeof(struct stat) * 1);
	if (lstat(arg, buf) == -1)
	{
		free(buf);
		return (0);
	}
	free(buf);
	return (1);
}

int				ft_newtablen(char **argv, int argc, int i)
{
	int			len;

	len = 0;
	while (i < argc)
	{
		if (ft_exist(argv[i]) == 1)
			len++;
		i++;
	}
	return (len);
}

char			**ft_grep(char **tab, char **argv, int argc, int i)
{
	char		**tab2;
	int			x;

	x = 0;
	tab2 = (char**)malloc(sizeof(char*) * ft_newtablen(argv, argc, i) + 1);
	ft_exist_error(argv + i);
	while (i < argc)
	{
		if (ft_exist(argv[i]) == 1)
		{
			tab2[x] = ft_strdup(argv[i]);
			x++;
		}
		i++;
	}
	tab2[x] = NULL;
	ft_tabsort(&tab2);
	ft_clear_tab(&tab);
	return (tab2);
}
