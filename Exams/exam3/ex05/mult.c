/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 11:53:06 by exam              #+#    #+#             */
/*   Updated: 2015/03/05 12:32:49 by exam             ###   ########.fr       */
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

void	ft_retenue(int **result, int len)
{
	int		i;

	i = len - 1;
	while (i > 0)
	{
		(*result)[i - 1] = (*result)[i - 1] + (*result)[i] / 10;
		(*result)[i] = (*result)[i] % 10;
		i--;
	}
}

int		ft_check(char **av)
{
	if (ft_strlen(av[1]) == 1 && av[1][0] == '0')
		return (0);
	if (ft_strlen(av[2]) == 1 && av[2][0] == '0')
		return (0);
	return (1);
}

void	ft_negative(char ***av)
{
	int		i;

	i = 0;
	if ((*av)[1][0] == '-')
	{
		(*av)[1] = (*av)[1] + 1;
		i++;
	}
	if ((*av)[2][0] == '-')
	{
		(*av)[2] = (*av)[2] + 1;
		i++;
	}
	if (i == 1 && ft_check(*av) == 1)
		ft_putchar('-');
}

void	ft_putdigit(int *result, int len)
{
	int	i;

	i = 0;
	while (result[i] == 0 && i < len)
		i++;
	if (result[i] == '\0')
		ft_putchar(48);
	while (i < len)
	{
		ft_putchar(result[i] + 48);
		i++;;
	}
	ft_putchar('\n');
}

void	ft_calc(int *result, int len, char *s1, char *s2)
{
	int		i;
	int		j;
	int		x;
	int		tmp;

	i = ft_strlen(s1) - 1;
	tmp = len - 1;
	while (i >= 0)
	{
		j = ft_strlen(s2) - 1;
		x = tmp;
		while (j >= 0)
		{
			result[x] = result[x] + (s1[i] - 48) * (s2[j] - 48);
			j--;
			x--;
		}
		i--;
		tmp--;
	}
	ft_retenue(&result, len);
	ft_putdigit(result, len);
}

int		main(int ac, char **av)
{
	int	*result;
	int	i;
	int	j;

	ac = ac;
	ft_negative(&av);
	i = ft_strlen(av[1]) + ft_strlen(av[2]);
	result = (int*)malloc(sizeof(int) * i);
	j = 0;
	while (j < i)
	{
		result[j] = 0;
		j++;
	}
	ft_calc(result, i, av[1], av[2]);
	return (0);
}
