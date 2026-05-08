/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 01:46:13 by REDACTED          #+#    #+#             */
/*   Updated: 2015/02/13 02:15:39 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	ft_strswap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
	tmp = NULL;
}

void	ft_stats_swap(t_data **stats, int i, int len)
{
	char			*tmp;
	long long int	j;

	j = ((*stats)[i]).int_epoch;
	((*stats)[i]).int_epoch = ((*stats)[len]).int_epoch;
	((*stats)[len]).int_epoch = j;
	tmp = ((*stats)[i]).file;
	((*stats)[i]).file = ((*stats)[len]).file;
	((*stats)[len]).file = tmp;
}

void	ft_transfer(char ***tab, t_data *stats)
{
	int		i;
	int		len;

	i = 0;
	len = ft_tablen(*tab);
	while (i < len)
	{
		(*tab)[i] = ft_strdup((stats[i]).file);
		i++;
	}
}
