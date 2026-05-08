/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 09:11:32 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 09:21:36 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_isalpha_upper(char c)
{
	if (c > 64 && c < 91)
		return (1);
	return (0);
}

int		ft_isalpha_lower(char c)
{
	if (c > 96 && c < 123)
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int	i;

	if (ac != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	i = 0;
	while (av[1][i] != '\0')
	{
		if (ft_isalpha_lower(av[1][i]) == 1)
			ft_putchar(av[1][i] - 32);
		else if (ft_isalpha_upper(av[1][i]) == 1)
			ft_putchar(av[1][i] + 32);
		else
			ft_putchar(av[1][i]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
