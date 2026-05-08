/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 14:22:35 by exam              #+#    #+#             */
/*   Updated: 2015/01/29 14:53:06 by exam             ###   ########.fr       */
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

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		ft_putchar(s[i++]);
}

void	ft_trim(char **s)
{
	int	i;

	i = ft_strlen(*s) - 1;
	while (((*s)[i] == ' ' || (*s)[i] == '\t') && i >= 0)
		i--;
	(*s)[i + 1] = '\0';
}

int		main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	ft_trim(&(av[1]));
	if (ft_strlen(av[1]) == 0)
	{
		ft_putchar('\n');
		return (0);
	}
	i = 0;
	while (av[1][i] != '\0')
	{
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		j = i;
		while (av[1][i] != ' ' && av[1][i] != '\0' && av[1][i] != '\t')
			i++;
		if (av[1][i] != '\0')
		{
			av[1][i] = '\0';
			ft_putstr(av[1] + j);
			ft_putchar(' ');
			i++;
		}
		else
		{
			ft_putstr(av[1] + j);
			ft_putchar('\n');
			return (0);
		}
	}
	return (0);
}
