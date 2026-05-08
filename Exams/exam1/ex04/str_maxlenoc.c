/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 10:35:42 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 12:31:55 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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
	{
		ft_putchar(s[i]);
		i++;
	}
}

char	*ft_smaller(char **av)
{
	int	i;
	int	j;
	int	*count;

	i = 0;
	count = (int*)malloc(sizeof(int) * 2);
	count[1] = 2100000000;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0')
			j++;
		if (count[1] > j)
		{
			count[0] = i;
			count[1] = j;
		}
		i++;
	}
	return (av[count[0]]);
}

int		ft_char_in_tab(char **tab, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i] != NULL && tab[i][j] != '\0')
	{
		if (tab[i][j] == c)
		{
			i++;
			j = -1;
			if (tab[i] == NULL)
				return (1);
		}
		j++;
	}
	return (0);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dst;

	i = 0;
	while (src[i] != '\0')
		i++;
	dst = (char*)malloc(sizeof(char) * i + 1);
	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int		ft_strchr(char *s1, char *s2)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		i = 0;
		while (s1[i] != s2[j])
		{
			j++;
			if (s2[j] == '\0')
				return (0);
		}
		while (s1[i] == s2[j])
		{
			i++;
			j++;
			if (s1[i] == '\0')
				return (1);
		}
	}
	return (0);
}

int		ft_tabchr(char **tab, char *s)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (ft_strchr(s, tab[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strsub(char *s, int i, int len)
{
	char	*dst;

	dst = ft_strdup(s + i);
	dst[len] = '\0';
	return (dst);
}

int		main(int ac, char **av)
{
	char	*small;
	int		i;
	int		j;
	int		maxlen;
	char	*tmp;
	char	*s;

	if (ac == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	tmp = (char*)malloc(sizeof(char) * 1);
	tmp[0] = '\0';
	small = ft_strdup(ft_smaller(av + 1));
	maxlen = ft_strlen(small);
	i = 0;
	j = 0;
	while (i < maxlen)
	{
		j = maxlen - i;
		while (0 < j)
		{
			if (ft_tabchr(av + 1, ft_strsub(small, i, j)) == 1)
				if (ft_strlen(tmp) < ft_strlen(ft_strsub(small, i, j)))
				{
					s = tmp;
					tmp = ft_strdup(ft_strsub(small, i, j));
					free(s);
				}
			j--;
		}
		i++;
	}
	ft_putstr(tmp);
	ft_putchar('\n');
	return (0);
}
