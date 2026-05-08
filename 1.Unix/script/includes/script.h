/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 06:32:52 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/15 06:32:54 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCRIPT_H
# define SCRIPT_H

# include <libft.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <sys/select.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <sys/time.h>

# define OK				0
# define READ			1
# define SELECTERR		2
# define FORKERR		3
# define SESSIONFAIL	4
# define OPENERR		5
# define IOCTLERR		6
# define CMD_TOO_LONG	7
# define INVALID_FLUSH	8

# define MAX_OPTION		5
# define BUFFER_CMD		500

typedef struct		s_env
{
	struct termios	term;
	int				ptmx[2];
	fd_set			fds;
	int				file;
	int				rights;
	char			*name;
	int				start_time;
	int				flush_time;
	char			opt[MAX_OPTION + 1];
	int				illegal_option;
	char			cmd[BUFFER_CMD];
	int				cmd_len;
	char			*zsh[4];
}					t_env;

int					ft_son(t_env *e, char **env);
int					ft_dad(t_env *e, int byte);
void				ft_close_ptmx(t_env *e);
int					ft_synth_option(t_env *e, int argc, char **argv, char *opt);
void				ft_print_time(t_env *e, int i);
int					set_flush_time(t_env *e, char **av, int i);
int					ft_atoi2(char *str);
void				check_flush(t_env *e);

int					ft_isdigit_str(char *str);
int					ft_args_len(char **av);

#endif
