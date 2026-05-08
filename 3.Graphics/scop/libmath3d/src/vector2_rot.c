/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:01:02 by REDACTED          #+#    #+#             */
/*   Updated: 2017/05/24 14:02:47 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libmath3d.h>

t_vector2	vector2_rot(t_vector2 v, float rad, float rot_direction)
{
	rad *= rot_direction;
	return ((t_vector2){v.x * cosf(rad) - v.y * sinf(rad), \
						v.x * sinf(rad) + v.y * cosf(rad)});
}
