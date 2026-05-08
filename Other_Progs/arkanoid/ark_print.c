/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 17:17:07 by REDACTED          #+#    #+#             */
/*   Updated: 2015/05/03 22:57:59 by jpucelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	ark_success(char *str)
{
	ft_putstr_fd(COLOR_GREEN, 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd(COLOR_NONE, 2);
}

void	ark_error(char *str)
{
	ft_putstr_fd(COLOR_RED, 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd(COLOR_NONE, 2);
}

void	ark_winner(t_env env)
{
	float	x;
	float	y;

	y = 0;
	x = -0.15;
	x = ark_drawcharcol(env.alpha[24], x, y, ark_color(0, 255, 0));
	x = ark_drawcharcol(env.alpha[14], x, y, ark_color(0, 255, 0));
	x = ark_drawcharcol(env.alpha[20], x, y, ark_color(0, 255, 0)) + 0.025;
	x = ark_drawcharcol(env.alpha[22], x, y, ark_color(0, 255, 0));
	x = ark_drawcharcol(env.alpha[8], x, y, ark_color(0, 255, 0));
	x = ark_drawcharcol(env.alpha[13], x, y, ark_color(0, 255, 0));
}

void	ark_gameover(t_env env)
{
	float	x;
	float	y;

	y = 0;
	x = -0.2;
	x = ark_drawcharcol(env.alpha[6], x, y, ark_color(255, 0, 0));
	x = ark_drawcharcol(env.alpha[0], x, y, ark_color(255, 0, 0));
	x = ark_drawcharcol(env.alpha[12], x, y, ark_color(255, 0, 0));
	x = ark_drawcharcol(env.alpha[4], x, y, ark_color(255, 0, 0)) + 0.025;
	x = ark_drawcharcol(env.alpha[14], x, y, ark_color(255, 0, 0));
	x = ark_drawcharcol(env.alpha[21], x, y, ark_color(255, 0, 0));
	x = ark_drawcharcol(env.alpha[4], x, y, ark_color(255, 0, 0));
	x = ark_drawcharcol(env.alpha[17], x, y, ark_color(255, 0, 0));
}
