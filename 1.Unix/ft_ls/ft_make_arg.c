/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 02:26:16 by REDACTED          #+#    #+#             */
/*   Updated: 2015/02/13 02:30:42 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_make_arg(char ***tab, char *opt, char *dir)
{
	(*tab)[0] = "ft_ls";
	(*tab)[1] = ft_strjoin("-", opt);
	(*tab)[2] = ft_strdup(dir);
	(*tab)[3] = NULL;
}
