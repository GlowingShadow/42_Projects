/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 01:19:27 by REDACTED          #+#    #+#             */
/*   Updated: 2014/12/15 01:58:46 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		i++;
	}
	free(*tab);
}
