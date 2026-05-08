/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:04:41 by REDACTED          #+#    #+#             */
/*   Updated: 2015/02/08 14:34:34 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int						ft_strcm(const char *s1, const char *s2)
{
	int					i;
	const unsigned char *cp1;
	const unsigned char *cp2;

	cp1 = (const unsigned char*)s1;
	cp2 = (const unsigned char*)s2;
	i = 0;
	while (cp2[i] == cp1[i])
	{
		i++;
		if (cp2[i] == '\0' && cp1[i] == '\0')
			return (0);
	}
	printf("%d\n", cp1[i] - cp2[i]);
	return (cp1[i] - cp2[i]);
}

int	main(int ac, char **av)
{
	ft_strcm(av[1], av[2]);
	return (0);
}
