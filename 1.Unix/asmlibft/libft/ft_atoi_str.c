/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 15:56:02 by REDACTED          #+#    #+#             */
/*   Updated: 2015/05/15 15:42:22 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_istr		ft_atoi_str(char **tab)
{
	int		i;
	t_istr	istr;

	i = ft_tablen(tab);
	istr.size = i;
	istr.istr = (int*)malloc(sizeof(int) * i);
	i = 0;
	while (tab[i] != NULL)
	{
		(istr.istr)[i] = ft_atoi(tab[i]);
		i++;
	}
	return (istr);
}
