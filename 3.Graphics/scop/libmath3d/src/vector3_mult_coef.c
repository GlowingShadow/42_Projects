/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_mult_coef.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:01:02 by REDACTED          #+#    #+#             */
/*   Updated: 2017/05/24 14:02:47 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libmath3d.h>

t_vector3	vector3_mult_coef(t_vector3 v, float coef)
{
	return ((t_vector3){v.x * coef, v.y * coef, v.z * coef});
}
