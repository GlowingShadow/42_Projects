/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bad_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 03:48:40 by REDACTED          #+#    #+#             */
/*   Updated: 2014/12/05 03:54:43 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_bad_argument(char **argv)
{
	int	i;

	i = 0;
	while (i < ft_tablen(argv))
	{
		if (argv[i][0] == 0)
		{
			ft_putendl("ls: fts_open: No such file or directory");
			exit(-1);
		}
		i++;
	}
}
