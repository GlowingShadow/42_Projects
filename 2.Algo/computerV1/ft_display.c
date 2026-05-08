/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 22:21:12 by REDACTED          #+#    #+#             */
/*   Updated: 2015/04/04 07:48:52 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	ft_display_reduced(t_itab power)
{
	int		i;

	printf("Reduced form: ");
	i = 0;
	while (i < power.size)
	{
	//	while ((power.itab)[i] == 0 && i < power.size)
	//		i += 1;
		if ((power.itab)[i] < 0)
		{
			printf(((power.itab)[i] < 0 ? "-" : ""));
			printf("%f", -(power.itab)[i]);
		}
		else
			printf("%f", (power.itab)[i]);
		printf(" * X^%d", i);
		if (i == (power.size - 1))
			printf(" = 0\n");
		else
		{
			if ((power.itab)[i + 1] >= 0)
				printf(" + ");
			else
				printf(" - ");
		}
		i++;
	}
}

void	ft_simple(t_env e)
{
	if ((e.power.itab)[0] != 0)
	{
		ft_putstr_color("Error:", RED);
		ft_putstr(" Insolvent equation\n");
	}
	else
	{
		ft_putstr_color("Error:", RED);
		ft_putstr(" All real numbers are solution\n");
	}
	exit(-1);
}

void	ft_display_degree(t_env e)
{
	ft_putstr("Polynomial degree: ");
	ft_putnbr(e.degree);
	ft_putchar('\n');
	if (e.degree == 0)
		ft_simple(e);
	if (e.degree == 1)
	{
		ft_putendl("The solution is:");
		ft_solve(e);
		exit(-1);
	}
	if (e.degree == 2)
	{
		ft_delta(e);
		exit(-1);
	}
	if (e.degree > 2)
	{
		COLOR(YELLOW);
		ft_putstr("The polynomial degree is stricly greater than 2");
		ft_putstr(", I can't solve.\n");
		COLOR(WHITE);
		exit(-1);
	}
}

void	ft_remove_zero(t_env *e)
{
	int	i;

	i = e->power.size - 1;
	while ((e->power.itab)[i] == 0 && i > 0)
	{
		(e->power.size)--;
		(e->degree)--;
		i--;
	}
}

void	ft_display(t_env e)
{
	ft_remove_zero(&e);
	ft_display_reduced(e.power);
	ft_display_degree(e);
	//int j=0;while(j<e.power.size){ft_putnbr((e.power.itab)[j]);j++;}
}
