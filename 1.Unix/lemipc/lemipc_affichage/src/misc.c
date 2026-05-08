/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 17:02:50 by REDACTED          #+#    #+#             */
/*   Updated: 2016/07/01 17:02:52 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc_aff.h>

void		print_register(t_env *e)
{
	t_int	*ptr;

	ptr = e->teams;
	while (ptr != NULL)
	{
		ft_putnbr(ptr->n);
		ptr = ptr->next;
	}
	ft_putchar(10);
}

void		printmap(t_env *e, char *map)
{
	int		i;

	i = 0;
	ft_putchar(10);
	while (i < e->size - 1)
	{
		if (i > 0 && i % WIDTH == 0)
			ft_putchar(10);
		if (map[i] == VOID_CHAR)
			ft_putchar('.');
		else
			ft_putnbr(map[i]);
		ft_putchar(32);
		i++;
	}
	ft_putchar(10);
}
