/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_smaller_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 16:42:55 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/15 22:01:27 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_small		ft_find_bigger_int(int *tab, int size)
{
	int		i;
	t_small	sm;

	sm.i = 0;
	sm.n = tab[0];
	i = 0;
	while (i < size)
	{
		if (sm.n < tab[i])
		{
			sm.n = tab[i];
			sm.i = i;
		}
		i++;
	}
	return (sm);
}

t_small		ft_find_smaller_int(int *tab, int size)
{
	int		i;
	t_small	sm;

	sm.i = 0;
	sm.n = tab[0];
	i = 0;
	while (i < size)
	{
		if (sm.n > tab[i])
		{
			sm.n = tab[i];
			sm.i = i;
		}
		i++;
	}
	return (sm);
}
