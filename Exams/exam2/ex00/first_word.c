/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 14:05:31 by exam              #+#    #+#             */
/*   Updated: 2015/01/29 14:19:50 by exam             ###   ########.fr       */
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
	return (0);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		ft_putchar(s[i++]);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	i = 0;
	while (av[1][i] == ' ' || av[1][i] == '\t')
		i++;
	j = i;
	while (av[1][i] != ' ' && av[1][i] != '\0' && av[1][i] != '\t')
		i++;
	av[1][i] = '\0';
	ft_putstr(av[1] + j);
	ft_putchar('\n');
	return (0);
}
