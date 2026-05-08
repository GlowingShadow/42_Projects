#include <sh1.h>

void	ft_only_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\t' || line[i] == '\v')
			line[i] = 32;
		i++;
	}
}

char	*ft_trim(char *line)
{
	char	*tmp;

	tmp = ft_strtrim(line);
	free(line);
	return (tmp);
}

t_env	*ft_start(int ac, char **av, char **env)
{
	t_env	*e;
	int		i;

	(void)ac;
	(void)av;
	e = (t_env*)malloc(sizeof(t_env) * 1);
	e->env = ft_tabdup(env);
	e->line = ft_strnew(1);
	if ((i = ft_find_var(e->env, "SHLVL=")) != -1)
		ft_setenv(e, "SHLVL", ft_itoa(ft_atoi(e->env[i] + 6) + 1));
	else
		ft_setenv(e, "SHLVL", "1");
	return (e);
}

t_env	*ft_start2(char *line, char **env)
{
	t_env	*epath;
	int		i;

	epath = (t_env*)malloc(sizeof(t_env) * 1);
	epath->error = NOTFOUND;
	epath->cmd = ft_strsplit(line, ' ');
	if ((i = ft_find_var(env, "PATH=")) != -1)
		epath->env = ft_strsplit(env[i] + 5, ':');
	else
	{
		epath->env = (char**)malloc(sizeof(char*) * 1);
		epath->env[0] = NULL;
	}
	return (epath);
}

char	*ft_reconcat(char **cmd)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	len = 0;
	while (cmd[i] != NULL)
	{
		len += ft_strlen(cmd[i]);
		len++;
		i++;
	}
	line = ft_strnew(len + 1);
	i = 0;
	while (cmd[i] != NULL)
	{
		line = ft_strcat(line, cmd[i]);
		line = ft_strcat(line, " ");
		i++;
	}
	line[len - 1] = '\0';
	return (line);
}
