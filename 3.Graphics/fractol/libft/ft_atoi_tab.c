/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 15:56:02 by REDACTED          #+#    #+#             */
/*   Updated: 2015/02/20 12:29:06 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_itab		ft_atoi_tab(char **tab)
{
	int		i;
	t_itab	itab;

	i = ft_tablen(tab);
	itab.size = i;
	itab.tab = (int*)malloc(sizeof(int) * i);
	i = 0;
	while (tab[i] != NULL)
	{
		(itab.tab)[i] = ft_atoi(tab[i]);
		i++;
	}
	return (itab);
}
