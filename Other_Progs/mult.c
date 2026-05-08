/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 19:52:37 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/05 08:24:24 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_digit_str(int *result, int len)
{
	int	i;

	i = 0;
	while (result[i] == 0)
		i++;
	while (i < len)
	{
		ft_putchar(result[i] + 48);
		i++;
	}
	ft_putchar('\n');
}

void	ft_retenue(int **result, int len)
{
	int i;

	i = len - 1;
	while (i > 0)
	{
		(*result)[i - 1] = (*result)[i - 1] + (*result)[i] / 10;
		(*result)[i] = (*result)[i] % 10;
		i--;
	}
}

void	ft_mult(int **result, char **av)
{
	int	i;
	int	j;
	int	x;
	int ind;

	i = ft_strlen(av[2]) - 1;
	x = ft_strlen(av[2]) + ft_strlen(av[1]) - 1;
	ind = x;
	while (i >= 0)
	{
		j = ft_strlen(av[1]) - 1;
		x = ind;
		while (j >= 0)
		{
			(*result)[x] = (*result)[x] + (av[2][i] - 48) * (av[1][j] - 48);
			j--;
			x--;
		}
		i--;
		ind--;
	}
}

void	ft_negative(char ***av)
{
	int	i;

	i = 0;
	if ((*av)[1][0] == '-')
		i++;
	if ((*av)[1][0] == '-' || (*av)[1][0] == '+')
		(*av)[1] = (*av)[1] + 1;
	if ((*av)[2][0] == '-')
		i++;
	if ((*av)[2][0] == '-' || (*av)[2][0] == '+')
		(*av)[2] = (*av)[2] + 1;
	if (i == 1)
		ft_putchar('-');
}

int		ft_valid_arg(char **av)
{
	int	i;

	if (ft_strlen(av[0]) == 1 && ft_isdigit(av[0][0]) == 0)
		return (-1);
	if (ft_strlen(av[1]) == 1 && ft_isdigit(av[1][0]) == 0)
		return (-1);
	i = 0;
	if (av[0][0] == '-' || av[0][0] == '+')
		i++;
	while (av[0][i] != '\0')
	{
		if (ft_isdigit(av[0][i]) == 0)
			return (-1);
		i++;
	}
	i = 0;
	if (av[1][0] == '-' || av[1][0] == '+')
		i++;
	while (av[1][i] != '\0')
	{
		if (ft_isdigit(av[1][i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int	len;
	int	*result;

	if (ac != 3)
	{
		ft_putstr("Please enter 2 number.\n");
		return (0);
	}
	if (ft_valid_arg(av + 1) != 0)
	{
		ft_putstr("Invalid arguments\n");
		return (0);
	}
	ft_negative(&av);
	len = ft_strlen(av[1]) + ft_strlen(av[2]);
	result = (int*)malloc(sizeof(int) * len);
	ft_memset(result, 0, (sizeof(int) * len));
	ft_mult(&result, av);
	ft_retenue(&result, len);
	ft_put_digit_str(result, len);
	return (0);
}
