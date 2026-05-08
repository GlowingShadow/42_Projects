#include <sh1.h>

static int		ft_cd_home(t_env *e, int i)
{
	char	*current;

	current = getcwd(NULL, 0);
	if (chdir(e->env[i] + ft_strlen("HOME=")) == -1)
	{
		free(current);
		return (CHDIRFAILED);
	}
	ft_setenv(e, "PWD", getcwd(NULL, 0));
	ft_setenv(e, "OLDPWD", current);
	free(current);
	return (0);
}

static int		ft_cd_racine(t_env *e, char **cmd)
{
	char	*current;

	current = getcwd(NULL, 0);
	if (chdir(cmd[1]) == -1)
	{
		free(current);
		return (CHDIRFAILED);
	}
	ft_setenv(e, "PWD", getcwd(NULL, 0));
	ft_setenv(e, "OLDPWD", current);
	free(current);
	return (0);
}

static int		ft_cd_dir(t_env *e, char **cmd)
{
	char	*current;

	current = getcwd(NULL, 0);
	if (chdir(ft_strjoin_free(getcwd(NULL, 0), \
		ft_strjoin("/", cmd[1]), 3)) == -1)
	{
		free(current);
		return (CHDIRFAILED);
	}
	ft_setenv(e, "PWD", getcwd(NULL, 0));
	ft_setenv(e, "OLDPWD", current);
	free(current);
	return (OK);
}

static int		ft_cd_back(t_env *e)
{
	char	*current;
	int		i;

	if ((i = ft_find_var(e->env, "OLDPWD=")) == -1)
		return (NOOLD);
	current = getcwd(NULL, 0);
	if (chdir(e->env[i] + 7) == -1)
	{
		free(current);
		return (CHDIRFAILED);
	}
	ft_setenv(e, "PWD", getcwd(NULL, 0));
	ft_setenv(e, "OLDPWD", current);
	free(current);
	return (OK);
}

int				ft_cd(char **cmd, t_env *e)
{
	int		i;

	i = 0;
	if (ft_tablen(cmd) > 2)
		return (CDTOOMANYARG);
	if (ft_tablen(cmd) == 1 && (i = ft_find_var(e->env, "HOME=")) != -1)
	{
		if (ft_cd_home(e, i) == CHDIRFAILED)
			return (CHDIRFAILED);
	}
	else if (i == -1)
		return (NOHOME);
	if (ft_tablen(cmd) == 2)
	{
		if (cmd[1][0] == '/')
		{
			if (ft_cd_racine(e, cmd) == CHDIRFAILED)
				return (CHDIRFAILED);
		}
		else if (ft_strcmp("-", cmd[1]) == 0)
			return (ft_cd_back(e));
		else
			return (ft_cd_dir(e, cmd));
	}
	return (OK);
}
