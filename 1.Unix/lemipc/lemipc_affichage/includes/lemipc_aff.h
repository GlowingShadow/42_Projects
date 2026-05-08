/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc_aff.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 17:02:17 by REDACTED          #+#    #+#             */
/*   Updated: 2016/07/01 17:02:21 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_AFF_H
# define LEMIPC_AFF_H

# include <libft.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/sem.h>
# include <sys/shm.h>
# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# include <mlx.h>

# define RGB(r, g, b)(65536 * (int)(r) + 256 * (int)(g) + (int)(b))

# define OK					0
# define MALLOC_FAILED		1
# define FTOK_FAILED		2
# define SEMCTL_FAILED		3
# define SEMOP_FAILED		4
# define SEMGET_FAILED		5
# define SHMGET_FAILED		6
# define SHMAT_FAILED		7
# define SHMDT_FAILED		8
# define BAD_ARGS			9
# define NO_PLACE			10
# define PLAYER_DEAD		11
# define NO_GAME			12
# define XPM_LOAD_FAIL		13
# define TEAM_NOT_RGSTRD	14

# define UNLOCK		1
# define LOCK		-1

# define LEAVE_KEY		53
# define PAUSE_KEY		35

# define RFRSH_TIMEOUT	30
# define VOID_CHAR		-1
# define WIDTH			20
# define HEIGHT			20
# define SQUARE_SIZE	25
# define WIN_SIZE_X		(e->win_x + 10 + 260)
# define WIN_SIZE_Y		(e->win_y + 10)
# define GRID_COLOR		0x466DD0
# define BG_COLOR		0x232A3C
# define BOX_COLOR		0x000000
# define BOXBG_COLOR	0x384B7A
# define WHITEC			0xFFFFFF
# define MLX_PITW		mlx_put_image_to_window

# define NB_LOGOS		10
# define S_X			WIDTH * (SQUARE_SIZE + 1) + 30 + (i % 4) * 60
# define S_Y			(i / 4) * 40 + 55

typedef struct	s_img
{
	int		width;
	int		height;
	void	*xpm;
	void	*mlx;
}				t_img;

typedef struct	s_int
{
	int				n;
	int				amount;
	t_img			*logo;
	t_img			*color;
	struct s_int	*next;
}				t_int;

typedef struct	s_env
{
	int			game_won;
	char		*winner;
	int			game_paused;
	int			end_game;
	char		*mapcpy;
	key_t		key;
	int			sema1_id;
	int			shm1_id;
	void		*data;
	char		*cdata;
	int			size;
	t_img		*logos;
	t_img		*color;
	void		*mlx;
	void		*win;
	void		*img;
	t_img		*grid;
	t_img		*bg;
	int			win_x;
	int			win_y;
	t_int		*teams;
	t_int		*end_team;
	int			team_ind;
}				t_env;

void			init_ipcs(t_env *e, char *path, int id);
void			op_sem(t_env *e, int operation);
void			register_teams(t_env *e);

void			launch_mlx(t_env *e);
void			get_logos(t_env *e);
void			fill_img(t_env *e, t_img *image, int color);
int				ft_mlx_image_pixel_put(t_env *e, int x, int y, int color);
void			ft_mlx_image_pixel_put2(t_img *image, int x, int y, int color);
void			ft_mlx_image_pixel_del(t_img *image, int x, int y);
t_img			*ft_mlx_new_image_void(t_env *e, int size_x, int size_y);
void			ft_mlx_print_pixel(t_img *image, int x, int y);

void			print_register(t_env *e);
void			printmap(t_env *e, char *map);

void			draw_win(t_env *e, t_int *win, int i, int j);
void			draw_game(t_env *e);
void			draw_stats(t_env *e);
void			draw_grid(t_env *e);
void			draw_background(t_env *e);
t_int			*get_team(t_env *e, int team);

#endif
