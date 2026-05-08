/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 09:26:04 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 09:38:33 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	i = 0;
	j = 0;
	while (av[1][i] != '\0')
	{
		if (av[1][i] == av[2][j])
			i++;
		if (av[2][j] == '\0')
		{
			ft_putchar('\n');
			return (0);
		}
		j++;
	}
	ft_putstr(av[1]);
	ft_putchar('\n');
	return (0);
}
