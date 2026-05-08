/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 19:29:53 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/09 02:32:30 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_sierpinski(void)
{
	t_env e;

	if ((e.mlx = mlx_init()) == NULL)
	{
		ft_putendl("mlx_init failed");
		return (0);
	}
	ft_launch_sierpinski(&e);
	mlx_key_hook(e.win, ft_key_hook, &e);
	mlx_hook(e.win, 6, 1L << 6, ft_hook, &e);
	mlx_mouse_hook(e.win, ft_mouse_hook, &e);
	mlx_expose_hook(e.win, ft_expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}

int		ft_julia(void)
{
	t_env e2;

	if ((e2.mlx = mlx_init()) == NULL)
	{
		ft_putendl("mlx_init failed");
		return (0);
	}
	ft_launch_julia(&e2);
	mlx_key_hook(e2.win, ft_key_hook, &e2);
	mlx_hook(e2.win, 6, 1L << 6, ft_hook, &e2);
	mlx_mouse_hook(e2.win, ft_mouse_hook, &e2);
	mlx_expose_hook(e2.win, ft_expose_hook, &e2);
	mlx_loop(e2.mlx);
	return (0);
}

int		ft_error(int ac)
{
	if (ac < 2)
	{
		ft_putendl("Choose your destiny:");
		ft_putendl("\tType 1 for Mandelbrot.");
		ft_putendl("\tType 2 for Julia.");
		ft_putendl("\tType 3 for Sierpinski.");
		ft_putendl("\tType 4 for Pythagoras tree.");
		ft_putendl("\tType nothing to choose your destiny.");
		return (-1);
	}
	return (0);
}

void	ft_fractol(char *av)
{
	if (ft_strcmp(av, "1") == 0)
		ft_mandelbrot();
	else if (ft_strcmp(av, "2") == 0)
		ft_julia();
	else if (ft_strcmp(av, "3") == 0)
		ft_sierpinski();
	else if (ft_strcmp(av, "4") == 0)
		ft_pythagore_tree();
	else
		ft_error(1);
}

int		main(int ac, char **av)
{
	int	x;
	int	pid;

	x = 1;
	pid = 0;
	if (ft_error(ac) == -1)
		return (0);
	while (x <= (ac - 1))
	{
		pid = fork();
		if (pid == 0)
		{
			ft_fractol(av[x]);
			return (0);
		}
		x++;
	}
	x = 0;
	while (++x <= (ac - 1))
		wait(NULL);
	return (0);
}
