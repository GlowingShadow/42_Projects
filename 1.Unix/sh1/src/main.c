#include <sh1.h>

int		ft_execute(char *tmp, char **av, char **env)
{
	pid_t	forker;

	if ((forker = fork()) == -1)
		exit(5);
	if (forker == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (execve(tmp, av, env) == -1)
			ft_putendl("execve failed");
		exit(0);
	}
	if (forker > 0)
	{
		wait(0);
	}
	return (OK);
}

int		ft_builtin(char **cmd, t_env *e)
{
	if (ft_strcmp(cmd[0], "cd") == 0)
		return (ft_cd(cmd, e));
	else if (ft_strcmp(cmd[0], "env") == 0)
	{
		if (ft_tablen(cmd) > 1)
			return (ft_env(e, cmd));
		else
			ft_puttab(e->env);
	}
	else if (ft_strcmp(cmd[0], "setenv") == 0)
	{
		if (ft_tablen(cmd) > 3)
			return (SETENVTOOMANYARG);
		ft_setenv(e, cmd[1], ft_tablen(cmd) > 2 ? cmd[2] : NULL);
	}
	else if (ft_strcmp(cmd[0], "unsetenv") == 0)
		ft_unsetenv(e, cmd);
	return (OK);
}

int		ft_read(char *line, t_env *e)
{
	t_env	*epath;
	int		i;

	epath = ft_start2(line, e->env);
	if (ft_isbuiltin(epath->cmd[0]) == 1)
		return (ft_builtin(epath->cmd, e));
	if (ft_isbinary(epath->cmd[0]) == 1)
		return (ft_execute(epath->cmd[0], epath->cmd, e->env));
	i = 0;
	while (epath->env[i] != NULL)
	{
		epath->line = ft_strjoin(ft_strjoin(epath->env[i], "/"), epath->cmd[0]);
		if (access(epath->line, F_OK) != -1 && (epath->error = -2) == -2)
			if (access(epath->line, X_OK) != -1)
			{
				i = ft_execute(epath->line, epath->cmd, e->env);
				free(epath->line);
				return (i);
			}
		free(epath->line);
		i++;
	}
	return (epath->error);
}

int		main(int ac, char **av, char **env)
{
	int		i;
	t_env	*e;

	signal(SIGINT, SIG_IGN);
	e = ft_start(ac, av, env);
	ft_putstr_color("REDACTED > ", RED);
	while (get_next_line(0, &(e->line)) > 0)
	{
		e->cmd = ft_strsplit(e->line, ';');
		i = 0;
		while ((e->cmd)[i] != NULL)
		{
			ft_only_space(e->cmd[i]);
			(e->cmd)[i] = ft_trim(e->cmd[i]);
			if (ft_strlen(e->cmd[i]) != 0 && \
				(e->error = ft_read(e->cmd[i], e)) != 0)
				ft_error(e->cmd[i], e->error);
			free(e->cmd[i]);
			i++;
		}
		free(e->cmd);
		ft_putstr_color("REDACTED > ", RED);
	}
	return (0);
}
