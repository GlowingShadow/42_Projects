/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 21:10:59 by REDACTED          #+#    #+#             */
/*   Updated: 2015/05/18 08:42:29 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_draw_background(t_env *e, int color)
{
	int		x;
	int		y;
	double	ratio;

	y = 0;
	while (y < e->win_y)
	{
		x = 0;
		ratio = (double)(e->win_y - y) / (double)(e->win_y);
		while (x < e->win_x)
		{
			if (y <= e->win_y / 2)
			{
				color = 0x2ED0E9 - ((1 - ratio) / 20000) * 0x2ED0E9;
				ft_mlx_image_pixel_put(*e, x, y, color);
			}
			else if (y > e->win_y / 2)
			{
				color = 0x2ADB6B + (ratio / 30000) * 0x2ADB6B;
				ft_mlx_image_pixel_put(*e, x, y, color);
			}
			x++;
		}
		y++;
	}
}
void	ft_draw_cam(t_env *e)
{

}

static void	ft_draw_minimap(t_env *e, t_map *tmp, int x, int y)
{
	t_map	*tmp2;

	tmp2 = e->map;
	while (y < e->win_y)
	{
		if ((y % e->block_size) == 0 && y != 0 && tmp->next != NULL)
			tmp2 = tmp->next;
		tmp = tmp2;
		x = 0;
		while (x < e->win_x)
		{
			if ((x % e->block_size) == 0 && x != 0 && tmp->next != NULL)
				tmp = tmp->next;
			if ((x % e->block_size) < 2 || (y % e->block_size) < 2)
			{
				if ((((x % e->block_size) < 2) \
					&& (tmp->wall == 1 || tmp->left->wall == 1)) \
					|| ((y % e->block_size) < 2 \
					&& (tmp->wall == 1 || tmp->up->wall == 1)))
					ft_mlx_image_pixel_put(*e, x, y, 0xffffff);
			}
			x++;
		}
		y++;
	}
}

static void	ft_test_wall(t_env *e)
{
	int	x;
	int	y;
	int	w;

	x = 0;
	while (x < e->win_y)
	{
		y = 0;
		while (y < e->win_x)
		{
			if (y > x && y < e->win_y - x)
			{
				w = 0xFF0000;
				ft_mlx_image_pixel_put(*e, x, y, w);
			}
			y++;
		}
		x++;
	}
}

void		ft_draw(t_env *e)
{
	ft_draw_background(e, 0);
//	ft_test_wall(e);
	ft_draw_cam(e);
	ft_draw_minimap(e, NULL, 0, 0);
}
