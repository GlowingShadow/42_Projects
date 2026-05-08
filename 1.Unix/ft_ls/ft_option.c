/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 06:36:54 by REDACTED          #+#    #+#             */
/*   Updated: 2014/12/10 16:44:15 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

t_data		*ft_option(char ***tab, char *opt)
{
	t_data	*stats;

	if (ft_strchr(opt, 'a') == NULL)
		*tab = ft_maketab_ls(tab);
	if (ft_strchr(opt, 't') != NULL && (*tab) != NULL)
		ft_maketab_lst(tab);
	if (ft_strchr(opt, 'r') != NULL && (*tab) != NULL)
		*tab = ft_maketab_lsr(tab);
	if (ft_strchr(opt, 'l') != NULL && (*tab) != NULL)
	{
		stats = ft_maketab_lsl(tab);
		return (stats);
	}
	return (NULL);
}
