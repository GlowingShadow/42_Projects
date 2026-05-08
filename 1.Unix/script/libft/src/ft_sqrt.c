/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 05:47:33 by REDACTED          #+#    #+#             */
/*   Updated: 2015/04/04 19:32:49 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_sqrt(double n)
{
	double	x;
	double	y;
	double	precision;

	x = n;
	y = 1;
	precision = 0.000001;
	while ((x - y) > precision)
	{
		x = (x + y) / 2;
		y = n / x;
	}
	return (x);
}
