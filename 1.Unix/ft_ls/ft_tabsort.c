/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 02:51:10 by REDACTED          #+#    #+#             */
/*   Updated: 2014/12/10 12:59:22 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_checksort(char **tab)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 1;
	len = ft_tablen(tab);
	while (j < len)
	{
		if (ft_strcmp(tab[i], tab[j]) > 0)
			return (0);
		i++;
		j++;
	}
	return (1);
}

void	ft_tabsort(char ***tab)
{
	int		i;
	int		j;
	int		len;

	len = ft_tablen(*tab) - 1;
	j = len;
	i = 0;
	while (ft_checksort(*tab) != 1)
	{
		i = 0;
		while (i < j)
		{
			len = ft_tablen(*tab) - 1;
			while (len > i)
			{
				if ((ft_strcmp((*tab)[i], (*tab)[len])) > 0)
					ft_strswap(&((*tab)[i]), &((*tab)[len]));
				len--;
			}
			i++;
		}
	}
}
