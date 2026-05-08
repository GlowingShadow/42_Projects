/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:29:29 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/17 20:32:35 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear_symbol(char ***av)
{
	int	i;

	i = 0;
	while ((*av)[i] != NULL)
	{
		if ((*av)[i][0] == '+' && ft_isnumber((*av)[i]) == 1)
			(*av)[i] = (*av)[i] + 1;
		i++;
	}

}

int		ft_integer(char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
	{
		if (ft_check_integer(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_only_digit(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i] != NULL)
	{
		j = 1;
		if ((ft_isdigit(av[i][0]) == 0 && av[i][0] != '-' && av[i][0] != '+') \
				|| (ft_strlen(av[i]) == 1 && ft_isdigit(av[i][0]) == 0))
			return (0);
		while (av[i][j] != '\0')
		{
			if (ft_isdigit(av[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_no_double(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[j] != NULL)
		{
			if (ft_strcmp(av[i], av[j]) == 0 && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_valid_argv(char **av)
{
	ft_clear_symbol(&av);
	ft_clear_zero(&av);
/*	ft_putendl("--------------");
	ft_puttab(av);
	ft_putendl("))))))))))");
*/	if (ft_only_digit(av) == 0)
	{
		ft_putendl("Error: Only digits please");
		exit(-1);
	}
	if (ft_integer(av) == 0)
	{
		ft_putendl("Error: Only integers please");
		exit(-1);
	}
	if (ft_no_double(av) == 0)
	{
		ft_putendl("Error: No duplicate numbers please");
		exit(-1);
	}
}
