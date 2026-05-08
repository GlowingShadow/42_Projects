/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 17:58:12 by REDACTED          #+#    #+#             */
/*   Updated: 2015/01/27 02:52:55 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_clear_tab(char ***tab)
{
	int	i;
	int	j;

	i = 0;
	j = ft_tablen(*tab);
	while (i < j)
	{
		ft_strclr(((*tab)[i]));
		free((*tab)[i]);
		i++;
	}
	free(*tab);
}

void	ft_strdel2(char **str)
{
	ft_strclr(*str);
	free(*str);
}

void	ft_clear_stats(t_data **stats, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_strdel2(&(((*stats)[i]).file));
		ft_strdel2(&(((*stats)[i]).symlink));
		ft_strdel2(&(((*stats)[i]).fmode));
		((*stats)[i]).links = 0;
		ft_strdel2(&(((*stats)[i]).owner));
		ft_strdel2(&(((*stats)[i]).group));
		((*stats)[i]).bytes = 0;
		ft_strdel2(&(((*stats)[i]).date));
		if (((*stats)[i]).epoch)
			(((*stats)[i]).epoch) = 0;
		((*stats)[i]).int_epoch = 0;
		((*stats)[i]).block = 0;
		i++;
	}
	free(*stats);
}

void	ft_clear_epoch(t_data **stats, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_strdel2(&(((*stats)[i]).file));
		((*stats)[i]).int_epoch = 0;
		i++;
	}
	free(*stats);
}
