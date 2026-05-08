/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 16:31:02 by REDACTED          #+#    #+#             */
/*   Updated: 2014/11/15 21:31:11 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int			main()
{
	int		i;
	int		j;
	char	*line;
	
	line = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	i = open("a.txt", O_RDONLY);
	ft_putnbr(i);
	ft_putchar('\n');


//	get_next_line(i, &line);
//	ft_putstr(line);

	/*
	while (( j = get_next_line(i, &line)) == 1)
	{
		ft_putnbr(j);
	    printf("\nRESULTAT line 1: %d characters\n", ft_strlen(line));
		ft_putstr(line);
		ft_putchar('\n');
	}
*/
	j = get_next_line(i, &line);
	ft_putnbr(j);
	ft_putstr(line);
	ft_putchar('\n');

	j = get_next_line(i, &line);
	ft_putnbr(j);
	ft_putstr(line);
	ft_putchar('\n');
	
	j = get_next_line(i, &line);
	ft_putnbr(j);
	ft_putstr(line);
	ft_putchar('\n');
	
	j = get_next_line(i, &line);
	ft_putnbr(j);
	ft_putstr(line);
	ft_putchar('\n');
	
	j = get_next_line(i, &line);
	ft_putnbr(j);
	ft_putstr(line);
	ft_putchar('\n');
	
	j = get_next_line(i, &line);
	ft_putnbr(j);
	ft_putstr(line);
	ft_putchar('\n');
	
	j = get_next_line(i, &line);
	ft_putnbr(j);
	ft_putstr(line);
	ft_putchar('\n');
	
	j = get_next_line(i, &line);
	ft_putnbr(j);
	ft_putstr(line);
	ft_putchar('\n');
	
	j = get_next_line(i, &line);
	ft_putnbr(j);
	ft_putstr(line);
	ft_putchar('\n');
	
	j = get_next_line(i, &line);
	ft_putnbr(j);
	ft_putstr(line);
	ft_putchar('\n');
	
	j = get_next_line(i, &line);
	ft_putnbr(j);
	ft_putstr(line);
	ft_putchar('\n');
	
	j = get_next_line(i, &line);
	ft_putnbr(j);
	ft_putstr(line);
	ft_putchar('\n');
	
	j = get_next_line(i, &line);
	ft_putnbr(j);
	ft_putstr(line);
	ft_putchar('\n');
	
	j = get_next_line(i, &line);
	ft_putnbr(j);
	ft_putstr(line);
	ft_putchar('\n');
	
	j = get_next_line(i, &line);
	ft_putnbr(j);
	ft_putstr(line);
	ft_putchar('\n');
	
	j = get_next_line(i, &line);
	ft_putnbr(j);
	ft_putstr(line);
	ft_putchar('\n');
	
	j = get_next_line(i, &line);
	ft_putnbr(j);
	ft_putstr(line);
	ft_putchar('\n');
	
	j = get_next_line(i, &line);
	ft_putnbr(j);
	ft_putstr(line);
	ft_putchar('\n');

	close(i);
	return (0);
}
