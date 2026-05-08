/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 00:18:45 by REDACTED          #+#    #+#             */
/*   Updated: 2015/04/04 07:09:42 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	ft_solve(t_env e)
{
	double	result;
	double	a;
	double	b;

	a = ((e.power.itab)[1]);
	b = ((e.power.itab)[0]);
	result = -((e.power.itab)[0]) / ((e.power.itab)[1]);
	b == 0 ? result = -result : (void)result;
	printf("a = %g  b = %g\n\n", a, b);
	printf("\tX = -b / a\n");
	printf("\tX = %g / %g\n", (b == 0 ? b : -b), a);
	COLOR(GREEN);
	printf("\tX = %g\n\n", result);
	COLOR(WHITE);
}

void	ft_null(double a, double b)
{
	double	result;

	result = -b / (2 * a);
	COLOR(GREEN);
	printf("Discriminant is null, the solution is:\n");
	COLOR(WHITE);
	printf("a = %g  b = %g\n\n", a, b);
	printf("\tX = -b / 2a\n");
	printf("\tX = %g / 2 * %g\n", (b == 0 ? b : -b), a);
	COLOR(GREEN);
	printf("\tX = %g\n", result);
	COLOR(WHITE);
}

void	ft_positive(double delta, double a, double b)
{
	double	result1;
	double	result2;

	result1 = (-b - ft_sqrt(delta)) / (2 * a);
	result2 = (-b + ft_sqrt(delta)) / (2 * a);
	COLOR(GREEN);
	printf("Discriminant is strictly positive, the 2 solutions are:\n");
	COLOR(WHITE);
	printf("delta = %g  a = %g  b = %g\n\n", delta, a, b);
	printf("\tX1 = (-b - ft_sqrt(delta)) / 2a\n");
	printf("\tX1 = (%g - %g) / (2 * %g)\n", -b, ft_sqrt(delta), a);
	COLOR(GREEN);
	printf("\tX1 = %g\n\n", result1);
	COLOR(WHITE);
	printf("\tX2 = (-b + ft_sqrt(delta)) / 2a\n");
	printf("\tX2 = (%g + %g) / (2 * %g)\n", -b, ft_sqrt(delta), a);
	COLOR(GREEN);
	printf("\tX2 = %g\n", result2);
	COLOR(WHITE);
}

void	ft_negative(double delta, double a, double b)
{
	double	x1;
	double	x2;

	x1 = -b / (2 * a);
	x2 = ft_sqrt(ft_fabs(delta)) / (2 * a);
	COLOR(GREEN);
	printf("Discriminant is strictly positive, the 2 solutions are:\n");
	COLOR(WHITE);
	printf("delta = %g  a = %g  b = %g\n\n", delta, a, b);
	printf("\tX1 = (-b - i * ft_sqrt(|delta|)) / 2a\n");
	printf("\tX1 = (%g - i * ft_sqrt(|%g|)) / (2 * %g)\n", -b, delta, a);
	COLOR(GREEN);
	printf("\tX1 = %g - i * %g\n\n", x1, x2);
	COLOR(WHITE);
	printf("\tX2 = (-b + i * ft_sqrt(|delta|)) / 2a\n");
	printf("\tX2 = (%g + i * %g) / (2 * %g)\n", -b, delta, a);
	COLOR(GREEN);
	printf("\tX2 = %g + i * %g\n\n", x1, x2);
	COLOR(WHITE);
}

void	ft_delta(t_env e)
{
	double	delta;
	double	a;
	double	b;
	double	c;

	a = ((e.power.itab)[2]);
	b = ((e.power.itab)[1]);
	c = ((e.power.itab)[0]);
	delta = b * b - 4 * a * c;
	COLOR(GREEN);
	printf("Calculating discriminant delta:\n");
	COLOR(WHITE);
	printf("a = %g  b = %g  c = %g\n\n", a, b, c);
	printf("\tdelta = b^2 - 4ac\n");
	printf("\tdelta = %g * %g - 4 * %g * %g\n", b, b, a, c);
	printf("\tdelta = %g\n\n", delta);
	if (delta == 0)
		ft_null(a, b);
	if (delta > 0)
		ft_positive(delta, a, b);
	if (delta < 0)
		ft_negative(delta, a, b);
}
