/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_device_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 23:40:35 by REDACTED          #+#    #+#             */
/*   Updated: 2014/11/29 23:43:50 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_max_major_len(t_data *stats, int j)
{
	int	major_len;
	int	i;

	major_len = 0;
	i = 0;
	while (i < j)
	{
		if (major_len < ft_strlen(ft_itoa((stats[i]).major)))
			major_len = ft_strlen(ft_itoa((stats[i]).major));
		i++;
	}
	return (major_len);
}

int		ft_max_minor_len(t_data *stats, int j)
{
	int	minor_len;
	int	i;

	minor_len = 0;
	i = 0;
	while (i < j)
	{
		if (minor_len < ft_strlen(ft_itoa((stats[i]).minor)))
			minor_len = ft_strlen(ft_itoa((stats[i]).minor));
		i++;
	}
	return (minor_len);
}
