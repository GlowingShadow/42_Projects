/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 05:14:37 by REDACTED          #+#    #+#             */
/*   Updated: 2014/12/15 12:35:25 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_sign_no_digit(char **s)
{
	int		i;

	i = 0;
	while ((*s)[i] == '-' || (*s)[i] == '+')
	{
		i++;
		if ((*s)[i] == '\0')
		{
			ft_strclr(*s);
			(*s)[0] = '0';
		}
	}
}

void	ft_get_sign(char **s)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while ((*s)[i] != '\0')
	{
		if ((*s)[i] == '-')
			count++;
		i++;
	}
	i = 0;
	while (ft_isdigit((*s)[i]) == 0)
	{
		if ((*s)[i] == '+' || (*s)[i] == '-')
			(*s)[i] = ' ';
		i++;
	}
	if (0 < i)
		(*s)[i - 1] = (((count % 2) == 0) ? '+' : '-');
}

void	ft_valid_tab(char ***tmp)
{
	int		i;

	i = 0;
	while ((*tmp)[i] != NULL)
	{
		ft_sign_no_digit(&((*tmp)[i]));
		ft_get_sign(&((*tmp)[i]));
		i++;
	}
}
