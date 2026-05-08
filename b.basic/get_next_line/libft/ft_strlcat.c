/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:05:33 by REDACTED          #+#    #+#             */
/*   Updated: 2014/11/16 13:25:34 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	int		i;
	int		j;
	size_t	sizeo;

	sizeo = size;
	len = (size_t)ft_strlen(dst) + (size_t)ft_strlen(src);
	j = 0;
	while (dst[i] != 0 && (int)size-- > 0)
		i++;
	while ((int)size > 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		size--;
		i++;
		j++;
	}
	if ((int)size > 0)
	{
		dst[i] = '\0';
		return (len);
	}
	else
		return (sizeo + (size_t)ft_strlen(src));
}
