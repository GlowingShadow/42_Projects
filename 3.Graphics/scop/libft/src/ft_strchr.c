/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:04:31 by REDACTED          #+#    #+#             */
/*   Updated: 2014/11/07 16:47:39 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (s[i] == 0 || c == 0)
		return (NULL);
	while (s[i] != (char)c)
	{
		if (((char)c) != '\0' && s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char*)s + i);
}
