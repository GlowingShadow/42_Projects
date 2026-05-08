/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 14:08:30 by REDACTED          #+#    #+#             */
/*   Updated: 2015/02/08 14:51:00 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_max(char *str)
{
	if (ft_strlen(str) < 10)
		return (1);
	else if (ft_strlen(str) > 10)
		return (0);
	if (ft_strcmp("2147483647", str) < 0)
		return (0);
	return (1);
}

int		ft_check_min(char *str)
{
	if (ft_strlen(str) < 11)
		return (1);
	else if (ft_strlen(str) > 11)
		return (0);
	if (ft_strcmp("-2147483648", str) < 0)
		return (0);
	return (1);
}

int		ft_check_integer(char *str)
{
	if (str[0] == '-')
	{
		if (ft_check_min(str) == 1)
			return (1);
	}
	else
	{
		if (ft_check_max(str) == 1)
			return (1);
	}
	return (0);
}
