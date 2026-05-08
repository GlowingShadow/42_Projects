/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:05:52 by REDACTED          #+#    #+#             */
/*   Updated: 2014/11/24 16:32:59 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*cp;
	int		i;

	i = 0;
	if (s && f)
	{
		cp = ft_strdup(s);
		while (cp[i] != '\0')
		{
			cp[i] = f(i, cp[i]);
			i++;
		}
		return (cp);
	}
	cp = (char*)malloc(sizeof(char) * 5);
	free(cp);
	return (NULL);
}
