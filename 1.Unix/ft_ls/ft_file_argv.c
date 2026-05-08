/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 15:40:53 by REDACTED          #+#    #+#             */
/*   Updated: 2014/12/12 16:04:29 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_file_argv(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_isdirectory(argv[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
