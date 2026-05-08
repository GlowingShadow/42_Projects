/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 03:52:26 by REDACTED          #+#    #+#             */
/*   Updated: 2015/02/19 13:05:44 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_puttab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		i++;
		ft_putchar('\n');
	}
}

void	ft_puttab_target(char **tab, char *opt)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if ((ft_isdirectory(tab[i]) == 0 && ft_islink(tab[i]) == 0) || \
			(ft_strchr(opt, 'l') == NULL && ft_islink(tab[i]) == 1 && \
			(ft_isdirectory(ft_readlink(tab[i])) == 0 || \
			ft_isdirectory(ft_readlink(tab[i])) == -1)))
		{
			ft_putstr(tab[i]);
			ft_putchar('\n');
		}
		i++;
	}
}

void	ft_no_path(char ***tab)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = ft_tablen(*tab);
	while (i < j)
	{
		tmp = (*tab)[i];
		(*tab)[i] = ft_grep_name((*tab)[i]);
		free(tmp);
		i++;
	}
}
