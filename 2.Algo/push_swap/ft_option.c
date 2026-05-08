/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 20:48:16 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/17 22:43:27 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 	-c peut faire afficher en couleur la dernière action
// 	   	-v etat des pile apres chaque action
// 	   		-a affichage du nbre d'action


void	ft_putpile(t_itab pile)
{
	int	i;

	i = 0;
	while (i < pile.size)
	{
		ft_putnbr((pile.tab)[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	ft_display(t_itab pile1, t_itab pile2)
{
	ft_putstr("\tA: ");
	ft_putpile(pile1);
	ft_putstr("\tB: ");
	ft_putpile(pile2);
	ft_putchar('\n');
}

void	ft_operations2(t_itab *pile1, t_itab *pile2, char *str)
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

int		ft_check_mvt2(t_itab pile1, t_itab pile2, char *str)
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
	ft_operations2(&pile1, &pile2, str);
	ft_putstr(str);
	ft_display(pile1, pile2);
	if (str[i + 1] == '\0')
	{
		if (ft_check_sort_int_tab(pile1.tab, pile1.size) == 1 \
				&& pile2.size == 0)
			return (1);
	}
	else
		return (ft_check_mvt2(pile1, pile2, str + i + 1));
	return (0);
}

void	ft_option(char *opt, t_mvt mvt, t_itab pile1, t_itab pile2)
{
	if (ft_strchr(opt, 'a') != NULL)
	{
		ft_putstr("\tNombre d'operations: ");
		ft_putnbr(mvt.count);
		ft_putstr("\n\n");
	}
	if (ft_strchr(opt, 'v') != NULL)
	{
		ft_display(pile1, pile2);
		ft_check_mvt2(pile1, pile2, ft_strjoin(mvt.str, " "));
	}
	if (ft_strchr(opt, 'a') != NULL)
	{
		ft_putstr("\tNombre d'operations: ");
		ft_putnbr(mvt.count);
		ft_putchar('\n');
	}
}
