/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diff_altitude.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 13:57:06 by REDACTED          #+#    #+#             */
/*   Updated: 2015/01/21 14:09:07 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_diff_altitude(int **n)
{
	int	i;
	int	j;
	int	min;
	int	max;

	i = 0;
	min = n[0][1];
	max = n[0][1];
	while (n[i] != NULL)
	{
		j = 1;
		while (j < n[i][0])
		{
			if (max < n[i][j])
				max = n[i][j];
			if (min > n[i][j])
				min = n[i][j];
			j++;
		}
		i++;
	}
	return (max - min);
}
