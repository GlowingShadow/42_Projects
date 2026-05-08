/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:49:40 by REDACTED          #+#    #+#             */
/*   Updated: 2015/01/23 02:21:36 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_launch_mlx(t_env *e)
{
	static int	count;

	count++;
	if (e->max_x < 100 && e->max_y < 100)
	{
		if (count == 1)
			e->win = mlx_new_window(e->mlx, (e->max_x + e->lines) * e->xrib + \
					50, e->max_y * e->yrib + 50, "FdF");
		e->img = mlx_new_image(e->mlx, (e->max_x + e->lines) * e->xrib + 50, \
				e->max_y * e->yrib + 50);
	}
	else
	{
		if (count == 1)
			e->win = mlx_new_window(e->mlx, 2550, 1350, "FdF");
		e->img = mlx_new_image(e->mlx, 2550, 1350);
	}
}
