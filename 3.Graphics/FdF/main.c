/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 20:00:49 by REDACTED          #+#    #+#             */
/*   Updated: 2015/01/27 04:36:47 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_size(int **coo, t_env *e)
{
	int	i;
	int	j;

	e->max_x = 0;
	e->max_y = 0;
	e->max_z = 0;
	i = 0;
	while (coo[i] != NULL)
	{
		if (e->max_y < (coo[i][0] - 1 + i))
			e->max_y = coo[i][0] - 1 + i;
		if (e->max_x < (coo[i][0] - 1 - i))
			e->max_x = coo[i][0] - 1 - i;
		j = 1;
		while (j < coo[i][0])
		{
			if (e->max_z < (coo[i][j] / 10 - i - j + 1))
				e->max_z = coo[i][j] / 10 - i - j + 1;
			j++;
		}
		i++;
	}
	e->lines = i;
}

int		ft_draw(t_env e, t_coo **coor)
{
	ft_print_points(e, coor);
	ft_print_line1(e, coor);
	ft_print_line2(e, coor);
	return (0);
}

int		ft_expose_hook(t_env *e)
{
	ft_draw(*e, e->coor);
	mlx_put_image_to_window(e->mlx, e->win, e->img, -1, 0);
	return (0);
}

int		ft_key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 65363)
		ft_move_right(e);
	if (keycode == 65361)
		ft_move_left(e);
	if (keycode == 65364)
		ft_move_down(e);
	if (keycode == 65362)
		ft_move_up(e);
	if (keycode == 65451 || keycode == 65453)
		ft_zoom(e, keycode);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
		return (0);
	e.pts = ft_get_coo(av, 0);
	if ((e.pts)[0] == NULL)
		ft_no_points(&e);
	ft_size(e.pts, &e);
	ft_coef(&e);
	ft_constants(&e, e.pts);
	e.coor = ft_assign_xy2(e.pts, e, 0);
	if ((e.mlx = mlx_init()) == NULL)
	{
		ft_putendl("mlx_init failed");
		exit(-1);
	}
	ft_launch_mlx(&e);
	mlx_key_hook(e.win, ft_key_hook, &e);
	mlx_expose_hook(e.win, ft_expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
