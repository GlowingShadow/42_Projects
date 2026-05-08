/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 02:12:03 by REDACTED          #+#    #+#             */
/*   Updated: 2015/02/19 10:43:58 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_print_tab_dir(char ***tab, char **opt)
{
	t_data	*stats;

	if ((stats = ft_option(tab, *opt)) == NULL)
	{
		if ((*tab) == NULL)
			return (-1);
		ft_no_path(tab);
		ft_puttab(*tab);
		ft_clear_tab(tab);
	}
	else
	{
		ft_puttab_stats_dir(stats, *tab, 0, 0);
		ft_clear_stats(&stats, ft_tablen(*tab));
		ft_clear_tab(tab);
	}
	return (0);
}

int	ft_print_tab(char ***tab, char **opt)
{
	t_data	*stats;

	if ((stats = ft_option(tab, *opt)) == NULL)
	{
		if ((*tab) == NULL)
			return (-1);
		ft_no_path(tab);
		ft_puttab(*tab);
		ft_clear_tab(tab);
	}
	else
	{
		ft_puttab_stats(stats, *tab, 0, 0);
		ft_clear_stats(&stats, ft_tablen(*tab));
		ft_clear_tab(tab);
	}
	return (0);
}

int	ft_check_before_dir(char **tab, char *opt)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (ft_strchr(opt, 'l') == NULL && ft_islink(tab[i]) == 1 && \
				ft_isdirectory(ft_readlink(tab[i])) == 1)
			;
		else if (ft_isdirectory(tab[i]) != 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_print_tab_target(char ***tab, char **opt, char **dir)
{
	t_data	*stats;
	int		j;

	j = 0;
	if (ft_check_before_dir(*tab, *opt) == 1)
		j = 1;
	if ((stats = ft_option(tab, *opt)) == NULL)
	{
		if ((*tab) == NULL)
			return (-1);
		ft_puttab_target(*tab, *opt);
		ft_clear_tab(tab);
	}
	else
	{
		ft_puttab_stats_target(stats, 0, ft_tablen(*tab));
		ft_clear_stats(&stats, ft_tablen(*tab));
		ft_clear_tab(tab);
	}
	dir = dir;
	if (j == 1 && dir[0] != NULL)
		ft_putchar('\n');
	return (0);
}
