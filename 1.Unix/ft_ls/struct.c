/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 06:49:50 by REDACTED          #+#    #+#             */
/*   Updated: 2014/11/20 02:40:55 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

int		main(void)
{
	int		i;
	t_data	**tab;

	i = 0;
	tab = (t_data**)malloc(sizeof(t_data*) * 10 + 1);

	while (i < 11)
	{
		tab[i] = (t_data*)malloc(sizeof(t_data) * 1 + 1);
		ft_putchar('*');
		(tab[i])->fmode = "drwxrwxrwx";
		(tab[i])->links = 1;
		(tab[i])->group = "2014_paris";
		(tab[i])->bytes = 452202;
		(tab[i])->date = "Nov 16 13:30";
		(tab[i])->owner = "REDACTED";
		(tab[i])->file = "coucou";
		i++;
	}
	i = 0;
		ft_putchar('\n');
		while (tab[i])
	{
		ft_putstr((tab[i])->fmode);
		ft_putstr(" - ");
		ft_putnbr((tab[i])->links);
		ft_putstr(" - ");
		ft_putstr((tab[i])->owner);
		ft_putstr(" - ");
		ft_putstr((tab[i])->group);
		ft_putstr(" - ");
		ft_putnbr((tab[i])->bytes);
		ft_putstr(" - ");
		ft_putstr((tab[i])->date);
		ft_putstr(" - ");
		ft_putstr((tab[i])->file);
		ft_putchar('\n');
		i++;
	}


	return (0);
}
