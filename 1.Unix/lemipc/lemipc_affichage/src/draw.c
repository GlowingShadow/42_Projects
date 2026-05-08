/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 17:02:29 by REDACTED          #+#    #+#             */
/*   Updated: 2016/07/01 17:02:31 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc_aff.h>

void		draw_grid(t_env *e)
{
	int		x;
	int		y;

	e->grid = ft_mlx_new_image_void(e, e->win_x, e->win_y);
	y = 0;
	while (y < e->win_y)
	{
		x = 0;
		while (x < e->win_x)
		{
			ft_mlx_image_pixel_put2(e->grid, x, y, GRID_COLOR);
			if (x == 0 || x == e->win_x - 1 || y == 0 || y == e->win_y - 1)
				ft_mlx_image_pixel_put2(e->grid, x, y, BOX_COLOR);
			if (y % (SQUARE_SIZE + 1) == 0)
				x++;
			else
				x += SQUARE_SIZE + 1;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->grid->xpm, 5, 5);
}

void		draw_game(t_env *e)
{
	int		i;
	t_int	*player;

	i = 0;
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->bg->xpm, 0, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->grid->xpm, 5, 5);
	while (i < e->size - 1)
	{
		if (e->mapcpy[i] != VOID_CHAR)
		{
			player = get_team(e, e->mapcpy[i]);
			ft_putnbr(player->n);
			mlx_put_image_to_window(e->mlx, e->win, player->color->xpm, \
				5 + (i % WIDTH) * 26 + 1, 5 + (i / WIDTH) * 26 + 1);
			mlx_put_image_to_window(e->mlx, e->win, player->logo->xpm, \
				5 + (i % WIDTH) * 26 + 1, 5 + (i / WIDTH) * 26 + 1);
		}
		i++;
	}
}

void		draw_stats(t_env *e)
{
	t_int	*player;
	int		i;

	i = 0;
	player = e->teams;
	while (player != NULL)
	{
		mlx_put_image_to_window(e->mlx, e->win, player->color->xpm, S_X, S_Y);
		mlx_put_image_to_window(e->mlx, e->win, player->logo->xpm, S_X, S_Y);
		mlx_string_put(e->mlx, e->win, S_X + SQUARE_SIZE + 5, S_Y, 0xFFFFFF, \
			ft_itoa(player->amount));
		i++;
		player = player->next;
	}
	mlx_string_put(e->mlx, e->win, WIDTH * (SQUARE_SIZE + 1) + 85, 10, \
		0xFFFFFF, "STATISTICS");
}

void		draw_background(t_env *e)
{
	int		x;
	int		y;
	int		xf;

	xf = e->win_x + 10;
	y = 0;
	e->bg = ft_mlx_new_image_void(e, WIN_SIZE_X, WIN_SIZE_Y);
	while (y < e->bg->height)
	{
		x = 0;
		while (x < e->bg->width)
		{
			ft_mlx_image_pixel_put2(e->bg, x, y, BG_COLOR);
			if ((x > xf && x < WIN_SIZE_X - 5 && y > 5 && y < WIN_SIZE_Y - 6) \
				|| (x > 5 && x < e->win_x + 5 && y > 5 && y < e->win_y + 5))
				ft_mlx_image_pixel_put2(e->bg, x, y, BOXBG_COLOR);
			if (x > xf && x < WIN_SIZE_X - 5 && (y == 5 || y == WIN_SIZE_Y - 6))
				ft_mlx_image_pixel_put2(e->bg, x, y, BOX_COLOR);
			if (y > 5 && y < WIN_SIZE_Y - 6 && (x == xf || x == WIN_SIZE_X - 5))
				ft_mlx_image_pixel_put2(e->bg, x, y, BOX_COLOR);
			x++;
		}
		y++;
	}
}

void		draw_win(t_env *e, t_int *win, int i, int j)
{
	static int		r = 0;
	float			c;

	if ((c = (float)r++ / 100.0) > 1.0)
		return ;
	e->img = mlx_new_image(e, e->win_x, e->win_y);
	while (j < e->win_y)
	{
		i = 0;
		while (i < e->win_x)
		{
			ft_mlx_image_pixel_put(e, i, j, \
	RGB(56 - (int)(c * 56.0), 75 - (int)(c * 75.0), 122 - (int)(c * 122.0)));
			if (i % (SQUARE_SIZE + 1) == 0 || j % (SQUARE_SIZE + 1) == 0)
				ft_mlx_image_pixel_put(e, i, j, \
	RGB(70 - (int)(c * 70.0), 109 - (int)(c * 109.0), 208 - (int)(c * 208.0)));
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 5, 5);
	mlx_string_put(e->mlx, e->win, e->win_x / 2 - 30, e->win_y / 2 - 5, \
WHITEC * c, e->winner);
	MLX_PITW(e->mlx, e->win, win->color->xpm, e->win_x / 2, e->win_y / 2 + 40);
	MLX_PITW(e->mlx, e->win, win->logo->xpm, e->win_x / 2, e->win_y / 2 + 40);
}
