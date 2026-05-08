/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:33:48 by REDACTED          #+#    #+#             */
/*   Updated: 2015/05/03 23:00:45 by jpucelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void	ark_getalnum(char ***tab, char *filename)
{
	char	*path;
	int		i;
	int		fd;

	path = ft_strjoin("alnum/", filename);
	if ((fd = open(path, O_RDONLY)) != -1)
	{
		free(path);
		*tab = (char**)malloc(sizeof(char*) * 8);
		i = 0;
		while (i < 7)
		{
			(*tab)[i] = (char*)malloc(sizeof(char) * 7);
			read(fd, (*tab)[i], 6);
			(*tab)[i][5] = '\0';
			i++;
		}
		(*tab)[i] = NULL;
	}
	else
	{
		ark_error("Opening alnum file failed !");
		exit(1);
	}
}

static void	ark_buildalnum(t_env *env)
{
	int		i;
	char	tmp[5];

	i = 0;
	(*env).alpha = (char***)malloc(sizeof(char**) * 27);
	(*env).digit = (char***)malloc(sizeof(char**) * 11);
	while (i < 26)
	{
		tmp[0] = i + 65;
		tmp[1] = '.';
		tmp[2] = 'm';
		tmp[3] = 'a';
		tmp[4] = 'p';
		ark_getalnum(&(env->alpha[i]), tmp);
		if (i < 10)
		{
			tmp[0] = i + 48;
			ark_getalnum(&(env->digit[i]), tmp);
		}
		i++;
	}
}

static void	ark_init(t_env *env)
{
	env->lvl = 0;
	env->lvl_name = NULL;
	env->score = 0;
	env->live = 3;
	env->runned = 0;
	env->brick_num = 0;
	env->status = 0;
}

int			main(void)
{
	t_env		env;

	ark_init(&env);
	if (!glfwInit())
	{
		ark_error("Failed to initialize GLFW");
		return (0);
	}
	ark_buildalnum(&env);
	if ((env.win = glfwCreateWindow(1024, 768, "Arkanoid", NULL, NULL)) != NULL)
	{
		ark_display(&env);
		glfwDestroyWindow(env.win);
	}
	else
		ark_error("Failed to open window");
	glfwTerminate();
	return (0);
}
