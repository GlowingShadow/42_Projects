/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:52:25 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:52:27 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	ft_command(char *line, t_env *e)
{
	if (ft_strcmp(line, "start") == 0)
		e->command_id = 1;
	else if (ft_strcmp(line, "end") == 0)
		e->command_id = 2;
	else if (ft_strcmp(line, "prints") == 0)
		e->prints = 1;
	else if (ft_strcmp(line, "matrix") == 0)
		e->matrix = 1;
	else if (ft_strcmp(line, "color") == 0)
		e->color = 1;
	else
	{
		COLOR(RED);
		ft_putstr(line - 2);
		ft_putstr(" : Unknow command.\n");
		COLOR(GREEN);
	}
	if (e->prints == 1)
	{
		ft_putstr("command\t");
		ft_putendl(line);
	}
}

void	set_start(t_env *e, char *room)
{
	if (e->start_room != NULL)
	{
		ft_putstr_color("ERROR: Start room already set.\n", RED);
		exit(COMMAND_REUSED);
	}
	e->start_room = find_room(e, room);
	e->command_id = 0;
	e->ants_amount > 0 ? init_ants(e) : NULL;
}

void	set_end(t_env *e, char *room)
{
	if (e->end_room == NULL)
	{
		e->end_room = find_room(e, room);
		e->command_id = 0;
	}
	else
	{
		ft_putstr_color("ERROR: End room already set.\n", RED);
		exit(COMMAND_REUSED);
	}
}
