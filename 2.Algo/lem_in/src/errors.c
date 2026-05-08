/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:52:33 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:52:35 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	room_name_taken(char *line)
{
	char	*error;

	error = " : Room name already taken.\n";
	COLOR(RED);
	ft_putstr(line);
	ft_putstr(error);
	COLOR(NOCOLOR);
	exit(BAD_ROOM_NAME);
}

void	room_name_invalid(char *line)
{
	char	*error;

	error = " : Invalid room name, must not begin by 'L' or '#' letters.\n";
	COLOR(RED);
	ft_putstr(line);
	ft_putstr(error);
	COLOR(NOCOLOR);
	exit(BAD_ROOM_NAME);
}

void	invalid_line_command(char *line)
{
	char	*error;

	error = " : Invalid line due to last command.\n";
	COLOR(RED);
	ft_putstr(line);
	ft_putstr(error);
	COLOR(NOCOLOR);
	exit(COMMAND_ERROR);
}

void	invalid_ants(char *line, int err)
{
	char	*errors[2];

	errors[0] = " : Ants number can't have more than 10 digits.\n";
	errors[1] = " : Ants number can't be more than 2 147 483 647.\n";
	COLOR(RED);
	ft_putstr(line);
	ft_putstr(errors[err]);
	COLOR(NOCOLOR);
	exit(BAD_ANTS_NUMBER);
}

void	ft_errexit(char *message, int code)
{
	ft_putchar(10);
	ft_putstr_color(message, RED);
	ft_putchar(10);
	exit(code);
}
