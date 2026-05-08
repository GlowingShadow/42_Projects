/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:19:46 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/12 04:47:44 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_itab *pile)
{
	ft_intswap(&((pile->tab)[0]), &((pile->tab)[1]));
}

void	ft_sswap(t_itab *pile1, t_itab *pile2)
{
	ft_swap(pile1);
	ft_swap(pile2);
}

void	ft_ablation(t_itab *src)
{
	int	i;

	i = 0;
	while (i < (src->size - 1))
	{
		(src->tab)[i] = (src->tab)[i + 1];
		i++;
	}
	(src->size)--;
}

int		ft_push(t_itab *src, t_itab *dst)
{
	int	i;

	if (src->size == 0)
		return (0);
	i = dst->size;
	(dst->tab)[i] = (src->tab)[0];
	(dst->size)++;
	ft_rrot(dst);
	ft_ablation(src);
	return (0);
}
