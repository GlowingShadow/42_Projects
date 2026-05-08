/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:57:00 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:57:02 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <libft.h>

# define MAX_COO				100

# define ERROR					99
# define MALLOC_FAILED			98
# define OK						0
# define BAD_ARG				1
# define BAD_ANTS_NUMBER		2
# define COMMAND_REUSED			3
# define BAD_ROOM_NAME			4
# define BAD_ROOM_COO			5
# define COMMAND_ERROR			6
# define UNKNOW_COMMAND			7
# define NO_START_END			8
# define NO_WAY					9
# define DATA_CORRUPT			10
# define ROOM_OVERFLOW			11

# define BUFF			e->rooms_amount + 2
# define SIZE			e->rooms_amount + 1
# define ID				e->rooms_amount
# define WAYS_AMOUNT	e->ways_amount

struct s_room;

typedef struct		s_matrix
{
	int				i;
	int				j;
	char			**tab;
	int				debit;
}					t_matrix;

typedef struct		s_way
{
	int				id;
	int				*istr;
	int				*istr2;
	int				size;
	struct s_way	*next;
}					t_way;

typedef struct		s_int
{
	int				id;
	int				size;
	int				room_id;
	struct s_int	*next;
	struct s_int	*next_way;
}					t_int;

typedef struct		s_ant
{
	int				id;
	t_way			*my_way;
	int				rooms_taken;
	struct s_room	*room_pos;
	struct s_ant	*next;
}					t_ant;

typedef struct		s_tube
{
	struct s_room	*room_dest;
	struct s_tube	*next;
}					t_tube;

typedef struct		s_room
{
	int				id;
	int				way_id;
	char			*name;
	int				x;
	int				y;
	t_ant			*ant;
	int				room_left;
	int				tubes_amount;
	t_tube			*tubes;
	struct s_room	*next;
}					t_room;

typedef struct		s_combi
{
	t_istr			*ways;
	int				total_len;
}					t_combi;

typedef struct		s_str
{
	char			*str;
	struct s_str	*next;
}					t_str;

typedef struct		s_env
{
	t_str			*map;
	t_str			*endmap;
	int				command_id;
	int				ants_amount;
	int				ants_left;
	int				ants_waiting;
	t_ant			*ants;
	int				rooms_amount;
	int				ra_coef;
	t_room			*start_room;
	t_room			*end_room;
	t_room			*rooms;
	int				debit;
	int				neighbour;
	int				algo;
	int				ways_amount;
	int				ways_tested;
	int				ways_found;
	t_way			*ways;
	t_way			*endways;
	t_combi			*combi;
	int				prints;
	int				color;
	int				matrix;
}					t_env;

void				ft_errexit(char *message, int code);
void				ft_free_tab(char **tab);
int					ft_isdigit_str(char *str);
int					ft_int_strchr(int *istr, int size, int n);
t_int				*ft_int_listchr(t_int *start, int n);
t_int				*ft_int_listdup(t_int *start);
t_way				*sort_list(t_env *e, t_way *ways);

void				ft_print_info(t_env *e, char *msg);
void				print_ways(t_env *e);
void				printistr(t_env *e, int *istr, int size);
void				print_combis(t_env *e);
void				print_matrix(t_env *e, char **tab);
void				print_found(t_env *e, int *set, t_matrix matx);
void				print_found_amount(t_env *e);
void				print_found_simple(t_env *e, t_room *room, int k);
void				print_map(t_str	*map);

void				ft_get_map(t_env *e);
int					ft_iscomment(char *line);
int					ft_iscommand(char *line);
int					ft_isants(t_env *e, char *line);
int					ft_isroom(t_env *e, char *line, int i);
int					ft_istube(t_env *e, char *line);
int					add_room(t_env *e, char *line);
int					add_tube(t_env *e, char *line);

void				room_name_taken(char *line);
void				room_name_invalid(char *line);
void				invalid_line_command(char *line);
void				invalid_ants(char *line, int err);

t_room				*find_room(t_env *e, char *name);
t_room				*get_room(t_env *e, int room_id);
t_way				*get_way(t_env *e, int way_id);
void				init_ants(t_env *e);
void				set_start(t_env *e, char *room);
void				set_end(t_env *e, char *room);
void				ft_command(char *line, t_env *e);

void				ft_resolve(t_env *e, char *line, char *error);
int					ft_count_ways(t_env *e, t_way *ways);
void				set_distances_from_end(t_room *room, int distance);
void				set_ways(t_env *e);
void				next_room(t_env *e, int way[BUFF], t_room *room);
void				add_way2(t_env *e, int way[BUFF]);

void				instant_move(t_env *e);

void				algo_best(t_env *e);
int					are_crossing(t_way *way1, t_way *way2);
char				**matrix(t_env *e, t_way *iways[WAYS_AMOUNT]);
void				reset(int *istr, int size);

void				algo_simple(t_env *e);
void				clear_ways(t_env *e);
void				move(t_env *e);
void				try_walk(t_env *e);

void				fuck(t_env *e);

#endif
