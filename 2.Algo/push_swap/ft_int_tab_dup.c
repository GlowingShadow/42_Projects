/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_tab_dup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 12:15:19 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/15 17:30:00 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_itab		ft_int_tab_dup(int *tab, int size)
{
	t_itab	newtab;

	newtab.tab = (int*)malloc(sizeof(int) * size);
	newtab.size = size;
	while (size >= 0)
	{
		(newtab.tab)[size] = tab[size];
		size--;
	}
	return (newtab);
}
