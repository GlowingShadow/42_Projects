/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 17:02:38 by REDACTED          #+#    #+#             */
/*   Updated: 2016/07/01 17:02:39 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc_aff.h>

void			fill_img(t_env *e, t_img *image, int color)
{
	int		i;
	int		j;

	i = 0;
	image->xpm = mlx_new_image(e->mlx, SQUARE_SIZE, SQUARE_SIZE);
	image->width = SQUARE_SIZE;
	image->height = SQUARE_SIZE;
	image->mlx = e->mlx;
	while (i < SQUARE_SIZE)
	{
		j = 0;
		while (j < SQUARE_SIZE)
		{
			ft_mlx_image_pixel_put2(image, i, j, color);
			j++;
		}
		i++;
	}
}

static void		make_backgrounds(t_env *e)
{
	char	*path[10];
	int		i;

	path[0] = "lemipc_affichage/img/Red.XPM";
	path[1] = "lemipc_affichage/img/Green.XPM";
	path[2] = "lemipc_affichage/img/Cyan.XPM";
	path[3] = "lemipc_affichage/img/green_dark.XPM";
	path[4] = "lemipc_affichage/img/purple.XPM";
	path[5] = "lemipc_affichage/img/yellow.XPM";
	path[6] = "lemipc_affichage/img/Brown.XPM";
	path[7] = "lemipc_affichage/img/Orange.XPM";
	path[8] = "lemipc_affichage/img/Gray.XPM";
	path[9] = "lemipc_affichage/img/Blue.XPM";
	i = 0;
	while (i < NB_LOGOS)
	{
		ft_putendl(path[i]);
		if ((e->color[i].xpm = mlx_xpm_file_to_image(e->mlx, path[i], \
			&(e->color[i].width), &(e->color[i].height))) == NULL)
			ft_errexit("mlx_xpm_file_to_image failed", RED, XPM_LOAD_FAIL);
		e->color[i].mlx = e->mlx;
		i++;
	}
}

void			get_logos(t_env *e)
{
	char	*path[10];
	int		i;

	path[0] = "lemipc_affichage/img/Radiation.XPM";
	path[1] = "lemipc_affichage/img/Rain.XPM";
	path[2] = "lemipc_affichage/img/sunlight.XPM";
	path[3] = "lemipc_affichage/img/Leaf.XPM";
	path[4] = "lemipc_affichage/img/cell.XPM";
	path[5] = "lemipc_affichage/img/Energy.XPM";
	path[6] = "lemipc_affichage/img/Love.XPM";
	path[7] = "lemipc_affichage/img/Recycle.XPM";
	path[8] = "lemipc_affichage/img/Twoleaves.XPM";
	path[9] = "lemipc_affichage/img/Leaf8.XPM";
	i = 0;
	while (i < NB_LOGOS)
	{
		ft_putendl(path[i]);
		if ((e->logos[i].xpm = mlx_xpm_file_to_image(e->mlx, path[i], \
			&(e->logos[i].width), &(e->logos[i].height))) == NULL)
			ft_errexit("mlx_xpm_file_to_image failed", RED, XPM_LOAD_FAIL);
		e->logos[i].mlx = e->mlx;
		i++;
	}
	make_backgrounds(e);
}
