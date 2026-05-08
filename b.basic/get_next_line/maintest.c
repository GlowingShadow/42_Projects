/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:06:32 by REDACTED          #+#    #+#             */
/*   Updated: 2014/11/17 23:50:59 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main(int ac, char **av) 
{ 
	char *line; 
	int fd;

	(void)ac;
	(void)av;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		printf("%s\n", line);
//	while (1)
//		;
	return (0);
}
