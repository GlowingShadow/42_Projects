/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 01:45:36 by REDACTED          #+#    #+#             */
/*   Updated: 2015/05/03 23:15:08 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H

# include <libft.h>
# include <GLFW/glfw3.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# define COLOR_BLACK "\033[30m"
# define COLOR_RED "\033[31m"
# define COLOR_GREEN "\033[32m"
# define COLOR_YELLOW "\033[33m"
# define COLOR_BLUE "\033[34m"
# define COLOR_MAGENTA "\033[35m"
# define COLOR_CYAN "\033[36m"
# define COLOR_WHITE "\033[37m"
# define COLOR_NONE "\033[0m"

typedef	struct	s_color
{
	int			red;
	int			green;
	int			blue;
}				t_color;

typedef struct	s_env
{
	char		***alpha;
	char		***digit;
	GLFWwindow	*win;
	char		**map;
	int			lvl;
	char		*lvl_name;
	int			score;
	int			live;
	float		player_x;
	char		brick_size;
	int			brick_num;
	float		brick_x;
	float		bubble_x;
	float		bubble_y;
	float		old_x;
	float		old_y;
	int			bbl_move;
	float		bbl_x;
	float		bbl_y;
	char		magmetised;
	char		runned;
	char		status;
}				t_env;

int				ark_getblocks(t_env *env);
void			ark_error(char *str);
void			ark_drawlevel(t_env env);
void			ark_display(t_env *env);
void			ark_drawbegin();
void			ark_drawplayer(t_env env);
void			ark_drawend(t_env env);
void			ark_drawinfo(t_env env);
void			ark_drawbubble(t_env env);
void			ark_launchbubble(t_env *env);
void			ark_explodebrick(t_env *env);
void			ark_success(char *str);
void			ark_gameinit(t_env *env);
void			ark_changelevel(t_env *env);
void			ark_winner(t_env env);
void			ark_gameover(t_env env);
t_color			ark_color(int red, int green, int blue);
float			ark_drawcharcol(char **tab, float x, float y, t_color color);
void			ark_windowsizecall(GLFWwindow *win, int width, int height);
#endif
