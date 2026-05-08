/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 09:44:25 by exam              #+#    #+#             */
/*   Updated: 2015/03/05 09:54:50 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		main(int ac, char **av)
{
	int		i;

	if (ac != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	i = ft_strlen(av[1]);
	while (i >= 0)
	{
		while (i >= 0 && av[1][i] != ' ' && av[1][i] != '\t')
			i--;
		ft_putstr(av[1] + i + 1);
		if (i != -1)
			ft_putchar(av[1][i]);
		av[1][i] = '\0';
	}
	ft_putchar('\n');
	return (0);
}
