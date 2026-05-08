/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 11:42:37 by REDACTED          #+#    #+#             */
/*   Updated: 2015/02/13 16:44:26 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	main(void)
{
	int	x;
	
	x = 0;
	while (x < 50) // decalage de la suite de nombres
	{
		rand();
		x++;
	}
	x = 0;
	while (x < 1500) // nombre maximum d'arguments
	{
		ft_putnbr(rand());
		ft_putchar(' ');
		x++;
	}
	return (0);
}
