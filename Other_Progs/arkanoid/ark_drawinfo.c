/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_drawinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 11:50:06 by REDACTED          #+#    #+#             */
/*   Updated: 2015/05/03 22:47:42 by jpucelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static float	ark_drawchar(char **tab, float x, float y)
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
				glColor3f(1, 1, 1);
				glVertex2f(x + (float)j / 200, y - (float)i / 200);
				glEnd();
			}
			j++;
		}
		i++;
	}
	return (x + 0.05);
}

static void		ark_drawscore(t_env env)
{
	float	x;
	float	y;
	char	*tmp;
	int		i;

	x = -0.9;
	y = 0.97;
	x = ark_drawchar(env.alpha[18], x, y);
	x = ark_drawchar(env.alpha[2], x, y);
	x = ark_drawchar(env.alpha[14], x, y);
	x = ark_drawchar(env.alpha[17], x, y);
	x = ark_drawchar(env.alpha[4], x, y) + 0.025;
	tmp = ft_itoa(env.score);
	i = 0;
	while (tmp[i] != '\0')
	{
		x = ark_drawchar(env.digit[tmp[i] - 48], x, y);
		i++;
	}
	free(tmp);
}

static void		ark_drawlive(t_env env)
{
	float	x;
	float	y;
	char	*tmp;
	int		i;

	y = 0.97;
	x = ark_drawchar(env.alpha[11], -0.2, y);
	x = ark_drawchar(env.alpha[8], x, y);
	x = ark_drawchar(env.alpha[21], x, y);
	x = ark_drawchar(env.alpha[4], x, y) + 0.025;
	tmp = ft_itoa(env.live);
	i = 0;
	while (tmp[i] != '\0')
	{
		x = ark_drawchar(env.digit[tmp[i] - 48], x, y);
		i++;
	}
	free(tmp);
}

static void		ark_drawlvl(t_env env)
{
	float	x;
	float	y;
	char	*tmp;
	int		i;

	y = 0.97;
	x = ark_drawchar(env.alpha[11], 0.55, y);
	x = ark_drawchar(env.alpha[4], x, y);
	x = ark_drawchar(env.alpha[21], x, y);
	x = ark_drawchar(env.alpha[4], x, y);
	x = ark_drawchar(env.alpha[11], x, y) + 0.025;
	tmp = ft_itoa(env.lvl);
	if (env.lvl < 10)
		x = ark_drawchar(env.digit[0], x, y);
	i = 0;
	while (tmp[i] != '\0')
	{
		x = ark_drawchar(env.digit[tmp[i] - 48], x, y);
		i++;
	}
	free(tmp);
}

void			ark_drawinfo(t_env env)
{
	ark_drawscore(env);
	ark_drawlive(env);
	ark_drawlvl(env);
}
