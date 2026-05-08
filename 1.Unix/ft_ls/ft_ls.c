/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 05:27:16 by REDACTED          #+#    #+#             */
/*   Updated: 2015/02/19 13:04:02 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_dir2(char **dir, char **tab, char *opt)
{
	char	**tab2;

	tab2 = ft_tabjoin(ft_strjoin(dir[0], "/"), tab);
	ft_print_tab_dir(&tab2, &opt);
	if (ft_strchr(opt, 'R') != NULL)
	{
		if (ft_strlen(dir[0]) > 1)
			ft_recursive(ft_tabjoin(ft_strjoin(dir[0], "/"), tab), opt);
		else
			ft_recursive(ft_tabjoin(dir[0], tab), opt);
	}
}

int		ft_ls_dir(char **dir, char *opt, char **argv)
{
	char		**tab;
	static int	count;

	if (dir[1] != NULL || count > 0 || ft_tablen(argv) > 1)
	{
		ft_putstr(dir[0]);
		ft_putstr(":\n");
	}
	count++;
	if (ft_lsa(&tab, dir[0]) == -1)
		perror(ft_strjoin_free("ls: ", ft_grep_name(dir[0]), 2));
	else
		ft_ls_dir2(dir, tab, opt);
	if ((dir + 1)[0] != NULL)
	{
		ft_putchar('\n');
		ft_ls_dir(dir + 1, opt, argv);
	}
	return (0);
}

void	ft_ls_part_recursive(char **argv, char **tab, char *opt)
{
	char	**dir;

	if (ft_strchr(opt, 'R') != NULL)
	{
		dir = (char**)malloc(sizeof(char*) * 1 + 1);
		dir[0] = ".";
		dir[1] = NULL;
		ft_ls_recursive(dir, opt, argv);
		free(opt);
	}
	else
		ft_print_tab(&tab, &opt);
}

void	ft_ls_part_dir(char **dir, char *opt, char **argv, int i)
{
	if (dir[0] != NULL)
	{
		opt[ft_strlen(opt) - 1] = 0;
		if (ft_strchr(opt, 'R') != NULL)
			ft_ls_recursive(dir, opt, argv + i);
		else
			ft_ls_dir(dir, opt, argv + i);
		ft_clear_tab(&dir);
		free(opt);
	}
}

int		ft_ls(char **argv, int argc)
{
	char		**tab;
	char		*opt;
	int			i;
	char		**dir;

	if (ft_lsa(&tab, "./") == -1)
		return (-1);
	opt = ft_strnew(5);
	if (argc == 1)
		ft_puttab(tab = ft_maketab_ls(&tab));
	if (argc > 1)
	{
		if ((i = ft_synth_option(argc, argv, &opt)) < argc)
		{
			tab = ft_grep(tab, argv, argc, i);
			opt = ft_strjoin_free(opt, "a", 1);
			dir = ft_maketab_dir(&tab, opt);
			ft_print_tab_target(&tab, &opt, dir);
			ft_ls_part_dir(dir, opt, argv, i);
			return (0);
		}
		else
			ft_ls_part_recursive(argv, tab, opt);
	}
	return (0);
}
