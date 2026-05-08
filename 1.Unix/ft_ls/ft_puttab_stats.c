/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_stats.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 04:08:23 by REDACTED          #+#    #+#             */
/*   Updated: 2015/01/17 04:51:13 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_isdev(t_data *stats, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (ft_strchr((stats[i]).fmode, 'c') != NULL || \
				ft_strchr((stats[i]).fmode, 'b') != NULL)
			return (1);
		i++;
	}
	return (0);
}

void	ft_total_blocks(t_data *stats, char **tab)
{
	int	i;
	int	j;
	int	blocks;

	i = 0;
	j = ft_tablen(tab);
	blocks = 0;
	while (i < j)
	{
		blocks = blocks + (stats[i]).block;
		i++;
	}
	ft_putstr("total ");
	ft_putnbr(blocks);
	ft_putchar('\n');
}

void	ft_puttab_stats(t_data *stats, char **tab, int i, int j)
{
	int		*lens;

	ft_total_blocks(stats, tab);
	j = ft_tablen(tab);
	lens = ft_max_lens(stats, j);
	while (i < j)
	{
		ft_putstr((stats[i]).fmode);
		ft_nputchar(' ', 2 + lens[0] - ft_strlen(ft_itoa((stats[i]).links)));
		ft_putnbr((stats[i]).links);
		ft_put2str(" ", (stats[i]).owner);
		ft_nputchar(' ', 2 + lens[1] - ft_strlen((stats[i]).owner));
		ft_putstr((stats[i]).group);
		ft_put_bytes_dev(stats, i, j, lens);
		ft_put2str(" ", (stats[i]).date);
		ft_put2str(" ", (stats[i]).file);
		if ((stats[i]).symlink != NULL)
			ft_put2str(" -> ", (stats[i]).symlink);
		ft_putchar('\n');
		i++;
	}
}

void	ft_puttab_stats_dir(t_data *stats, char **tab, int i, int j)
{
	int		*lens;

	ft_total_blocks(stats, tab);
	j = ft_tablen(tab);
	lens = ft_max_lens(stats, j);
	while (i < j)
	{
		ft_putstr((stats[i]).fmode);
		ft_nputchar(' ', 2 + lens[0] - ft_strlen(ft_itoa((stats[i]).links)));
		ft_putnbr((stats[i]).links);
		ft_put2str(" ", (stats[i]).owner);
		ft_nputchar(' ', 2 + lens[1] - ft_strlen((stats[i]).owner));
		ft_putstr((stats[i]).group);
		ft_put_bytes_dev(stats, i, j, lens);
		ft_put2str(" ", (stats[i]).date);
		ft_put2str(" ", ft_grep_name((stats[i]).file));
		if ((stats[i]).symlink != NULL)
			ft_put2str(" -> ", (stats[i]).symlink);
		ft_putchar('\n');
		i++;
	}
}

void	ft_puttab_stats_target(t_data *stats, int i, int j)
{
	int		*lens;

	lens = ft_max_lens(stats, j);
	while (i < j)
	{
		if (ft_isdirectory((stats[i]).file) == 0 || \
				ft_readlink((stats[i]).file) != NULL)
		{
			ft_putstr((stats[i]).fmode);
			ft_nputchar(32, 2 + lens[0] - ft_strlen(ft_itoa((stats[i]).links)));
			ft_putnbr((stats[i]).links);
			ft_put2str(" ", (stats[i]).owner);
			ft_nputchar(' ', 2 + lens[1] - ft_strlen((stats[i]).owner));
			ft_putstr((stats[i]).group);
			ft_put_bytes_dev(stats, i, j, lens);
			ft_put2str(" ", (stats[i]).date);
			ft_put2str(" ", (stats[i]).file);
			if ((stats[i]).symlink != NULL)
				ft_put2str(" -> ", (stats[i]).symlink);
			ft_putchar('\n');
		}
		i++;
	}
}
