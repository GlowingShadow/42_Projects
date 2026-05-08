#include <sh1.h>

void	ft_error(char *cmd, int error)
{
	if (error == -1)
	{
		ft_putstr("ft_minishell1: command not found: ");
		ft_putendl(cmd);
	}
	else if (error == -2)
	{
		ft_putstr("ft_minishell1: permission denied: ");
		ft_putendl(cmd);
	}
	else if (error == -3)
		ft_putendl("cd: Too many arguments.");
	else if (error == -4)
		ft_putendl("You are homeless.");
	else if (error == -5)
		ft_putendl("chdir failed.");
	else if (error == -6)
		ft_putendl("env: Too many arguments.");
	else if (error == -7)
		ft_putendl("setenv: Too many arguments.");
	else if (error == -8)
		ft_putendl("execve failed.");
	else if (error == -9)
		ft_putendl("cd: no OLDPWD set.");
}

int		ft_isbuiltin(char *cmd)
{
	if (strcmp(cmd, "exit") == 0)
		exit(0);
	if (strcmp(cmd, "cd") == 0)
		return (1);
	if (strcmp(cmd, "env") == 0)
		return (1);
	if (strcmp(cmd, "setenv") == 0)
		return (1);
	if (strcmp(cmd, "unsetenv") == 0)
		return (1);
	return (0);
}

int		ft_isbinary(char *cmd)
{
	if (ft_strchr(cmd, '/') != NULL)
		return (1);
	return (0);
}
