/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ark_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 15:42:25 by REDACTED          #+#    #+#             */
/*   Updated: 2015/05/03 20:21:13 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void	ark_countblocks(t_env *env, int i)
{
	int		j;

	j = 0;
	env->map[i][18] = '\0';
	while (env->map[i][j] != '\0')
	{
		if (env->map[i][j] != '0' && env->map[i][j] != 'I')
			env->brick_num++;
		j++;
	}
}

int			ark_getblocks(t_env *env)
{
	char	*filename;
	int		i;
	int		fd;

	filename = ft_strnew(ft_strlen((*env).lvl_name) + 11);
	filename = ft_strcpy(filename, "levels/level");
	filename = ft_strcat(filename, (*env).lvl_name);
	filename = ft_strcat(filename, ".map");
	if ((fd = open(filename, O_RDONLY)) != -1)
	{
		(*env).map = (char**)malloc(sizeof(char*) * 19);
		i = 0;
		while (i < 18)
		{
			(*env).map[i] = (char*)malloc(sizeof(char) * 20);
			read(fd, (*env).map[i], 19);
			ark_countblocks(env, i);
			i++;
		}
		(*env).map[i] = NULL;
		if (env->runned == 0)
			env->runned = 1;
	}
	free(filename);
	return (fd);
}
