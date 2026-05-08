/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 10:42:20 by exam              #+#    #+#             */
/*   Updated: 2015/03/05 18:09:07 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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

int		small(char **av)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (av[i] != NULL)
	{
		if (ft_strlen(av[i]) < ft_strlen(av[x]))
			x = i;
		i++;
	}
	return (x);
}

char	*ft_strdup(char *str)
{
	char	*dst;
	int		i;

	dst = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	while (str[i] != '\0')
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strsub(char *str, int len)
{
	char	*dst;

	dst = ft_strdup(str);
	dst[len] = '\0';
	return (dst);
}

int		ft_is_in(char *av, char *s)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	x = 0;
	while (av[i] != '\0')
	{
		j = 0;
		while (av[x] == s[j])
		{
			x++;
			j++;
			if (s[j] == '\0')
				return (1);
		}
		i++;
		x = i;
	}
	return (0);
}

int		ft_in_all(char *s, char **av)
{
	int		i;

	i = 0;
	while (av[i] != NULL)
	{
		if (ft_is_in(av[i], s) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_moulinette(char *s, char **av)
{
	int		i;
	int		j;
	char	*tmp;
	char	*max;

	tmp = "";
	max = "";
	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i + j] != '\0')
		{
			if (ft_in_all(ft_strsub(s + i, j), av) == 1)
				tmp = ft_strsub(s + i, j);
			if (ft_strlen(tmp) > ft_strlen(max))
				max = tmp;
			j++;
		}
		i++;
	}
	ft_putstr(max);
}

int		main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_putchar('\n');
		return (0);
	}
	av = av + 1;
	ft_moulinette(av[small(av)], av);
	ft_putchar('\n');
	return (0);
}
