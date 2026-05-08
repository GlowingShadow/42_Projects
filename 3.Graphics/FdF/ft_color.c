/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 13:21:08 by REDACTED          #+#    #+#             */
/*   Updated: 2015/01/22 17:33:47 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color(double t, t_env e)
{
	int		i;

	if (e.diffz != 0)
		t = t / e.diffz * 5;
	i = RGB(127.5 * (cos(t) + 1), 127.5 * (sin(t) + 1), 127.5 * (1 - cos(t)));
	return (i);
}

int		ft_couleur_ulysse(int alt)
{
	int alt1;
	int alt2;
	int col1;
	int col2;

	alt1 = 0;
	alt2 = 1000;
	col1 = 0xFFFFFF;
	col2 = 0x00FF00;
	return (((alt - alt1) % (alt2 - alt1)) * (col2 - col1) / (alt2 - alt1));
}
