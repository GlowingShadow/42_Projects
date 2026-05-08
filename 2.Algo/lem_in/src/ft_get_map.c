/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:53:05 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:53:07 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		grep_line(t_env *e, char *line)
{
	t_str	*newline;

	newline = (t_str*)malloc(sizeof(t_str));
	newline->str = ft_strdup(line);
	newline->next = NULL;
	if (e->map == NULL)
		e->map = newline;
	else
		e->endmap->next = newline;
	e->endmap = newline;
}

static int		step1(t_env *e, char *line, int *step)
{
	if (ft_isants(e, line) == 1)
	{
		(*step)++;
		return (0);
	}
	else
		return (-1);
}

int				ft_new_line(char *line, t_env *e)
{
	static int	step = 1;

	if (step != 2 && (e->command_id == 1 || e->command_id == 2))
		invalid_line_command(line);
	if (step == 1)
		return (step1(e, line, &step));
	if (step == 2)
	{
		if (ft_isroom(e, line, 0) == 0)
		{
			step++;
			return (ft_new_line(line, e));
		}
		else if (e->command_id == 1)
			set_start(e, line);
		else if (e->command_id == 2)
			set_end(e, line);
	}
	if (step == 3)
		if (ft_istube(e, line) == 0)
		{
			ft_resolve(e, line, " : Invalid line\n");
			exit(0);
		}
	return (0);
}

void			ft_get_map(t_env *e)
{
	char	*line;

	COLOR(GREEN);
	while (get_next_line(0, &line) > 0 && ft_strlen(line) > 0)
	{
		grep_line(e, line);
		if (ft_iscomment(line) == 1)
		{
			if (e->prints == 1)
			{
				ft_putstr("comment\t");
				ft_putendl(line);
			}
		}
		else if (ft_iscommand(line) == 1)
			ft_command(line + 2, e);
		else if (ft_new_line(line, e) == -1)
		{
			COLOR(RED);
			ft_putendl("ERROR");
			COLOR(NOCOLOR);
			exit(ERROR);
		}
	}
	COLOR(NOCOLOR);
}
