/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_strchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:53:14 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:53:16 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_int_strchr(int *istr, int size, int n)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (istr[i] == n)
			return (i);
		i++;
	}
	return (-1);
}
