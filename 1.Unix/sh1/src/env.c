#include <sh1.h>

static void		ft_new_var(t_env *e, char *name, char *value)
{
	char	**dst;
	int		i;

	i = ft_tablen(e->env) + 1;
	dst = (char**)malloc(sizeof(char*) * (i + 1));
	i = 0;
	while (e->env[i] != NULL)
	{
		dst[i] = e->env[i];
		i++;
	}
	if (value == NULL)
		dst[i] = ft_strjoin(name, "=");
	else
		dst[i] = ft_strjoin_free(ft_strjoin(name, "="), value, 1);
	i++;
	dst[i] = NULL;
	free(e->env);
	e->env = dst;
}

void			ft_setenv(t_env *e, char *name, char *value)
{
	int		i;
	char	*var;

	if (name == NULL)
		ft_puttab(e->env);
	else if (value == NULL)
	{
		var = ft_strjoin(name, "=");
		if ((i = ft_find_var(e->env, var)) != -1)
			e->env[i][ft_strlen(name) + 1] = '\0';
		else
			ft_new_var(e, name, value);
		free(var);
	}
	else
	{
		var = ft_strjoin(name, "=");
		if ((i = ft_find_var(e->env, var)) != -1)
		{
			free(e->env[i]);
			e->env[i] = ft_strjoin_free(var, value, 1);
		}
		else
			ft_new_var(e, name, value);
	}
}

void			ft_unsetenv(t_env *e, char **cmd)
{
	int		i;
	char	*var;
	int		len;
	int		ind;

	len = ft_tablen(e->env);
	i = 1;
	while (cmd[i] != NULL)
	{
		var = ft_strjoin(cmd[i], "=");
		if ((ind = ft_find_var(e->env, cmd[i])) != -1)
		{
			e->env[ind] = e->env[len - 1];
			e->env[len - 1] = NULL;
			len--;
		}
		i++;
	}
}

void			ft_inception(t_env *cpy, char **cmd, int i)
{
	cpy->line = ft_reconcat(cmd + i);
	cpy->cmd = ft_strsplit(cpy->line, ';');
	i = 0;
	while ((cpy->cmd)[i] != NULL)
	{
		if (ft_strlen(cpy->cmd[i]) != 0 && \
			(cpy->error = ft_read(cpy->cmd[i], cpy)) != 0)
			ft_error(cpy->cmd[i], cpy->error);
		free(cpy->cmd[i]);
		i++;
	}
	free(cpy->cmd);
}

int				ft_env(t_env *e, char **cmd)
{
	t_env	*cpy;
	int		i;
	char	*ptr;

	cpy = (t_env*)malloc(sizeof(t_env) * 1);
	i = 1;
	if (ft_strcmp(cmd[i], "-i") == 0)
	{
		cpy->env = (char**)malloc(sizeof(char*) * 1);
		cpy->env[0] = NULL;
		i++;
	}
	else
		cpy->env = ft_tabdup(e->env);
	while (cmd[i] != NULL && (ptr = ft_strchr(cmd[i], '=')) != NULL)
	{
		ft_setenv(cpy, ft_strsub(cmd[i], 0, ptr - cmd[i]), ptr + 1);
		i++;
	}
	if (cmd[i] == NULL)
		ft_puttab(cpy->env);
	else
		ft_inception(cpy, cmd, i);
	return (OK);
}
