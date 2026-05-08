/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_stats_dev.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 01:28:11 by REDACTED          #+#    #+#             */
/*   Updated: 2015/02/12 04:16:57 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_put_bytes_dev(t_data *stats, int i, int j, int *lens)
{
	if (ft_isdev(stats, j) == 1)
	{
		if (((stats[i]).fmode)[0] == 'c' || ((stats[i]).fmode)[0] == 'b')
		{
			ft_nputchar(' ', 3 + lens[2] - ft_strlen((stats[i]).group));
			ft_nputchar(' ', lens[3] - ft_strlen(ft_itoa((stats[i]).major)));
			ft_putnbr((stats[i]).major);
			ft_putchar(',');
			ft_nputchar(32, 1 + lens[4] - ft_strlen(ft_itoa((stats[i]).minor)));
			ft_putnbr((stats[i]).minor);
		}
		else
		{
			ft_nputchar(' ', 5 + lens[2] - ft_strlen((stats[i]).group) + \
					lens[3] + lens[4] - ft_strlen(ft_itoa((stats[i]).bytes)));
			ft_bigputnbr((stats[i]).bytes);
		}
	}
	else
		ft_put_bytes(stats, i, lens);
}

void	ft_put_bytes(t_data *stats, int i, int *lens)
{
	ft_nputchar(' ', 2 + lens[2] - ft_strlen((stats[i]).group));
	ft_nputchar(' ', lens[5] - ft_strlen(ft_itoa((stats[i]).bytes)));
	ft_bigputnbr((stats[i]).bytes);
}

int		*ft_max_lens(t_data *stats, int j)
{
	int		*lens;

	lens = (int*)malloc(sizeof(int) * 6);
	lens[0] = ft_max_links_len(stats, j);
	lens[1] = ft_max_owner_len(stats, j);
	lens[2] = ft_max_group_len(stats, j);
	if (ft_isdev(stats, j) == 1)
	{
		lens[3] = ft_max_major_len(stats, j);
		lens[4] = ft_max_minor_len(stats, j);
	}
	else
		lens[5] = ft_max_bytes_len_target(stats, j);
	return (lens);
}
