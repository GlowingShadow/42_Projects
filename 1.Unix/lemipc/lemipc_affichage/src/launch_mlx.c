/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 17:02:44 by REDACTED          #+#    #+#             */
/*   Updated: 2016/07/01 17:04:03 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc_aff.h>

int		ft_key_hook(int keycode, t_env *e)
{
	ft_putnbrendl(keycode);
	if (keycode == PAUSE_KEY && e->game_won == -1)
	{
		e->game_paused == 0 ? op_sem(e, LOCK) : op_sem(e, UNLOCK);
		e->game_paused = (e->game_paused == 0) ? 1 : 0;
	}
	else if (keycode == LEAVE_KEY)
	{
		shmdt(e->data);
		exit(0);
	}
	return (0);
}

void	check_win(t_env *e)
{
	int		n;
	t_int	*ptr;

	n = -1;
	ptr = e->teams;
	while (ptr != NULL)
	{
		if (ptr->amount > 0)
		{
			if (n == -1)
				n = ptr->n;
			else if (n != ptr->n)
				return ;
		}
		ptr = ptr->next;
	}
	e->game_won = n;
	e->winner = ft_strjoin(ft_strjoin("PLAYER ", ft_itoa(n)), " WON");
}

int		no_event(t_env *e)
{
	static int	i = 0;

	if (e->game_paused == 1 || e->game_won >= 0 || e->end_game == 1)
	{
		e->game_won >= 0 ? draw_win(e, get_team(e, e->game_won), 0, 0) : (int)i;
		e->game_won >= 0 ? shmdt(e->data) : (void)i;
		return (0);
	}
	op_sem(e, LOCK);
	i++;
	if ((e->data && ft_strcmp(e->mapcpy, e->cdata)) != 0 || i == RFRSH_TIMEOUT)
	{
		i = 0;
		free(e->mapcpy);
		e->mapcpy = ft_strdup(e->cdata);
		register_teams(e);
		draw_game(e);
		draw_stats(e);
		check_win(e);
	}
	op_sem(e, UNLOCK);
	usleep(50000);
	return (0);
}

void	launch_mlx(t_env *e)
{
	if ((e->mlx = mlx_init()) == NULL)
	{
		ft_putendl("mlx_init failed");
		exit(1);
	}
	e->win_x = WIDTH * (SQUARE_SIZE + 1) + 1;
	e->win_y = HEIGHT * (SQUARE_SIZE + 1) + 1;
	e->win = mlx_new_window(e->mlx, WIN_SIZE_X, WIN_SIZE_Y, "lemipc");
	e->img = mlx_new_image(e->mlx, e->win_x, e->win_y);
	get_logos(e);
	draw_background(e);
	draw_grid(e);
	mlx_key_hook(e->win, ft_key_hook, e);
	mlx_loop_hook(e->mlx, no_event, e);
	mlx_loop(e->mlx);
}
