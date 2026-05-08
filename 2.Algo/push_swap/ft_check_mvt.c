/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_mvt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 03:29:53 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/17 22:49:24 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_operations(t_itab *pile1, t_itab *pile2, char *str)
{
	if (ft_strcmp(str, "sa") == 0 && pile1->size >= 2)
		ft_swap(pile1);
	if (ft_strcmp(str, "sb") == 0 && pile2->size >= 2)
		ft_swap(pile2);
	if (ft_strcmp(str, "ss") == 0 && pile1->size >= 2 && pile2->size >= 2)
		ft_sswap(pile1, pile2);
	if (ft_strcmp(str, "pa") == 0 && pile2->size >= 1)
		ft_push(pile2, pile1);
	if (ft_strcmp(str, "pb") == 0 && pile1->size >= 1)
		ft_push(pile1, pile2);
	if (ft_strcmp(str, "ra") == 0 && pile1->size >= 2)
		ft_rot(pile1);
	if (ft_strcmp(str, "rb") == 0 && pile2->size >= 2)
		ft_rot(pile2);
	if (ft_strcmp(str, "rr") == 0 && pile1->size >= 2 && pile2->size >= 2)
		ft_rot_all(pile1, pile2);
	if (ft_strcmp(str, "rra") == 0 && pile1->size >= 2)
		ft_rrot(pile1);
	if (ft_strcmp(str, "rrb") == 0 && pile2->size >= 2)
		ft_rrot(pile2);
	if (ft_strcmp(str, "rrr") == 0 && pile1->size >= 2 && pile2->size >= 2)
		ft_rrot_all(pile1, pile2);
}

int		ft_check_mvt(t_itab pile1, t_itab pile2, char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 1)
	{
		ft_putchar('d');
		if (ft_check_sort_int_tab(pile1.tab, pile1.size) == 1 \
				&& pile2.size == 0)
			return (1);
		else
			return (0);
	}
	while (str[i] != ' ')
		i++;
	str[i] = '\0';
	ft_operations(&pile1, &pile2, str);
	if (str[i + 1] == '\0')
	{
		if (ft_check_sort_int_tab(pile1.tab, pile1.size) == 1 \
				&& pile2.size == 0)
			return (1);
	}
	else
		return (ft_check_mvt(pile1, pile2, str + i + 1));
	return (0);
}
