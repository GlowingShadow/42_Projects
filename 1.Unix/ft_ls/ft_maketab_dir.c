/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maketab_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 10:47:20 by REDACTED          #+#    #+#             */
/*   Updated: 2015/02/19 13:07:57 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_isdirectory(char *str)
{
	int			i;
	struct stat	*buf;

	i = 0;
	buf = (struct stat*)malloc(sizeof(struct stat) * 1);
	if (lstat(str, buf) == -1)
		return (-1);
	((S_ISDIR(buf->st_mode)) ? (i++) : (i = 0));
	free(buf);
	return (i);
}

int		ft_islink(char *str)
{
	int			i;
	struct stat	*buf;

	i = 0;
	buf = (struct stat*)malloc(sizeof(struct stat) * 1);
	if (lstat(str, buf) == -1)
		return (1);
	((S_ISLNK(buf->st_mode) != 0) ? (i++) : (i = 0));
	free(buf);
	return (i);
}

int		ft_count_dir(char **tab, char *opt)
{
	int			i;
	int			j;
	int			count;

	i = 0;
	j = ft_tablen(tab);
	count = 0;
	while (i < j)
	{
		if (ft_islink(tab[i]) == 1 && ft_strchr(opt, 'l') == NULL)
			count++;
		if (ft_isdirectory(tab[i]) == 1)
			count++;
		i++;
	}
	return (count);
}

char	**ft_maketab_dir(char ***tab, char *opt)
{
	char		**dir;
	int			i;
	int			j;
	int			x;

	i = 0;
	j = 0;
	x = ft_tablen(*tab);
	dir = (char**)malloc(sizeof(char*) * ft_count_dir(*tab, opt) + 1);
	while (i < x)
	{
		if (ft_isdirectory((*tab)[i]) == 1 && ft_islink((*tab)[i]) == 0)
			dir[j++] = ft_strdup((*tab)[i]);
		if (ft_islink((*tab)[i]) == 1 && ft_strchr(opt, 'l') == NULL && \
				ft_isdirectory(ft_readlink(((*tab)[i]))) == 1 && \
				ft_exist(ft_readlink(((*tab)[i]))) == 1)
		{
			dir[j] = ft_strdup((*tab)[i]);
			j++;
		}
		i++;
	}
	dir[j] = NULL;
	return (dir);
}
