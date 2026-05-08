/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 20:26:03 by REDACTED          #+#    #+#             */
/*   Updated: 2014/12/03 21:07:06 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_get_time(t_data *stats)
{
	char	*s;
	time_t	t;
	char	*date;

	t = time(NULL);
	s = ctime(stats->epoch);
	date = (char*)malloc(sizeof(char) * 12 + 1);
	if (*stats->epoch < (t - 15778463) || *stats->epoch > t)
	{
		date = ft_strcat(date, ft_strsub(s, 4, 7));
		date = ft_strcat(date, " ");
		date = ft_strcat(date, ft_strsub(s, 20, 4));
	}
	else
		date = ft_strsub(s, 4, 12);
	date[12] = 0;
	return (date);
}
