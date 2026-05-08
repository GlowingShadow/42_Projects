/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/12 13:35:45 by REDACTED          #+#    #+#             */
/*   Updated: 2015/10/12 13:35:47 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ft_get_img(t_mlx *mlx)
{
	int	w;
	int	h;

	mlx->xpm[0] = mlx_xpm_file_to_image(mlx->mlx, "img/sleeps.XPM", &w, &h);
	mlx->xpm[1] = mlx_xpm_file_to_image(mlx->mlx, "img/thinks.XPM", &w, &h);
	mlx->xpm[2] = mlx_xpm_file_to_image(mlx->mlx, "img/eats.XPM", &w, &h);
	mlx->xpm[3] = mlx_xpm_file_to_image(mlx->mlx, "img/tables.XPM", &w, &h);
	mlx->xpm[4] = mlx_xpm_file_to_image(mlx->mlx, "img/deads.XPM", &w, &h);
	mlx->xhp[0] = mlx_xpm_file_to_image(mlx->mlx, "img/1.XPM", &w, &h);
	mlx->xhp[1] = mlx_xpm_file_to_image(mlx->mlx, "img/1.XPM", &w, &h);
	mlx->xhp[2] = mlx_xpm_file_to_image(mlx->mlx, "img/2.XPM", &w, &h);
	mlx->xhp[3] = mlx_xpm_file_to_image(mlx->mlx, "img/3.XPM", &w, &h);
	mlx->xhp[4] = mlx_xpm_file_to_image(mlx->mlx, "img/4.XPM", &w, &h);
	mlx->xhp[5] = mlx_xpm_file_to_image(mlx->mlx, "img/5.XPM", &w, &h);
	mlx->xhp[6] = mlx_xpm_file_to_image(mlx->mlx, "img/6.XPM", &w, &h);
	mlx->xhp[7] = mlx_xpm_file_to_image(mlx->mlx, "img/7.XPM", &w, &h);
	mlx->xhp[8] = mlx_xpm_file_to_image(mlx->mlx, "img/8.XPM", &w, &h);
	mlx->xhp[9] = mlx_xpm_file_to_image(mlx->mlx, "img/9.XPM", &w, &h);
	mlx->xhp[10] = mlx_xpm_file_to_image(mlx->mlx, "img/10.XPM", &w, &h);
	mlx->xhp[11] = mlx_xpm_file_to_image(mlx->mlx, "img/11.XPM", &w, &h);
	mlx->xhp[12] = mlx_xpm_file_to_image(mlx->mlx, "img/12.XPM", &w, &h);
	mlx->xhp[13] = mlx_xpm_file_to_image(mlx->mlx, "img/13.XPM", &w, &h);
	mlx->xhp[14] = mlx_xpm_file_to_image(mlx->mlx, "img/14.XPM", &w, &h);
	mlx->xhp[15] = mlx_xpm_file_to_image(mlx->mlx, "img/15.XPM", &w, &h);
	mlx->xhp[16] = mlx_xpm_file_to_image(mlx->mlx, "img/16.XPM", &w, &h);
}

void	ft_draw_bg(t_mlx *mlx, int x, int y)
{
	t_im	im1;
	t_im	im2;
	int		tmp1;
	int		tmp2;

	im1.px = mlx_get_data_addr(mlx->xpm[3], &im1.bpp, &im1.SL, &im1.endian);
	im2.px = mlx_get_data_addr(mlx->img, &im2.bpp, &im2.SL, &im2.endian);
	while (x < mlx->win_x)
	{
		y = 0;
		while (y < mlx->win_y)
		{
			tmp1 = y * im1.SL + (im1.bpp / 8) * x;
			tmp2 = y * im2.SL + (im2.bpp / 8) * x;
			im2.px[tmp2] = im1.px[tmp1];
			im2.px[tmp2 + 1] = im1.px[tmp1 + 1];
			im2.px[tmp2 + 2] = im1.px[tmp1 + 2];
			y++;
		}
		x++;
	}
}

void	ft_launch_mlx(t_mlx *mlx)
{
	if ((mlx->mlx = mlx_init()) == NULL)
	{
		ft_putstr_color("mlx_init failed\n", RED);
		exit(1);
	}
	ft_get_img(mlx);
	mlx->win_x = 500;
	mlx->win_y = 500;
	mlx->img = mlx_new_image(mlx->mlx, mlx->win_x, mlx->win_y);
	ft_draw_bg(mlx, 0, 0);
	mlx->win = mlx_new_window(mlx->mlx, mlx->win_x, mlx->win_y, "philo");
}
