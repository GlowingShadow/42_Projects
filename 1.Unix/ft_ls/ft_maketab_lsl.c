/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maketab_lsl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 21:41:33 by REDACTED          #+#    #+#             */
/*   Updated: 2015/02/19 10:24:38 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_grep_name(char *s)
{
	int			i;
	char		*name;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	while (0 <= i && s[i] != '/')
		i--;
	name = ft_strdup(s + i + 1);
	return (name);
}

char	*ft_readlink(char *file)
{
	char		*symlink;

	symlink = (char*)malloc(sizeof(char) * 260 + 1);
	ft_strclr(symlink);
	if (readlink(file, symlink, 260) == -1)
		return (NULL);
	return (symlink);
}

void	ft_get_stats2(t_data **stats, t_stat *buf, char **tab)
{
	if (((*stats)->fmode)[0] != 'c' && ((*stats)->fmode)[0] != 'b')
		(*stats)->bytes = buf->st_size;
	else
	{
		(*stats)->major = buf->st_rdev >> 24 & 0xff;
		(*stats)->minor = buf->st_rdev & 0xff;
	}
	(*stats)->epoch = (&buf->st_mtimespec.tv_sec);
	(*stats)->date = ft_get_time(*stats);
	(*stats)->file = ft_strdup(*tab);
	(*stats)->symlink = ft_readlink(*tab);
	(*stats)->block = buf->st_blocks;
}

int		ft_get_stats(t_data *stats, char **tab)
{
	t_stat			*buf;
	struct passwd	*pw;
	struct group	*gr;

	buf = (t_stat*)malloc(sizeof(t_stat) * 1);
	if (lstat(*tab, buf) == -1)
	{
		perror(ft_strjoin_free("ls: ", ft_grep_name(*tab), 2));
		return (-1);
	}
	stats->fmode = ft_perm(buf);
	stats->links = buf->st_nlink;
	if ((pw = getpwuid(buf->st_uid)) == NULL)
		stats->owner = ft_itoa(buf->st_uid);
	else
		stats->owner = ft_strdup((getpwuid(buf->st_uid))->pw_name);
	if ((gr = getgrgid(buf->st_gid)) == NULL)
		stats->group = ft_itoa(buf->st_gid);
	else
		stats->group = ft_strdup((getgrgid(buf->st_gid))->gr_name);
	ft_get_stats2(&stats, buf, tab);
	free(buf);
	return (0);
}

t_data	*ft_maketab_lsl(char ***tab)
{
	int			i;
	int			j;
	t_data		*stats;

	stats = (t_data*)malloc(sizeof(t_data) * (ft_tablen(*tab) + 1));
	i = 0;
	j = 0;
	while (j < ft_tablen(*tab))
	{
		if (ft_get_stats(&(stats[i]), &((*tab)[j])) == -1)
			i--;
		i++;
		j++;
	}
	(*tab)[i] = NULL;
	if (i == 0)
	{
		(*tab)[0] = NULL;
		return (NULL);
	}
	return (stats);
}
