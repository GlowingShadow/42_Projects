/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 09:54:53 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 10:32:43 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		ft_strchr(char *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[j] != '\0' && j < i)
	{
		if (s[j] == c)
			return (1);
		j++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int	i;

	if (ac != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	i = 0;
	while (av[1][i] != '\0')
	{
		if (i == 0 && ft_strchr(av[2], av[1][i], ft_strlen(av[2])) == 1)
			ft_putchar(av[1][i]);
		else if (ft_strchr(av[1], av[1][i], i) == 0)
			if (ft_strchr(av[2], av[1][i], ft_strlen(av[2])) == 1)
				ft_putchar(av[1][i]);
		i++;
	}
	ft_putchar ('\n');
	return (0);
}
