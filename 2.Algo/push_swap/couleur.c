/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couleur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 23:13:52 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/18 00:14:00 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strcolor(char *c1, char *color, char *c2)
{
	char	*tmp;

	tmp = ft_strnew(7);
	ft_strcat(tmp, c1);
	ft_strcat(tmp, color);
	ft_strcat(tmp, c2);
	ft_putstr(tmp);
	return (tmp);
}

void	ft_putstr_color(char *color, char *str)
{
	COLOR(color);
	ft_putstr(str);
	COLOR(WHITE);
}

int		main(void)
{
	ft_putendl("llllllll");
	ft_putstr_color(GREEN, "w\n");
	COLOR(RED);
	ft_putendl("llllllll");
	ft_putendl("llllllll");

	return (0);
}
