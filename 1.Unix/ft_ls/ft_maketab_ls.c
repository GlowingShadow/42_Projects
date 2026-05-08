/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maketab_ls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 00:27:53 by REDACTED          #+#    #+#             */
/*   Updated: 2015/02/13 02:14:10 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

char		**ft_maketab_ls(char ***tab)
{
	int		i;
	int		j;
	char	**newtab;

	newtab = (char**)malloc(sizeof(char*) * ft_tablen(*tab) + 1);
	i = 0;
	j = 0;
	while ((*tab)[i] != NULL)
	{
		while (ft_grep_name((*tab)[i]) != NULL && \
				ft_grep_name((*tab)[i])[0] == '.')
			i++;
		if ((*tab)[i] != NULL)
		{
			newtab[j] = ft_strdup((*tab)[i]);
			i++;
			j++;
		}
	}
	newtab[j] = NULL;
	return (newtab);
}
