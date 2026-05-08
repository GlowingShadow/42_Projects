/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 09:36:45 by exam              #+#    #+#             */
/*   Updated: 2014/12/04 10:00:19 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		ft_putchar(str[i++]);
}

int		ft_error(int ac, char *av)
{
	if (ac != 3)
	{
		ft_putchar('\n');
		return (-1);
	}
	if (av[0] == 0)
	{
		ft_putstr("1\n");
		return (-1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int i;
	int	j;

	if (ft_error(ac, av[1]) == -1)
		return (0);
	i = 0;
	j = 0;
	while (i < ft_strlen(av[2]))
	{
		if (av[1][j] == av[2][i])
		{
			j++;
			if (av[1][j] == 0)
			{
				ft_putstr("1\n");
				return (0);
			}
		}
		i++;
	}
	ft_putstr("0\n");
	return (0);
}
