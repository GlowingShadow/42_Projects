/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:16:54 by REDACTED          #+#    #+#             */
/*   Updated: 2014/11/10 20:22:58 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char    *ft_no_bad_char(char *str)
{
	int    i;
	int    j;
	char *dest;

	dest = (char*)malloc(sizeof(char));
	i = 0;
	j = 0;
	while(str[i])
	{
		if (i > 0 && str[i] > 64 && str[i] < 91)
			str[i] = str[i] + 32;
		while (str[i] == 32)
			i++;
		dest[j] = str[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

int    ft_find_word(char *str1, char *str2)
{
	int        i;
	int        j;

	i = 0;
	j = 0;
	while (str1[i] == str2[j])
	{
		i++;
		j++;
		if (str1[i] == str2[j] && str2[j] == '\0')
		{
			write(1, "Alert!!!\n", 9);
			return (1);
		}
	}
	return (0);
}

int        main(int argc, char **argv)
{
	int    i;

	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		ft_find_word(ft_no_bad_char(argv[i]), "president");
		ft_find_word(ft_no_bad_char(argv[i]), "attack");
		ft_find_word(ft_no_bad_char(argv[i]), "Powers");
		i++;
	}
	return (0);
}
