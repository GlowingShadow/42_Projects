/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 06:30:38 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/15 06:30:40 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <script.h>

void	ft_print_time(t_env *e, int i)
{
	struct timeval	date;

	gettimeofday(&date, NULL);
	if (i == 0 && ft_strchr(e->opt, 'q') == NULL)
	{
		ft_putstr("Script started, output file is ");
		ft_putendl(e->name);
		ft_putstr_fd("Script started on ", e->file);
		ft_putstr_fd(ctime(&date.tv_sec), e->file);
		if (e->cmd[0] != 0)
		{
			ft_putstr_fd("command: ", e->file);
			ft_putstr_fd(e->cmd, e->file);
			ft_putstr_fd("\n", e->file);
		}
	}
	else if (i == 1 && ft_strchr(e->opt, 'q') == NULL)
	{
		ft_putchar_fd('\n', e->file);
		ft_putstr_fd("Script done on ", e->file);
		ft_putstr_fd(ctime(&date.tv_sec), e->file);
		ft_putstr("\nScript done, output file is ");
		ft_putendl(e->name);
	}
}

int		set_flush_time(t_env *e, char **av, int i)
{
	struct timeval	date;

	gettimeofday(&date, NULL);
	if (av[0] == NULL || ft_isdigit_str(av[0]) == 0 \
		|| ft_strlen(av[0]) > 10)
	{
		e->flush_time = 30;
	}
	else if (ft_strlen(av[0]) == 10 && ft_strcmp("2147483647", av[0]) < 0)
	{
		ft_putstr("ft_script: invalid flush time ");
		ft_putnbr((unsigned int)ft_atoi2(av[0]));
		ft_putendl(": Undefined error: 0");
		return (-1);
	}
	else
		e->flush_time = ft_atoi2(av[0]);
	e->start_time = date.tv_sec;
	return (i + 1);
}
