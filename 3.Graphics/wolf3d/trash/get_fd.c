/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/20 14:16:24 by REDACTED          #+#    #+#             */
/*   Updated: 2015/05/30 13:21:08 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_log_file(t_env *e)
{
	char	*str;
	time_t	t;

	t = time(NULL);
	str = ctime(&t);
	str = ft_strsub(str, 4, 15);
	e->logs->dist = open(ft_strjoin("logs/dist_", str), O_CREAT | O_RDWR | O_APPEND, 0666);
	e->logs->coo = open(ft_strjoin("logs/coo_", str), O_CREAT | O_RDWR | O_APPEND, 0666);
	e->logs->base = open(ft_strjoin("logs/base_", str), O_CREAT | O_RDWR | O_APPEND, 0666);
	e->logs->inter = open(ft_strjoin("logs/inter_", str), O_CREAT | O_RDWR | O_APPEND, 0666);
	dprintf(e->logs->dist, "coordonees camera\t\t\t\tangle\t\t\t\t\t\tdistance du mur HOR/VER\n\n");
	dprintf(e->logs->coo, "MUR\t\tcoordonees camera\t\tangle\t\t\t\tcoordonee intersection\t equivalent **map\n\n");
}

void	ft_log_base(t_env *e)
{
	dprintf(e->logs->base, \
		"winX: %d\twinY: %d\nscreen: %d block_size: %d map_size: %dx%d\ncamX: %d\tcamY: %d\n cam_low:\t%lf\t(%lf)\n cam_mid:\t%lf\t(%lf)\n cam_high:\t%lf\t(%lf)\n\n",\
		e->win_x, e->win_y, e->screen, e->BS, e->map_size, e->map_size, (int)e->cam_x, (int)e->cam_y, e->cam_low, ft_degree_scale(e->cam_low),\
		e->cam_mid, ft_degree_scale(e->cam_mid),e->cam_high, ft_degree_scale(e->cam_high));
}

void	ft_log_hor(t_env *e, float ray, int xa, int x, int y)
{
	dprintf(e->logs->coo, "HOR\t\tcamX: %d camY: %d\t\tray: (%lf)  \t", (int)e->cam_x, (int)e->cam_y, ray);
	dprintf(e->logs->coo, "xa: %d \tx: %d\ty: %d\t\t", xa, x, y);
	dprintf(e->logs->coo, "[%d][%d]\n", y / e->BS, x / e->BS);
}

void	ft_log_ver(t_env *e, float ray, int ya, int x, int y)
{
	dprintf(e->logs->coo, "VER\t\tcamX: %d camY: %d\t\tray: (%lf)  \t", (int)e->cam_x, (int)e->cam_y, ray);
	dprintf(e->logs->coo, "ya: %d\tx: %d\ty: %d\t\t", ya, x, y);
	dprintf(e->logs->coo, "[%d][%d]\n", y / e->BS, x / e->BS);
}

void	ft_log_dist(t_env *e, float ray, float ray_scale)
{
	dprintf(e->logs->dist, "camX: %d camY: %d\t\tray: %lf (%lf)   \t ", (int)e->cam_x, (int)e->cam_y, ray, ray_scale);
}

void	ft_log_dist_hor(t_env *e, float interx)
{
	dprintf(e->logs->dist, "<-HOR %lf\t\n", interx);
}

void	ft_log_dist_ver(t_env *e, float intery)
{
	dprintf(e->logs->inter, "%lf VER->\n", intery);
}

void	ft_log_column(t_env *e, float height, int start, int end, int color)
{
	dprintf(e->logs->dist, "\ttaille: %lf\t%d -> %d\t%#06.6x\n", height, start, end, color);
}

void	ft_log_inter1(t_env *e, float ray)
{
	dprintf(e->logs->inter, "\nray %lf\n", ray);
}

void	ft_log_inter(t_env *e, float x, float y, float inter)
{
	dprintf(e->logs->inter, "camX %lf\tcamY %lf\tx %lf\ty %lf\tinter %lf\t", e->cam_x, e->cam_y, x, y, inter);
}


