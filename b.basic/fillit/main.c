/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 19:36:27 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/13 19:36:29 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			error(char *msg, int error_code)
{
	(void)msg;
	ft_putstr("error\n");
	exit(error_code);
}

static t_env	*init_env(void)
{
	t_env	*e;
	int		i;

	e = (t_env*)malloc(sizeof(t_env));
	i = 0;
	while (i < 27)
	{
		if (i < 19)
			ft_bzero(e->list[i], 17);
		ft_bzero(e->pieces[i], 17);
		i++;
	}
	return (e);
}

static void		write_list(t_env *e)
{
	ft_strcpy(e->list[0], "#...#...#...#...");
	ft_strcpy(e->list[1], "####............");
	ft_strcpy(e->list[2], "##..##..........");
	ft_strcpy(e->list[3], "###...#.........");
	ft_strcpy(e->list[4], "###.#...........");
	ft_strcpy(e->list[5], "#...###.........");
	ft_strcpy(e->list[6], "..#.###.........");
	ft_strcpy(e->list[7], ".#...#..##......");
	ft_strcpy(e->list[8], "#...#...##......");
	ft_strcpy(e->list[9], "##..#...#.......");
	ft_strcpy(e->list[10], "##...#...#......");
	ft_strcpy(e->list[11], ".##.##..........");
	ft_strcpy(e->list[12], "#...##...#......");
	ft_strcpy(e->list[13], "##...##.........");
	ft_strcpy(e->list[14], ".#..##..#.......");
	ft_strcpy(e->list[15], "###..#..........");
	ft_strcpy(e->list[16], ".#..###.........");
	ft_strcpy(e->list[17], ".#..##...#......");
	ft_strcpy(e->list[18], "#...##..#.......");
}

int				main(int ac, char **av)
{
	t_env *e;

	if (ac != 2)
		error("Error: Bad args\n", BAD_ARG);
	e = init_env();
	write_list(e);
	get_map(e, av[1]);
	adjust_map(e);
	result(e);
	return (0);
}
