/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 10:10:59 by exam              #+#    #+#             */
/*   Updated: 2014/12/08 12:43:34 by REDACTED         ###   ########.fr       */
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

int		ft_error(int ac)
{
	if (ac != 3)
	{
		ft_putchar('\n');
		return (-1);
	}
	return (0);
}

int		ft_strchr(char *str, char c, int i)
{
	int		j;

	j = 0;
	while (j < i && str[j] != c)
	{
		j++;
		if (j == i)
			return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	int		i;

	if (ft_error(ac) == -1)
		return (0);
	ft_putchar(av[1][0]);
	i = 1;
	if (ft_strlen(av[1]) > 0)
		while (av[1][i] != 0)
		{
			if (ft_strchr(av[1], av[1][i], i) == 0)
				ft_putchar(av[1][i]);
			i++;
		}
	i = 0;
	while (av[2][i] != 0)
	{
		if (i == 0 && ft_strchr(av[1], av[2][i], ft_strlen(av[1])) == 0)
			ft_putchar(av[2][i]);
		if (ft_strchr(av[1], av[2][i], ft_strlen(av[1])) == 0 && \
				ft_strchr(av[2], av[2][i], i) == 0)
			ft_putchar(av[2][i]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
