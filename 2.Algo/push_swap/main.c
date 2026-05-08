/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:12:29 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/17 23:01:59 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int ac, char **av, t_env *e)
{
	int		i;

	if (ac == 1)
	{
		ft_putendl("Error: Enter some numbers please");
		exit(-1);
	}
	e->opt = ft_strnew(2);
	if ((i = ft_synth_option(ac, av, &(e->opt))) >= ac)
	{
		ft_putendl("Error: Enter at least 1 numbers please");
		exit(-1);
	}
	ft_valid_argv(av + i);
	e->pile1 = ft_atoi_tab(av + i);
	e->pile2.tab = (int*)malloc(sizeof(int) * e->pile1.size);
	e->pile2.size = 0;
	e->count = 0;
	e->ac = ac - i;
}

t_mvt	ft_choose_algo(int ac, char **av)
{
	t_env	e1;
	t_env	e2;
	t_env	e3;
	t_mvt	*mvt;
	t_small	sm;

	mvt = (t_mvt*)malloc(sizeof(t_mvt) * 3);
	ft_error(ac, av, &e1);
	mvt[0] = ft_algo1(e1);
ft_putstr("Algo1 ");
ft_putnbr((mvt[0]).count);
ft_putstr(":\n");
ft_putendl((mvt[0]).str);
ft_putchar('\n');

	ft_error(ac, av, &e2);
	(mvt[1]) = ft_algo2(e2, sm, 0, 0);
ft_putstr("Algo2 ");
ft_putnbr((mvt[1]).count);
ft_putstr(":\n");
ft_putendl((mvt[1]).str);
ft_putchar('\n');

	ft_error(ac, av, &e3);
	(mvt[2]) = ft_algo3(e3, 6);
ft_putstr("\n\nAlgo3 ");
ft_putnbr((mvt[2]).count);
ft_putstr(":\n");
ft_putendl((mvt[2]).str);
ft_putchar('\n');

	if ((mvt[0]).count < (mvt[1]).count && (mvt[0]).count < (mvt[2]).count)
	{
ft_putendl("Algo1 returned");
		free((mvt[1]).str);
		free((mvt[2]).str);
		return (mvt[0]);
	}
	if ((mvt[1]).count < (mvt[0]).count && (mvt[1]).count < (mvt[2]).count)
	{
ft_putendl("Algo2 returned");
		free((mvt[0]).str);
		free((mvt[2]).str);
		return (mvt[1]);
	}
	if ((mvt[2]).count <= (mvt[0]).count && (mvt[2]).count <= (mvt[1]).count)
	{
ft_putendl("Algo3 returned");
		free((mvt[0]).str);
		free((mvt[1]).str);
		return (mvt[2]);
	}
	return (mvt[0]);
}

int		main(int ac, char **av)
{
	t_env	e;
	t_mvt	mvt;
//	int		i;

	ft_error(ac, av, &e);
	mvt = ft_choose_algo(ac, av);
	ft_putendl(mvt.str);
	if (ft_strlen(mvt.str) != 0)
		(mvt.str)[ft_strlen(mvt.str) - 1] = '\0';
	ft_putendl(mvt.str);
		
/*	if ((i = ft_check_mvt(e.pile1, e.pile2, ft_strjoin_free(mvt.str, " ", 0))) == 1)
		ft_putendl("\nMouvements valides");
	else
		ft_putendl("\nMouvements invalides");
*/	ft_putendl("\t------------------------------------------\n\n");
	if (ft_strlen(e.opt) != 0)
	{
		ft_putstr("Options: ");
		if (ft_strchr(e.opt, 'c') != NULL)
			ft_putchar('c');
		if (ft_strchr(e.opt, 'v') != NULL)
			ft_putchar('v');
		if (ft_strchr(e.opt, 'a') != NULL)
			ft_putchar('a');
		ft_putchar('\n');
		ft_option(e.opt, mvt, e.pile1, e.pile2);
	}
	return (0);
}
