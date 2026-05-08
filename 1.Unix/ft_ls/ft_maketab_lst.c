/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maketab_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 09:46:23 by REDACTED          #+#    #+#             */
/*   Updated: 2015/02/12 03:31:55 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_checksort_epoch(t_data *statst, char ***tab)
{
	int			i;
	int			j;
	int			len;

	i = 0;
	j = 1;
	len = ft_tablen(*tab);
	while (j < len)
	{
		if ((statst[i]).int_epoch < (statst[j]).int_epoch)
			return (0);
		if ((statst[i]).int_epoch == (statst[j]).int_epoch)
			if (ft_strcmp((statst[i]).file, (statst[j]).file) > 0)
				return (0);
		i++;
		j++;
	}
	return (1);
}

void			ft_tabsort_epoch(char ***tab, t_data *statst)
{
	int			i;
	int			j;

	i = 0;
	j = ft_tablen(*tab);
	while (ft_checksort_epoch(statst, tab) != 1)
	{
		i = 0;
		while (i < (j - 1))
		{
			if ((statst[i]).int_epoch < (statst[i + 1]).int_epoch)
				ft_stats_swap(&statst, i, i + 1);
			if ((statst[i]).int_epoch == (statst[i + 1]).int_epoch)
				if (ft_strcmp((statst[i]).file, (statst[i + 1]).file) > 0)
					ft_stats_swap(&statst, i, i + 1);
			i++;
		}
	}
	ft_transfer(tab, statst);
}

char			**ft_maketab_lst(char ***tab)
{
	t_stat		*buf;
	int			i;
	t_data		*statst;

	i = 0;
	statst = (t_data*)malloc(sizeof(t_data) * ft_tablen(*tab));
	buf = (struct stat*)malloc(sizeof(struct stat) * 1);
	while (i < ft_tablen(*tab))
	{
		lstat((*tab)[i], buf);
		(statst[i]).file = (*tab)[i];
		(statst[i]).int_epoch = (unsigned int)(buf->st_mtimespec.tv_sec);
		i++;
	}
	ft_tabsort_epoch(tab, statst);
	ft_clear_epoch(&statst, ft_tablen(*tab));
	free(buf);
	return (*tab);
}
