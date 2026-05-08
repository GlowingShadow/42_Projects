/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 18:20:27 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/15 19:12:54 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb(t_env *e)
{
	ft_rrot(&(e->pile2));
	(e->mvt.count)++;
	ft_strcpy(e->mvt.str + e->start, "rrb ");
	e->start += 4;
}

void	ft_rra(t_env *e)
{
	ft_rrot(&(e->pile1));
	(e->mvt.count)++;
	ft_strcpy(e->mvt.str + e->start, "rra ");
	e->start += 4;
}

void	ft_pa(t_env *e)
{
	ft_push(&(e->pile2), &(e->pile1));
	(e->mvt.count)++;
	ft_strcpy(e->mvt.str + e->start, "pa ");
	e->start += 3;
}

void	ft_pb(t_env *e)
{
	ft_push(&(e->pile1), &(e->pile2));
	(e->mvt.count)++;
	ft_strcpy(e->mvt.str + e->start, "pb ");
	e->start += 3;
}
