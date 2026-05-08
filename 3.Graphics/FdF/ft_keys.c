/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 02:25:32 by REDACTED          #+#    #+#             */
/*   Updated: 2015/01/27 04:36:56 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move_right(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	e->move_x = e->move_x - 10;
	e->coor = ft_assign_xy2(e->pts, *e, 0);
	ft_launch_mlx(e);
	ft_expose_hook(e);
}

void	ft_move_left(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	e->move_x = e->move_x + 10;
	e->coor = ft_assign_xy2(e->pts, *e, 0);
	ft_launch_mlx(e);
	ft_expose_hook(e);
}

void	ft_move_down(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	e->move_y = e->move_y - 10;
	e->coor = ft_assign_xy2(e->pts, *e, 0);
	ft_launch_mlx(e);
	ft_expose_hook(e);
}

void	ft_move_up(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	e->move_y = e->move_y + 10;
	e->coor = ft_assign_xy2(e->pts, *e, 0);
	ft_launch_mlx(e);
	ft_expose_hook(e);
}

void	ft_zoom(t_env *e, int keycode)
{
	mlx_destroy_image(e->mlx, e->img);
	if (keycode == 65451)
	{
		e->c_edge = e->c_edge * 1.1;
		e->c_haut = e->c_haut * 1.1;
		e->coor = ft_assign_xy2(e->pts, *e, 0);
		ft_launch_mlx(e);
		ft_expose_hook(e);
	}
	if (keycode == 65453)
	{
		e->c_edge = e->c_edge / 1.1;
		e->c_haut = e->c_haut / 1.1;
		e->coor = ft_assign_xy2(e->pts, *e, 0);
		ft_launch_mlx(e);
		ft_expose_hook(e);
	}
}
