/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essai.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 20:00:49 by REDACTED          #+#    #+#             */
/*   Updated: 2015/01/22 15:59:11 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>

void	mlx_image_put_pixel(void *mlx, void *img, int x, int y, int color)
{
	char    		*pixel;
	int     		bpp;
	int     		sizeline;
	int     		endian;
	unsigned int	new_color;
	
	new_color = mlx_get_color_value(mlx, color);
	pixel = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
	pixel[y * sizeline + (bpp/8)*(x)] = (new_color & 0xFF);
	pixel[y * sizeline + (bpp/8)*(x) + 1] = (new_color & 0xFF00) >> 8;
	pixel[y * sizeline + (bpp/8)*(x) + 2] = (new_color & 0xFF0000) >> 16;
}

int		main(int ac, char **av)
{
	int		x;
	int		y;
	int		i;
	int		j;
	void	*mlx;
	void	*win;
	void	*img;

	(void)ac;
	(void)av;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "FdF");
	img = mlx_new_image(mlx, 500, 500);
	y = 0;
	i = 255;
	while (y < i)
	{
		x = 0;
		j = 255;
		while (x < i)
		{
			mlx_image_put_pixel(mlx, img, x, y, ((0xFFFF00 * j + y  )));
			x++;
			j--;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_destroy_image(mlx, img);
	sleep(500);
	return (0);
}
