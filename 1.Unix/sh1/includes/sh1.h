#ifndef SH1_H
# define SH1_H

# include <libft.h>

# define OK					0
# define NOTFOUND			-1
# define PERMDENIED			-2
# define CDTOOMANYARG		-3
# define NOHOME				-4
# define CHDIRFAILED		-5
# define ENVTOOMANYARG		-6
# define SETENVTOOMANYARG	-7
# define EXECVEFAILED		-8
# define NOOLD				-9

typedef struct	s_env
{
	int		error;
	char	**env;
	char	**cmd;
	char	*line;
}				t_env;

void			ft_error(char *cmd, int error);
int				ft_isbinary(char *cmd);
int				ft_isbuiltin(char *cmd);
int				ft_builtin(char **cmd, t_env *e);
int				ft_find_var(char **env, char *var);
int				ft_env(t_env *e, char **cmd);
void			ft_setenv(t_env *e, char *name, char *value);
void			ft_unsetenv(t_env *e, char **cmd);
int				ft_cd(char **cmd, t_env *e);
int				ft_execute(char *tmp, char **av, char **env);
int				ft_read(char *line, t_env *e);

t_env			*ft_start(int ac, char **av, char **env);
t_env			*ft_start2(char *line, char **env);
char			**ft_tabdup(char **src);
void			ft_only_space(char *line);
char			*ft_trim(char *line);
char			*ft_reconcat(char **cmd);

#endif
