/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_launchbubble.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 17:37:01 by REDACTED          #+#    #+#             */
/*   Updated: 2015/05/03 23:16:44 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	ark_gameinit(t_env *env)
{
	env->old_x = 0;
	env->old_y = 0;
	env->player_x = 0;
	env->bubble_x = 0;
	env->bbl_y = 0.01;
	env->bbl_x = 0.01;
	env->bubble_y = -0.785;
	env->magmetised = 1;
	env->brick_size = 2;
	env->brick_x = env->player_x - (env->brick_size * 0.1) / 2;
}

void	ark_launchbubble(t_env *env)
{
	if (env->bubble_x >= 0.9 || env->bubble_x <= -0.9)
		env->bbl_x = -env->bbl_x;
	if (env->bubble_y >= 0.9)
		env->bbl_y = -env->bbl_y;
	if (env->bubble_x > env->brick_x
		&& env->bubble_x < env->brick_x + env->brick_size * 0.1
		&& env->bubble_y <= -0.786 && env->bubble_y >= -0.8)
		env->bbl_y = -env->bbl_y;
	if (env->bubble_y <= -0.9)
	{
		env->live--;
		if (env->live < 0)
			env->status = 2;
		ark_gameinit(env);
	}
	else
	{
		env->old_x = env->bubble_x;
		env->old_y = env->bubble_y;
		env->bubble_x += env->bbl_x;
		env->bubble_y += env->bbl_y;
	}
}

void	ark_explodebrick(t_env *env)
{
	int	x;
	int	y;
	int	old_x;
	int	old_y;

	x = ft_fabs((-0.9 - env->bubble_x) / 0.1);
	y = ft_fabs((0.9 - env->bubble_y) / 0.05);
	old_x = ft_fabs((-0.9 - env->old_x) / 0.1);
	old_y = ft_fabs((0.9 - env->old_y) / 0.05);
	if (y < 18 && x < 18 && env->map[y][x] != '0')
	{
		if (env->map[y][x] > '0' && env->map[y][x] < '5')
		{
			env->score += 10;
			env->brick_num--;
		}
		if (env->map[y][x] != 'I')
			(env->map[y][x])--;
		if (env->brick_num == 0)
			ark_changelevel(env);
		if (old_x != x)
			env->bbl_x = -env->bbl_x;
		if (old_y != y)
			env->bbl_y = -env->bbl_y;
	}
}
