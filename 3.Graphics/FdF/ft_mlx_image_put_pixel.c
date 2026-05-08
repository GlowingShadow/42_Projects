/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_image_put_pixel.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 15:57:20 by REDACTED          #+#    #+#             */
/*   Updated: 2015/01/23 02:18:47 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_mlx_image_pixel_put(t_env e, int x, int y, int color)
{
	char			*pixel;
	int				bpp;
	int				sizeline;
	int				endian;
	unsigned int	new_color;

	if ((e.max_y <= 100 && e.max_x <= 100 && \
			(x > ((e.max_x + e.lines) * e.xrib + 50) \
			|| y > (e.max_y * e.yrib + 50) || x < 0 || y < 0)) \
			|| ((e.max_y > 100 || e.max_x > 100) && (x > 2550 || y > 1350 \
			|| x < 0 || y < 0)))
		return (0);
	new_color = mlx_get_color_value(e.mlx, color);
	pixel = mlx_get_data_addr(e.img, &bpp, &sizeline, &endian);
	pixel[y * sizeline + (bpp / 8) * x] = (new_color & 0xFF);
	pixel[y * sizeline + (bpp / 8) * x + 1] = (new_color & 0xFF00) >> 8;
	pixel[y * sizeline + (bpp / 8) * x + 2] = (new_color & 0xFF0000) >> 16;
	return (0);
}
