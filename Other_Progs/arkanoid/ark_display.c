/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 17:08:11 by REDACTED          #+#    #+#             */
/*   Updated: 2015/05/03 23:15:19 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void	ark_refresh(t_env *env)
{
	env->brick_x = env->player_x - (env->brick_size * 0.1) / 2;
	if (env->magmetised == 1)
		env->bubble_x = env->player_x;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	ark_drawplayer(*env);
	ark_explodebrick(env);
	ark_drawinfo(*env);
	ark_drawlevel(*env);
	if (env->magmetised == 0)
		ark_launchbubble(env);
	ark_drawbubble(*env);
	glfwSwapBuffers(env->win);
}

static void	ark_message(t_env *env)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	if (env->status == 1)
		ark_winner(*env);
	else if (env->status == 2)
		ark_gameover(*env);
	glfwSwapBuffers(env->win);
}

void		ark_changelevel(t_env *env)
{
	if (env->lvl > 0)
		free(env->lvl_name);
	env->lvl++;
	env->lvl_name = ft_itoa(env->lvl);
	env->brick_num = 0;
	if (ark_getblocks(env) != -1)
	{
		if (env->live < 3)
			env->live++;
		ark_gameinit(env);
		ark_refresh(env);
	}
	else if (env->runned == 1)
	{
		env->status = 1;
	}
	else
	{
		ark_error("Opening map file failed !");
		exit(1);
	}
}

static void	ark_keyhook(t_env *env)
{
	if (glfwGetKey((*env).win, GLFW_KEY_A) == GLFW_PRESS
		|| glfwGetKey((*env).win, GLFW_KEY_LEFT) == GLFW_PRESS
		|| glfwGetKey((*env).win, GLFW_KEY_KP_4) == GLFW_PRESS)
		if ((*env).player_x - ((*env).brick_size * 0.1) / 2 > -0.9)
			(*env).player_x -= 0.015;
	if (glfwGetKey((*env).win, GLFW_KEY_D) == GLFW_PRESS
		|| glfwGetKey((*env).win, GLFW_KEY_RIGHT) == GLFW_PRESS
		|| glfwGetKey((*env).win, GLFW_KEY_KP_6) == GLFW_PRESS)
		if ((*env).player_x + ((*env).brick_size * 0.1) / 2 < 0.9)
			(*env).player_x += 0.015;
	if (glfwGetKey((*env).win, GLFW_KEY_SPACE) == GLFW_PRESS)
		(*env).magmetised = 0;
}

void		ark_display(t_env *env)
{
	int		width;
	int		height;

	ark_changelevel(env);
	glfwMakeContextCurrent((*env).win);
	glfwSwapInterval(1);
	glfwSetWindowSizeCallback(env->win, ark_windowsizecall);
	while (!glfwWindowShouldClose((*env).win))
	{
		if (env->status != 0)
			ark_message(env);
		else
		{
			ark_keyhook(env);
			ark_refresh(env);
		}
		glfwGetFramebufferSize((*env).win, &width, &height);
		glViewport(0, 0, width, height);
		if (glfwGetKey((*env).win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			return ;
		glfwPollEvents();
	}
}
