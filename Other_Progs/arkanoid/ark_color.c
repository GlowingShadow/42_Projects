/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:51:12 by REDACTED          #+#    #+#             */
/*   Updated: 2015/05/03 23:15:12 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void		ark_glcolor(t_color color)
{
	float	red;
	float	green;
	float	blue;

	red = (float)(color.red) / 255.0f;
	green = (float)(color.green) / 255.0f;
	blue = (float)(color.blue) / 255.0f;
	glColor3f(red, green, blue);
}

float			ark_drawcharcol(char **tab, float x, float y, t_color color)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '1')
			{
				glBegin(GL_POINTS);
				ark_glcolor(color);
				glVertex2f(x + (float)j / 200, y - (float)i / 200);
				glEnd();
			}
			j++;
		}
		i++;
	}
	return (x + 0.05);
}

void			ark_windowsizecall(GLFWwindow *win, int width, int height)
{
	if (width < 150 || height < 150)
	{
		ark_error("Window too small !");
		glfwDestroyWindow(win);
		glfwTerminate();
		exit(1);
	}
}
