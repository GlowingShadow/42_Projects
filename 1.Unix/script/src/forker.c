/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 06:30:29 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/15 06:30:31 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <script.h>

static void		ft_build_zsh(t_env *e)
{
	e->zsh[0] = "/bin/zsh";
	e->zsh[1] = "-i";
	e->zsh[2] = NULL;
	if (e->cmd[0] != 0)
	{
		e->zsh[1] = "-c";
		e->zsh[2] = e->cmd;
		e->zsh[3] = NULL;
	}
}

int				ft_son(t_env *e, char **env)
{
	ft_build_zsh(e);
	if (setsid() == -1)
	{
		ft_close_ptmx(e);
		ft_putstr_color("setsid failed\n", RED);
		return (SESSIONFAIL);
	}
	ioctl((e->ptmx)[1], TIOCSCTTY, NULL);
	close((e->ptmx)[0]);
	dup2((e->ptmx)[1], STDERR_FILENO);
	dup2((e->ptmx)[1], STDOUT_FILENO);
	dup2((e->ptmx)[1], STDIN_FILENO);
	if (execve("/bin/zsh", e->zsh, env) == -1)
		ft_putendl("execve failed");
	return (0);
}

int				ft_dad(t_env *e, int byte)
{
	char			buf[1025];
	struct timeval	timeout;

	timeout.tv_sec = 0;
	timeout.tv_usec = 0;
	ft_bzero(buf, 1025);
	FD_ZERO(&(e->fds));
	FD_SET(STDIN_FILENO, &(e->fds));
	FD_SET((e->ptmx)[0], &(e->fds));
	if (select((e->ptmx)[0] + 1, &(e->fds), NULL, NULL, &timeout) < 0)
		return (0);
	if (FD_ISSET(STDIN_FILENO, &(e->fds)))
	{
		if ((byte = read(STDIN_FILENO, buf, 1024)) == 0)
			return (0);
		write((e->ptmx)[0], buf, byte);
	}
	if (FD_ISSET((e->ptmx)[0], &(e->fds)))
	{
		if ((byte = read((e->ptmx)[0], buf, 1024)) == 0)
			return (0);
		write(e->file, buf, byte);
		write(STDOUT_FILENO, buf, byte);
	}
	return (1);
}

void			check_flush(t_env *e)
{
	struct timeval	date;
	int				diff;

	if (ft_strchr(e->opt, 't') == NULL)
		return ;
	gettimeofday(&date, NULL);
	diff = date.tv_sec - e->start_time;
	if (diff >= e->flush_time && diff % e->flush_time == 0)
	{
		close(e->file);
		e->file = open(e->name, O_CREAT | O_TRUNC | O_RDWR);
		e->start_time = date.tv_sec;
	}
}
