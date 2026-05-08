/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 17:58:12 by REDACTED          #+#    #+#             */
/*   Updated: 2015/01/07 09:28:33 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
}
