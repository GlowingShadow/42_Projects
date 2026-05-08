/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:54:10 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:54:11 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int	ft_iscomment(char *line)
{
	if (ft_strlen(line) > 1 && line[0] == '#' && line[1] != '#')
		return (1);
	return (0);
}

int	ft_iscommand(char *line)
{
	if (ft_strlen(line) > 1 && line[0] == '#' && line[1] == '#')
		return (1);
	return (0);
}

int	ft_isants(t_env *e, char *line)
{
	int	i;

	i = 0;
	while (line[i] != 0)
	{
		if (ft_isdigit(line[i]) == 0)
			return (0);
		i++;
	}
	if (i > 10)
		invalid_ants(line, 0);
	if (i == 10 && ft_strcmp(line, "2147483647") > 0)
		invalid_ants(line, 1);
	e->ants_amount = ft_atoi(line);
	e->ants_left = e->ants_amount;
	e->ants_waiting = e->ants_amount;
	if (e->prints == 1)
	{
		ft_putstr("ants\t");
		ft_putendl(line);
	}
	return (1);
}

int	ft_isroom(t_env *e, char *line, int i)
{
	int		n;

	n = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
		{
			n++;
			line[i] = 0;
		}
		i++;
	}
	if (n == 2)
	{
		if (add_room(e, line) == -1)
			return (0);
		if (e->prints == 1)
		{
			ft_putstr("room\t");
			ft_putendl(line);
		}
		return (1);
	}
	return (0);
}

int	ft_istube(t_env *e, char *line)
{
	char	*ptr;

	if ((ptr = ft_strchr(line, '-')) != NULL)
	{
		ptr[0] = 0;
		if (add_tube(e, line) == -1)
			return (0);
		if (e->prints == 1)
		{
			ft_putstr("tube\t");
			ft_putstr(line);
			COLOR(NOCOLOR);
			ft_putstr("-");
			COLOR(GREEN);
			ft_putendl(ptr + 1);
		}
		return (1);
	}
	return (0);
}
