/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 13:45:49 by REDACTED          #+#    #+#             */
/*   Updated: 2015/04/04 08:11:40 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int		ft_isoperand(char c)
{
	if (c == '-' || c == '+' || c == '=' || c == '*')
		return (1);
	return (0);
}

int		ft_isnumber(char *str)
{
	int		i;
	int		flt;

	i = 0;
	flt = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			i++;
			flt++;
		}
		else if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (flt > 1 || ft_strcmp(str, ".") == 0 || ft_strlen(str) > 300)
		return (0);
	return (1);
}

int		ft_ismult(char *str)
{
	if (ft_strlen(str) != 1)
		return (0);
	if (str[0] != '*')
		return (0);
	return (1);
}

int		ft_isoperand_str(char *str)
{
	if (ft_strlen(str) != 1)
		return (0);
	if (str[0] != '*' && str[0] != '-' && str[0] != '+')
		return (0);
	return (1);
}

int		ft_ispower(char *str)
{
	int		i;

	if (ft_strlen(str) < 3)
		return (0);
	if (str[0] != 'X' || str[1] != '^')
		return (0);
	i = 2;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (ft_strlen(str + 2) > 10)
		return (0);
	if (ft_strlen(str + 2) == 10 && ft_strcmp("2147483647", str + 2) <= 0)
		return (0);
	return (1);
}
