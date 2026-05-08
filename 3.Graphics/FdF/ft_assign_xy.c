/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_xy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 09:38:07 by REDACTED          #+#    #+#             */
/*   Updated: 2015/01/26 13:38:06 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coo	**ft_assign_xy2(int **pts, t_env e, int i)
{
	int		j;
	t_coo	**coor;

	coor = (t_coo**)malloc(sizeof(t_coo*) * ft_tablen_int(pts) + 1);
	while ((pts)[i] != NULL)
	{
		j = 1;
		coor[i] = (t_coo*)malloc(sizeof(t_coo) * pts[i][0]);
		(coor[i][0]).z = pts[i][0];
		while (j < pts[i][0])
		{
			(coor[i][j]).x = 50 + e.move_x + e.xrib * e.lines + e.lines / 3 + \
					CTE1 * ((j - 1) * e.edge * e.c_edge) - \
					CTE2 * (i * e.edge * e.c_edge);
			(coor[i][j]).y = 50 + e.move_y - e.haut * e.c_haut * pts[i][j] + \
					(CTE1 * ((j - 1) * e.edge * e.c_edge)) / 2 + \
					(CTE2 * (i * e.edge * e.c_edge)) / 2;
			(coor[i][j]).z = pts[i][j];
			j++;
		}
		i++;
	}
	coor[i] = NULL;
	return (coor);
}

void	ft_coef(t_env *e)
{
	e->c_edge = 1;
	e->c_haut = 1;
	e->move_x = 0;
	e->move_y = 0;
}

void	ft_constants(t_env *e, int **pts)
{
	e->diffz = ft_diff_altitude(pts);
	if (e->max_x < 100 && e->max_y < 100)
	{
		e->edge = 30;
		e->haut = 4;
		e->xrib = 25;
		e->yrib = 13;
	}
	else
	{
		if (e->max_x > e->max_y)
		{
			e->edge = 3000 / e->max_x;
			e->xrib = e->edge;
			e->yrib = (e->xrib + 1) / 2;
			e->haut = (float)e->edge / 15;
		}
		else
		{
			e->edge = 3000 / e->max_y;
			e->xrib = e->edge * 5 / 6;
			e->yrib = (e->xrib + 1) / 2;
			e->haut = (float)e->edge / 15;
		}
	}
}

void	ft_no_points(t_env *e)
{
	e->pts = (int**)malloc(sizeof(int*) * 2);
	(e->pts)[0] = (int*)malloc(sizeof(int) * 1);
	(e->pts)[0][0] = 1;
	(e->pts)[1] = NULL;
}
