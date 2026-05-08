/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 22:41:42 by REDACTED          #+#    #+#             */
/*   Updated: 2015/01/23 02:34:53 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFF_SIZE 2048
# define CTE1 0.8
# define CTE2 0.8
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

typedef struct	s_coo
{
	int	x;
	int	y;
	int	z;
}				t_coo;

typedef struct	s_point
{
	int	c1x;
	int	c2x;
	int	c1y;
	int	c2y;
}				t_point;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	int		**pts;
	t_coo	**coor;
	int		max_y;
	int		max_x;
	int		max_z;
	int		lines;
	int		edge;
	float	haut;
	int		xrib;
	int		yrib;
	int		diffz;
	float	c_edge;
	float	c_haut;
	int		move_x;
	int		move_y;
}				t_env;

int				ft_c12(t_coo coor1, t_coo coor2);
int				ft_c34(t_coo coor1, t_coo coor2);
int				ft_c56(t_coo coor1, t_coo coor2);
int				ft_c78(t_coo coor1, t_coo coor2);
void			ft_print_line1(t_env e, t_coo **coor);
void			ft_print_line2(t_env e, t_coo **coor);
void			ft_print_points(t_env e, t_coo **coor);
t_coo			**ft_assign_xy2(int **pts, t_env e, int i);
void			ft_valid_tab(char ***tmp);
void			ft_valid_line(char **l);
void			ft_putnbr_str(int *n);
void			ft_clear_tab(char ***tab);
void			ft_putnbr_tab(int **n);
int				**ft_get_coo(char **av, int i);
int				ft_tablen(char **tab);
int				ft_tablen_int(int **tab);
int				ft_itaballoc(char **av);
int				get_next_line(int const fd, char **line);
void			ft_puttab(char **tab);
void			ft_constants(t_env *e, int **coo);
float			ft_altitude(int x, int cas, t_coo c1, t_coo c2);
int				ft_color(double t, t_env e);
int				ft_couleur_ulysse(int alt);
int				ft_diff_altitude(int **n);
int				ft_mlx_image_pixel_put(t_env e, int x, int y, int color);
void			ft_launch_mlx(t_env *e);
void			ft_no_points(t_env *e);
void			ft_coef(t_env *e);
void			ft_move_right(t_env *e);
void			ft_move_left(t_env *e);
void			ft_move_down(t_env *e);
void			ft_move_up(t_env *e);
void			ft_zoom(t_env *e, int keycode);
int				ft_expose_hook(t_env *e);

#endif
