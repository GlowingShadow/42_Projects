/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_drawbubble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 14:58:01 by REDACTED          #+#    #+#             */
/*   Updated: 2015/05/03 17:39:08 by jpucelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	ark_drawbubble(t_env env)
{
	float	a;
	float	b;
	float	c;
	float	d;

	a = 0.01545 / 4;
	b = 0.04755 / 4;
	c = 0.04045 / 4;
	d = 0.0294 / 4;
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(env.bubble_x - a, env.bubble_y + b);
	glVertex2f(env.bubble_x + a, env.bubble_y + b);
	glVertex2f(env.bubble_x + c, env.bubble_y + d);
	glVertex2f(env.bubble_x + (0.025 / 2), env.bubble_y);
	glVertex2f(env.bubble_x + c, env.bubble_y - d);
	glVertex2f(env.bubble_x + a, env.bubble_y - b);
	glVertex2f(env.bubble_x - a, env.bubble_y - b);
	glVertex2f(env.bubble_x - c, env.bubble_y - d);
	glVertex2f(env.bubble_x - (0.025 / 2), env.bubble_y);
	glVertex2f(env.bubble_x - a, env.bubble_y + b);
	glEnd();
}
