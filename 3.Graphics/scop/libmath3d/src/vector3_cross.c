/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:01:02 by REDACTED          #+#    #+#             */
/*   Updated: 2017/05/24 14:02:47 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libmath3d.h>

t_vector3	vector3_cross(const t_vector3 v1, const t_vector3 v2)
{
	return ((t_vector3){v1.y * v2.z - v1.z * v2.y, \
						v1.z * v2.x - v1.x * v2.z, \
						v1.x * v2.y - v1.y * v2.x});
}
