/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 14:16:42 by REDACTED          #+#    #+#             */
/*   Updated: 2015/05/21 14:21:48 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float	rtod(float radians)
{
    return (radians * (180.0 / M_PI));
}

float	dtor(float degree)
{
    return (degree * M_PI / 180.0);
}


int	main(int ac, char **av)
{
	if (ac != 4)
	{
		printf("Pas assez d arguments\n");
		return (0);
	}
	float	ray;
	int 	block;
	int		cam_x;
	int		cam_y;

	cam_x = atof(av[1]);
	cam_y = atof(av[2]);
	ray = atof(av[3]);
	block = 60;

	printf("Angle: %g block: %d\ncamX: %d\ncamy: %d\n\n", ray, block, cam_x, cam_y);
	
	float	inter;
	int 	x;
	int 	y;
	int 	tmpx;
	int 	tmpy;

	if (ray >= 0 && ray < 180)
		y = (cam_y / block) * block - 1;
	else if (ray >= 180 && ray < 360)
		y = (cam_y / block) * block + block;
	else
		exit(3);
	x = cam_x + (cam_y - y) / tan(dtor(ray));
	tmpx = abs(cam_x - x);
	tmpx = tmpx * tmpx;
	tmpy = abs(cam_y - y);
	tmpy = tmpy * tmpy;
	inter = sqrt(tmpx + tmpy);

	float	inter2;
	int		y2;
	int		x2;
	int 	tmpx2;
	int 	tmpy2;

	if ((ray >= 270 && ray < 360) || (ray >= 0 && ray < 90))
		x2 = (cam_x / block) * block + block;
	else if (ray >= 90 && ray < 270)
		x2 = (cam_x / block) * block - 1;
	else
		exit(4);
	y2 = cam_y + (cam_x - x2) * tan(dtor(ray));
	tmpx2 = abs(cam_x - x2);
	tmpx2 = tmpx2 * tmpx2;
	tmpy2 = abs(cam_y - y2);
	tmpy2 = tmpy2 * tmpy2;
	inter2 = sqrt(tmpx2 + tmpy2); 

	printf("Intersection mur horizontal:\nx1: %d\ny1: %d\nDistance: %lf\n\n", x, y, inter);
	printf("Intersection mur vertical:\nx2: %d\ny2: %d\nDistance: %lf\n\n", x2, y2, inter2);
	return (0);
}