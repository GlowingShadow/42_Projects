/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:06:31 by REDACTED          #+#    #+#             */
/*   Updated: 2014/11/09 15:40:30 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*s;

	s = (char*)safe_malloc(sizeof(char) * size);
	while (size)
	{
		s[size - 1] = '\0';
		size--;
	}
	return (s);
}
