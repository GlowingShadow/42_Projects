/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_image_put_pixel.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 15:57:20 by REDACTED          #+#    #+#             */
/*   Updated: 2015/05/30 13:21:13 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc_aff.h>

void		ft_mlx_image_pixel_put2(t_img *image, int x, int y, int color)
{
	char			*pixel;
	int				bpp;
	int				sizeline;
	int				endian;
	unsigned int	new_color;

	if (x >= image->width || y >= image->height || y < 0 || x < 0)
		return ;
	new_color = mlx_get_color_value(image->mlx, color);
	pixel = mlx_get_data_addr(image->xpm, &bpp, &sizeline, &endian);
	pixel[y * sizeline + (bpp / 8) * x] = (new_color & 0xFF);
	pixel[y * sizeline + (bpp / 8) * x + 1] = (new_color & 0xFF00) >> 8;
	pixel[y * sizeline + (bpp / 8) * x + 2] = (new_color & 0xFF0000) >> 16;
	pixel[y * sizeline + (bpp / 8) * x + 3] = 0;
}

int			ft_mlx_image_pixel_put(t_env *e, int x, int y, int color)
{
	char			*pixel;
	int				bpp;
	int				sizeline;
	int				endian;
	unsigned int	new_color;

	if (x >= e->win_x || y >= e->win_y || y < 0 || x < 0)
		return (0);
	new_color = mlx_get_color_value(e->mlx, color);
	pixel = mlx_get_data_addr(e->img, &bpp, &sizeline, &endian);
	pixel[y * sizeline + (bpp / 8) * x] = (new_color & 0xFF);
	pixel[y * sizeline + (bpp / 8) * x + 1] = (new_color & 0xFF00) >> 8;
	pixel[y * sizeline + (bpp / 8) * x + 2] = (new_color & 0xFF0000) >> 16;
	pixel[y * sizeline + (bpp / 8) * x + 3] = 0;
	return (0);
}

void		ft_mlx_image_pixel_del(t_img *image, int x, int y)
{
	char			*pixel;
	int				bpp;
	int				sizeline;
	int				endian;

	if (x >= image->width || y >= image->height || y < 0 || x < 0)
		return ;
	pixel = mlx_get_data_addr(image->xpm, &bpp, &sizeline, &endian);
	pixel[y * sizeline + (bpp / 8) * x + 0] = 0;
	pixel[y * sizeline + (bpp / 8) * x + 1] = 0;
	pixel[y * sizeline + (bpp / 8) * x + 2] = 0;
	pixel[y * sizeline + (bpp / 8) * x + 3] = -1;
}

t_img		*ft_mlx_new_image_void(t_env *e, int size_x, int size_y)
{
	t_img	*img;
	int		x;
	int		y;

	img = (t_img*)malloc(sizeof(t_img));
	img->width = size_x;
	img->height = size_y;
	img->mlx = e->mlx;
	img->xpm = mlx_new_image(e->mlx, size_x, size_y);
	y = 0;
	while (y < size_y)
	{
		x = 0;
		while (x < size_x)
		{
			ft_mlx_image_pixel_del(img, x, y);
			x++;
		}
		y++;
	}
	return (img);
}

void		ft_mlx_print_pixel(t_img *image, int x, int y)
{
	char			*pixel;
	int				bpp;
	int				sizeline;
	int				endian;

	if (x >= image->width || y >= image->height || y < 0 || x < 0)
	{
		ft_putendl("print_pixel: [y][x] Out of image size");
		return ;
	}
	pixel = mlx_get_data_addr(image->xpm, &bpp, &sizeline, &endian);
	ft_putnbr(pixel[y * sizeline + (bpp / 8) * x + 0]);
	ft_putchar(32);
	ft_putnbr(pixel[y * sizeline + (bpp / 8) * x + 1]);
	ft_putchar(32);
	ft_putnbr(pixel[y * sizeline + (bpp / 8) * x + 2]);
	ft_putchar(32);
	ft_putnbr(pixel[y * sizeline + (bpp / 8) * x + 3]);
	ft_putchar(10);
}
