/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:03:26 by REDACTED          #+#    #+#             */
/*   Updated: 2014/11/07 16:41:11 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*dest;
	char	d;

	d = (char)c;
	dest = (char*)b;
	i = 0;
	while (i < len)
	{
		dest[i] = d;
		i++;
	}
	return (b);
}
