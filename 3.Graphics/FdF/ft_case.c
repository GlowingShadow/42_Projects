/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 04:59:21 by REDACTED          #+#    #+#             */
/*   Updated: 2015/01/20 17:14:06 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int		ft_c12(t_coo coor1, t_coo coor2)
{
	if (coor1.x <= coor2.x && abs(coor2.x - coor1.x) >= abs(coor2.y - coor1.y))
		return (1);
	return (0);
}

int		ft_c34(t_coo coor1, t_coo coor2)
{
	if (coor1.x > coor2.x && abs(coor2.x - coor1.x) >= abs(coor2.y - coor1.y))
		return (1);
	return (0);
}

int		ft_c56(t_coo coor1, t_coo coor2)
{
	if (coor1.y <= coor2.y && abs(coor2.y - coor1.y) >= abs(coor2.x - coor1.x))
		return (1);
	return (0);
}

int		ft_c78(t_coo coor1, t_coo coor2)
{
	if (coor1.y > coor2.y && abs(coor2.y - coor1.y) >= abs(coor2.x - coor1.x))
		return (1);
	return (0);
}
