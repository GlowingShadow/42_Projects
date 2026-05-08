/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maketab_lsr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 00:27:53 by REDACTED          #+#    #+#             */
/*   Updated: 2014/12/12 19:37:39 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

char		**ft_maketab_lsr(char ***tab)
{
	int		i;
	int		j;
	char	**newtab;

	newtab = (char**)malloc(sizeof(char*) * ft_tablen(*tab) + 1);
	i = ft_tablen(*tab) - 1;
	j = 0;
	while (i >= 0)
	{
		newtab[j] = (char*)malloc(sizeof(char) * ft_strlen((*tab)[i]) + 1);
		newtab[j] = ft_strcpy(newtab[j], (*tab)[i]);
		ft_strclr((*tab)[i]);
		free((*tab)[i]);
		j++;
		i--;
	}
	newtab[j] = NULL;
	return (newtab);
}
