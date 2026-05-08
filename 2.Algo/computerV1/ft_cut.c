/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 06:19:30 by REDACTED          #+#    #+#             */
/*   Updated: 2015/04/04 05:37:19 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int		ft_check_group(char **tab, int ind)
{
	int		i;

	i = 0;
	tab[ind] = NULL;
	while (tab[i] != NULL)
	{
		if (i == ind)
			i++;
		if ((i % 4) == 0)
			if (ft_isnumber(tab[i]) == 0)
				return (-1);
		if ((i % 4) == 1)
			if (ft_ismult(tab[i]) == 0)
				return (-2);
		if ((i % 4) == 2)
			if (ft_ispower(tab[i]) == 0)
				return (-3);
		if ((i % 4) == 3)
			if (ft_isoperand_str(tab[i]) == 0)
				return (-4);
		i++;
	}
	if (i == ind)
		return (ft_check_group(tab + i + 1, -1));
	return (0);
}

int		ft_check_equal(char **tab)
{
	int		i;
	int		index;

	i = 0;
	index = -1;
	while (tab[i] != NULL)
	{
		if (ft_strcmp(tab[i], "=") == 0)
		{
			if (index != -1)
				return (-1);
			index = i;
		}
		i++;
	}
	if (index == 0 || index == ft_tablen(tab) - 1)
		index = -1;
	return (index);
}

int		ft_check_parse(char **tab)
{
	int		ind;
	int		i;

	if ((ind = ft_check_equal(tab)) == -1)
		return (-1);
	if ((i = ft_check_group(tab, ind)) < 0)
	{
		ft_putnbr(i);
		return (-1);
	}
	return (0);
}

char	**ft_cut(char *src)
{
	char	**f;
	int		i;

	f = ft_strsplit(src, ' ');
	i = 0;
	while (f[i] != NULL)
	{
		if (ft_strlen(f[i]) == 1 && f[i][0] == 'X')
		{
			free(f[i]);
			f[i] = ft_strdup("X^1");
		}
		i++;
	}
	//ft_puttab(f);
	if (ft_check_parse(f) == -1)
		return (NULL);
	return (f);
}
