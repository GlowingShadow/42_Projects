/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_bonus2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 00:46:13 by REDACTED          #+#    #+#             */
/*   Updated: 2015/06/04 08:46:17 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_draw_bg(t_env *e, int x, int y)
{
	t_im	im1;
	t_im	im2;
	int		tmp1;
	int		tmp2;
	int		tmp3;

	im1.px = mlx_get_data_addr(e->xpm[0], &im1.bpp, &im1.sizeline, &im1.endian);
	im2.px = mlx_get_data_addr(e->img, &im2.bpp, &im2.sizeline, &im2.endian);
	tmp3 = (int)((e->cam_mid / 360.0) * (e->zoom == 0 ? SKY : SKY * 2.0));
	while (y < 300)
	{
		x = 0;
		while (x < e->win_x)
		{
			tmp1 = y * im1.sizeline + (im1.bpp / 8) * (x - tmp3);
			tmp2 = y * im2.sizeline + (im2.bpp / 8) * x;
			im2.px[tmp2 + 0] = co(im1.px[tmp1 + 0], e->shad_coef);
			im2.px[tmp2 + 1] = co(im1.px[tmp1 + 1], e->shad_coef);
			im2.px[tmp2 + 2] = co(im1.px[tmp1 + 2], e->shad_coef);
			x++;
		}
		y++;
	}
}

void			ft_draw_gun(t_env *e, int y, int diffx, int diffy)
{
	t_im	src;
	t_im	dst;
	int		tmp1;
	int		tmp2;
	int		x;

	src.px = mlx_get_data_addr(e->xpm[1], &src.bpp, &src.sizeline, &src.endian);
	dst.px = mlx_get_data_addr(e->img, &dst.bpp, &dst.sizeline, &dst.endian);
	while (y < 190)
	{
		x = 0;
		while (x < 280)
		{
			tmp1 = y * src.sizeline + (src.bpp / 8) * x;
			if (src.px[tmp1 + 3] != -1)
			{
				tmp2 = (y + diffy) * dst.sizeline + (dst.bpp / 8) * (x + diffx);
				dst.px[tmp2] = src.px[tmp1];
				dst.px[tmp2 + 1] = src.px[tmp1 + 1];
				dst.px[tmp2 + 2] = src.px[tmp1 + 2];
			}
			x++;
		}
		y++;
	}
}

static float	ft_calc_coef(t_env *e, float dist)
{
	float	coef;

	coef = 1.00000 - (dist / ((float)e->BS * e->shad_len));
	coef = (coef < 0.0) ? 0.0 : coef;
	coef += e->shad_coef;
	coef = (coef > 1.0) ? 1.0 : coef;
	return (coef);
}

void			ft_floor(t_env *e, t_bin coo, float ray, t_im ptr)
{
	float	dist;
	t_floor	f;
	t_fbin	data;

	data.cos_ray_minus_cam_mid = cosf(dtor(ray - e->cam_mid));
	data.cos_ray = cosf(dtor(ray));
	data.sin_ray = sinf(dtor(ray));
	while (coo.v < 600)
	{
		dist = e->sol[coo.v - 300] / data.cos_ray_minus_cam_mid;
		dist = (e->zoom == 1 ? 2 * dist : dist);
		f.tx = e->cam_x + data.cos_ray * dist;
		f.ty = e->cam_y - data.sin_ray * dist;
		if (f.ty >= 0.0 && f.tx >= 0.0)
		{
			f.x = (int)(1414.0 * ft_fmodulo(f.tx, (float)e->BS) / (float)e->BS);
			f.y = (int)(1239.0 * ft_fmodulo(f.ty, (float)e->BS) / (float)e->BS);
			f.coef = ft_calc_coef(e, dist);
			ft_mlx_image_pixel_put(*e, coo.h, coo.v, RGB(\
				co(ptr.px[f.y * ptr.SL + (ptr.bpp / 8) * f.x + 2], f.coef), \
				co(ptr.px[f.y * ptr.SL + (ptr.bpp / 8) * f.x + 1], f.coef), \
				co(ptr.px[f.y * ptr.SL + (ptr.bpp / 8) * f.x + 0], f.coef)));
		}
		(coo.v)++;
	}
}

void			ft_draw_floor2(t_env *e, int x, int y)
{
	t_im	im;
	int		tmp;

	im.px = mlx_get_data_addr(e->img, &im.bpp, &im.sizeline, &im.endian);
	while (y < e->win_y)
	{
		x = 0;
		while (x < e->win_x)
		{
			tmp = y * im.sizeline + (im.bpp / 8) * x;
			im.px[tmp] = 144;
			im.px[tmp + 1] = 0;
			im.px[tmp + 2] = 50;
			x++;
		}
		y++;
	}
}
