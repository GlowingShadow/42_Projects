/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 06:30:57 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/15 06:30:58 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <script.h>

static int		ft_launch_ptmx(t_env *e)
{
	static char		ttyfile[128];

	if (ioctl(0, TIOCGETA, &(e->term)) == -1)
		return (IOCTLERR);
	e->term.c_lflag &= ~(ECHO | ICANON);
	if (ioctl(0, TIOCSETA, &(e->term)) == -1)
		return (IOCTLERR);
	if (((e->ptmx)[0] = open("/dev/ptmx", O_RDWR)) == -1)
		return (OPENERR);
	if (ioctl((e->ptmx)[0], TIOCPTYGRANT) == -1)
		return (IOCTLERR);
	if (ioctl((e->ptmx)[0], TIOCPTYUNLK) == -1)
		return (IOCTLERR);
	if (ioctl((e->ptmx)[0], TIOCPTYGNAME, ttyfile) == -1)
		return (IOCTLERR);
	if (((e->ptmx)[1] = open(ttyfile, O_RDWR)) == -1)
		return (OPENERR);
	return (OK);
}

static void		ft_concat_cmd(t_env *e, char **cmd)
{
	int		i;

	ft_bzero(e->cmd, e->cmd_len);
	i = 0;
	while (cmd[i] != NULL)
	{
		ft_strcat(e->cmd, cmd[i]);
		ft_strcat(e->cmd, " ");
		i++;
	}
}

static int		ft_option(t_env *e, int ac, char **av)
{
	int		i;

	ft_bzero(e->opt, MAX_OPTION + 1);
	i = ft_synth_option(e, ac, av, e->opt);
	if (e->opt[0] != 0 && ft_strchr(e->opt, 't') != NULL)
		if ((i = set_flush_time(e, av + i, i)) == -1)
			return (INVALID_FLUSH);
	e->rights = O_CREAT | O_TRUNC | O_RDWR;
	if (ft_strchr(e->opt, 'a') != NULL)
		e->rights = O_CREAT | O_APPEND | O_RDWR;
	e->name = (i < ac) ? av[i] : "typescript";
	e->file = open(e->name, e->rights, 0666);
	if ((e->cmd_len = ft_args_len(av + i + 1)) == -1)
		return (CMD_TOO_LONG);
	if (ac - i > 1)
		ft_concat_cmd(e, av + i + 1);
	return (OK);
}

int				init_ptmx(t_env *e)
{
	int		i;

	if ((i = ft_launch_ptmx(e)) != OK)
	{
		if (i == OPENERR)
			ft_putstr_color("open failed\n", RED);
		else
			ft_putstr_color("ioctl failed\n", RED);
		return (i);
	}
	i = OK;
	return (i);
}

int				main(int ac, char **av, char **env)
{
	t_env	e;
	int		forker;
	int		i;

	if ((i = ft_option(&e, ac, av)) != OK || e.illegal_option == 1)
		return (i);
	ft_print_time(&e, 0);
	if ((i = init_ptmx(&e)) != OK)
		return (i);
	if ((forker = fork()) == -1)
	{
		ft_putstr_color("fork failed\n", RED);
		return (FORKERR);
	}
	if (forker == 0)
	{
		if ((i = ft_son(&e, env)) != -1)
			return (i);
	}
	else
		while (ft_dad(&e, 0) == 1)
			check_flush(&e);
	ft_close_ptmx(&e);
	ft_print_time(&e, 1);
	return (OK);
}
