/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readlink.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 04:01:45 by REDACTED          #+#    #+#             */
/*   Updated: 2014/11/29 06:56:09 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, char **argv)
{
	int i;
	char *buf;

	argc =argc;
	argv = argv;
	buf = (char*)malloc(sizeof(char) * 260 + 1);
	ft_strclr(buf);
	i = readlink("ce", buf, 260);
	ft_putnbr(i);
	ft_putchar('\n');
	if (i == -1)
		perror("readlink");
	ft_putendl(buf);
	return (0);
}
