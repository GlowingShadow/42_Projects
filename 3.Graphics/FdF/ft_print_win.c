/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 10:19:14 by REDACTED          #+#    #+#             */
/*   Updated: 2015/01/22 17:31:57 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_points(t_env e, t_coo **coor)
{
	int		i;
	int		j;

	i = 0;
	while (coor[i] != NULL)
	{
		j = 1;
		while (j < (coor[i][0]).z)
		{
			ft_mlx_image_pixel_put(e, (coor[i][j]).x, (coor[i][j]).y, \
					ft_color((coor[i][j]).z, e));
			j++;
		}
		i++;
	}
}

void	line1(t_coo coor1, t_coo coor2, t_env e, int cas)
{
	int		x;
	int		x1;
	int		x2;
	int		y1;
	int		y2;

	x1 = coor1.x;
	y1 = coor1.y;
	x2 = coor2.x;
	y2 = coor2.y;
	x = x1 + 1;
	while (x <= x2)
	{
		ft_mlx_image_pixel_put(e, x, y1 + ((y2 - y1) * (x - x1)) / (x2 - x1),
				ft_color(ft_altitude(x, cas, coor1, coor2), e));
		x++;
	}
}

void	line2(t_coo coor1, t_coo coor2, t_env e, int cas)
{
	int		x;
	int		x1;
	int		x2;
	int		y1;
	int		y2;

	y1 = coor1.x;
	x1 = coor1.y;
	y2 = coor2.x;
	x2 = coor2.y;
	x = x1 + 1;
	while (x <= x2)
	{
		if ((coor1.z != 0 || coor2.z != 0) && (coor1.z - coor2.z) != 0)
			ft_mlx_image_pixel_put(e, \
					y1 + ((y2 - y1) * (x - x1)) / (x2 - x1), x, \
					ft_color(ft_altitude(x, cas, coor1, coor2), e));
		x++;
	}
}

void	ft_print_line2(t_env e, t_coo **coor)
{
	int		i;
	int		j;

	i = 0;
	while (coor[i + 1] != NULL)
	{
		j = 1;
		while (j < (coor[i][0]).z && j < (coor[i + 1][0]).z)
		{
			if (ft_c12(coor[i][j], coor[i + 1][j]) == 1)
				line1(coor[i][j], coor[i + 1][j], e, 12);
			else if (ft_c34(coor[i][j], coor[i + 1][j]) == 1)
				line1(coor[i + 1][j], coor[i][j], e, 34);
			else if (ft_c56(coor[i][j], coor[i + 1][j]) == 1)
				line2(coor[i][j], coor[i + 1][j], e, 56);
			else if (ft_c78(coor[i][j], coor[i + 1][j]) == 1)
				line2(coor[i + 1][j], coor[i][j], e, 78);
			j++;
		}
		i++;
		while (coor[i + 1] != NULL && \
				((coor[i][0]).z == 1 || (coor[i + 1][0]).z == 1))
			i++;
	}
}

void	ft_print_line1(t_env e, t_coo **coor)
{
	int		i;
	int		j;

	i = 0;
	while (coor[i] != NULL)
	{
		j = 1;
		while (j < (coor[i][0]).z - 1)
		{
			if (ft_c12(coor[i][j], coor[i][j + 1]) == 1)
				line1(coor[i][j], coor[i][j + 1], e, 12);
			else if (ft_c34(coor[i][j], coor[i][j + 1]) == 1)
				line1(coor[i][j + 1], coor[i][j], e, 34);
			else if (ft_c56(coor[i][j], coor[i][j + 1]) == 1)
				line2(coor[i][j], coor[i][j + 1], e, 56);
			else if (ft_c78(coor[i][j], coor[i][j + 1]) == 1)
				line2(coor[i][j + 1], coor[i][j], e, 78);
			j++;
		}
		i++;
	}
}
