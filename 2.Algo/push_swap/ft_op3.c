/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 18:20:35 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/16 10:33:40 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_env *e)
{
	ft_swap(&(e->pile1));
	ft_swap(&(e->pile2));
	(e->mvt.count)++;
	ft_strcpy(e->mvt.str + e->start, "ss ");
	e->start += 3;
}

void	ft_rrr(t_env *e)
{
	ft_rrot(&(e->pile1));
	ft_rrot(&(e->pile2));
	(e->mvt.count)++;
	ft_strcpy(e->mvt.str + e->start, "rrr ");
	e->start += 4;
}

void	ft_rr(t_env *e)
{
	ft_rot(&(e->pile1));
	ft_rot(&(e->pile2));
	ft_strcpy(e->mvt.str + e->start, "rr ");
	e->start += 3;
	(e->mvt.count)++;
}
