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

void			ft_close_ptmx(t_env *e)
{
	e->term.c_lflag |= ~(ECHO | ICANON);
}

static char		*ft_concat_cmd(char **cmd)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (cmd[i] != NULL)
	{
		len += ft_strlen(cmd[i]) + 1;
		i++;
	}
	str = ft_strnew(len);
	i = 0;
	while (cmd[i] != NULL)
	{
		ft_strcat(str, cmd[i]);
		ft_strcat(str, " ");
		i++;
	}
	return (str);
}

static void		ft_option(t_env *e, int ac, char **av)
{
	int		i;

	ft_bzero(e->opt, MAX_OPTION + 1);
	i = ft_synth_option(ac, av, e->opt);
	if (e->opt[0] != 0 && ft_strchr(e->opt, 't') != NULL)
		i = set_flush_time(e, av + i, i);
	e->rights = O_CREAT | O_TRUNC | O_RDWR;
	// if (e->opt == NULL)
	// 	e->opt = ft_strdup("");
	if (ft_strchr(e->opt, 'a') != NULL)
		e->rights = O_CREAT | O_APPEND | O_RDWR;
	e->name = ft_strdup((i < ac) ? av[i] : "typescript");
	e->file = open(e->name, e->rights, 0666);
	e->cmd = NULL;
	if (ac - i > 1)
		e->cmd = ft_concat_cmd(av + i + 1);
}

int				main(int ac, char **av, char **env)
{
	t_env	e;
	int		forker;
	int		i;

	ft_option(&e, ac, av);
	ft_print_time(&e, 0, NULL);
	if ((i = ft_launch_ptmx(&e)) != OK)
	{
		if (i == OPENERR)
			ft_putstr_color("open failed\n", RED);
		else
			ft_putstr_color("ioctl failed\n", RED);
		return (i);
	}
	if ((forker = fork()) == -1)
	{
		ft_putstr_color("fork failed\n", RED);
		return (FORKERR);
	}
	if ((i = ft_son(&e, forker, env)) != -1)
		return (i);
	ft_dad(&e, forker);
	ft_close_ptmx(&e);
	ft_print_time(&e, 1, NULL);
	return (OK);
}
