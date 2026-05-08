/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stats_len_target.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 07:01:47 by REDACTED          #+#    #+#             */
/*   Updated: 2015/02/13 02:17:10 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		ft_max_links_len_target(t_data *stats, int j)
{
	int	links_len;
	int	i;

	links_len = 0;
	i = 0;
	while (i < j)
	{
		if (ft_isdirectory((stats[i]).file) == 0)
			if (links_len < ft_strlen(ft_itoa((stats[i]).links)))
				links_len = ft_strlen(ft_itoa((stats[i]).links));
		i++;
	}
	return (links_len);
}

int		ft_max_owner_len_target(t_data *stats, int j)
{
	int	owner_len;
	int	i;

	owner_len = 0;
	i = 0;
	while (i < j)
	{
		if (ft_isdirectory((stats[i]).file) == 0)
			if (owner_len < ft_strlen((stats[i]).owner))
				owner_len = ft_strlen((stats[i]).owner);
		i++;
	}
	return (owner_len);
}

int		ft_max_group_len_target(t_data *stats, int j)
{
	int	group_len;
	int	i;

	group_len = 0;
	i = 0;
	while (i < j)
	{
		if (ft_isdirectory((stats[i]).file) == 0)
			if (group_len < ft_strlen((stats[i]).group))
				group_len = ft_strlen((stats[i]).group);
		i++;
	}
	return (group_len);
}

int		ft_max_bytes_len_target(t_data *stats, int j)
{
	int	bytes_len;
	int	i;

	bytes_len = 0;
	i = 0;
	while (i < j)
	{
		if (bytes_len < ft_strlen(ft_itoa((stats[i]).bytes)))
			bytes_len = ft_strlen(ft_itoa((stats[i]).bytes));
		i++;
	}
	return (bytes_len);
}
