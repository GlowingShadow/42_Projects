/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testbf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/15 16:06:29 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/15 16:43:48 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libft.h>

static const char alphabet[] = "0123456789:";
//static const int alphabetSize = sizeof(alphabet) - 1;

void ft_next_index(char* str, int index, int op_n)
{
	int	i;
	int	len;

	len = ft_strlen(alphabet);
	i = 0;
	while (i < len)
	{
		str[index] = alphabet[i];
		if (index == op_n - 1)
			ft_putendl(str);
		else 
			ft_next_index(str, index + 1, op_n);
		i++;
	}
}

void ft_brute_force(int op_max)
{
	char	*buf;
	int		i;

	i = 1;
	buf = ft_strnew(op_max + 1);
	while (i <= op_max)
	{
		ft_next_index(buf, 0, i);
		i++;
	}
	free(buf);
}

int main(int ac, char **av)
{
	ft_brute_force(av[1][0] - 48);
	return 0;
}
