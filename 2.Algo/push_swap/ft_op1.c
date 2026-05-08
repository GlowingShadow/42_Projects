/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 18:20:15 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/15 19:10:19 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_env *e)
{
	ft_swap(&(e->pile2));
	(e->mvt.count)++;
	ft_strcpy(e->mvt.str + e->start, "sb ");
	e->start += 3;
}

void	ft_sa(t_env *e)
{
	ft_swap(&(e->pile1));
	(e->mvt.count)++;
	ft_strcpy(e->mvt.str + e->start, "sa ");
	e->start += 3;
}

void	ft_rb(t_env *e)
{
	ft_rot(&(e->pile2));
	(e->mvt.count)++;
	ft_strcpy(e->mvt.str + e->start, "rb ");
	e->start += 3;
}

void	ft_ra(t_env *e)
{
	ft_rot(&(e->pile1));
	ft_strcpy(e->mvt.str + e->start, "ra ");
	e->start += 3;
	(e->mvt.count)++;
}
