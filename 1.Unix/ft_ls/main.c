/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 19:46:12 by REDACTED          #+#    #+#             */
/*   Updated: 2015/02/13 02:31:10 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_put_file_name(char **dir, char **argv, int count, char *opt)
{
	argv = argv;
	if (dir[1] != NULL || count > 0)
	{
		if ((ft_strchr(opt, 'a') != NULL) || \
				(ft_strchr(opt, 'a') == NULL && \
				ft_grep_name(dir[0])[0] != '.'))
		{
			ft_putstr(dir[0]);
			ft_putstr(":\n");
		}
	}
}

void	ft_next_dir(char **dir, char **argv, char *opt)
{
	if ((dir + 1)[0] != NULL)
	{
		ft_putchar('\n');
		ft_ls_recursive(dir + 1, opt, argv);
	}
}

int		ft_ls_recursive(char **dir, char *opt, char **argv)
{
	char		**tab;
	char		**tab2;
	static int	count;

	ft_put_file_name(dir, argv, count, opt);
	count++;
	if (ft_lsa(&tab, dir[0]) == -1)
		perror(ft_strjoin_free("ls: ", ft_grep_name(dir[0]), 2));
	else
	{
		tab2 = ft_tabjoin(ft_strjoin(dir[0], "/"), tab);
		if ((ft_strchr(opt, 'a') != NULL) || \
				(ft_strchr(opt, 'a') == NULL && \
				ft_grep_name(dir[0])[0] != '.') || count == 1)
			ft_print_tab_dir(&tab2, &opt);
		if (ft_strchr(opt, 'R') != NULL)
		{
			if (ft_strcmp(dir[0], "/") == 0)
				ft_recursive(ft_tabjoin(dir[0], tab), opt);
			else
				ft_recursive(ft_tabjoin(ft_strjoin(dir[0], "/"), tab), opt);
		}
	}
	ft_next_dir(dir, argv, opt);
	return (0);
}

int		ft_recursive(char **dir, char *opt)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	tab = (char**)malloc(sizeof(char*) * 3 + 1);
	dir = ft_maketab_dir(&dir, opt);
	ft_option(&dir, ft_strjoin(opt, "a"));
	j = ft_tablen(dir);
	while (i < j)
	{
		if (ft_isdirectory(dir[i]) == 1 && ft_strchr(opt, 'R') != NULL && \
				ft_strcmp(ft_grep_name(dir[i]), "..") != 0 && \
				ft_strcmp(ft_grep_name(dir[i]), ".") != 0)
		{
			ft_make_arg(&tab, opt, dir[i]);
			if (ft_strchr(opt, 'a') != NULL || (ft_strchr(opt, 'a') == NULL \
						&& ft_grep_name(tab[2])[0] != '.'))
				ft_putchar('\n');
			ft_ls(tab, 3);
		}
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	ft_bad_argument(argv);
	if (ft_ls(argv, argc) == -1)
		return (-1);
	return (0);
}
