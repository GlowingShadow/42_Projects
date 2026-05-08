/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:22:08 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/15 19:09:21 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rot(t_itab *pile)
{
	int	i;

	i = 0;
	while (i < (pile->size - 1))
	{
		ft_intswap(&((pile->tab)[i]), &((pile->tab)[i + 1]));
		i++;
	}
}

void	ft_rrot(t_itab *pile)
{
	int	i;

	i = pile->size - 1;
	while (i != 0)
	{
		ft_intswap(&((pile->tab)[i]), &((pile->tab)[i - 1]));
		i--;
	}
}

void	ft_rot_all(t_itab *pile1, t_itab *pile2)
{
	ft_rot(pile1);
	ft_rot(pile2);
}

void	ft_rrot_all(t_itab *pile1, t_itab *pile2)
{
	ft_rrot(pile1);
	ft_rrot(pile2);
}
