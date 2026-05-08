/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 17:07:35 by REDACTED          #+#    #+#             */
/*   Updated: 2015/05/03 22:51:36 by jpucelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

t_color			ark_color(int red, int green, int blue)
{
	t_color color;

	color.red = red;
	color.green = green;
	color.blue = blue;
	return (color);
}

static void		ark_drawbrick(float x, float y, t_color color)
{
	float	red;
	float	green;
	float	blue;

	red = (float)(color.red) / 255.0f;
	green = (float)(color.green) / 255.0f;
	blue = (float)(color.blue) / 255.0f;
	glBegin(GL_QUADS);
	glColor3f(red, green, blue);
	glVertex2f(x, y);
	glColor3f(red, green, blue);
	glVertex2f(x + 0.1, y);
	glColor3f(0, 0, 0);
	glVertex2f(x + 0.1, y - 0.05);
	glColor3f(red, green, blue);
	glVertex2f(x, y - 0.05);
	glEnd();
}

void			ark_drawplayer(t_env env)
{
	int		i;
	float	x;

	i = 0;
	x = env.brick_x;
	while (i < env.brick_size)
	{
		ark_drawbrick(x, -0.8, ark_color(120, 160, 220));
		x += 0.1;
		i++;
	}
}

static void		ark_drawcolor(float x, float y, char v)
{
	if (v == '1')
		ark_drawbrick(x, y, ark_color(0, 255, 0));
	else if (v == '2')
		ark_drawbrick(x, y, ark_color(255, 255, 0));
	else if (v == '3')
		ark_drawbrick(x, y, ark_color(255, 127, 0));
	else if (v == '4')
		ark_drawbrick(x, y, ark_color(255, 0, 0));
	else if (v == 'I')
		ark_drawbrick(x, y, ark_color(127, 127, 127));
	else
		ark_drawbrick(x, y, ark_color(255, 255, 255));
}

void			ark_drawlevel(t_env env)
{
	float	x;
	float	y;
	int		i;
	int		j;

	i = 0;
	y = 0.9;
	while (env.map[i] != NULL)
	{
		y = 0.9 - (0.05 * i);
		j = 0;
		while (env.map[i][j] != '\0')
		{
			x = -0.9 + (0.1 * j);
			if (env.map[i][j] != '0')
				ark_drawcolor(x, y, env.map[i][j]);
			j++;
		}
		i++;
	}
}
