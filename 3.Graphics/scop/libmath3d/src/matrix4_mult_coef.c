/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4_mult_coef.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:01:02 by REDACTED          #+#    #+#             */
/*   Updated: 2017/05/24 14:02:47 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libmath3d.h>

t_matrix4	matrix4_mult_coef(t_matrix4 m, float coef)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		m.m.e[i] *= coef;
		i++;
	}
	return (m);
}
