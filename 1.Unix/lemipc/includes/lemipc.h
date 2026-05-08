/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 17:01:23 by REDACTED          #+#    #+#             */
/*   Updated: 2016/07/01 17:01:27 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_H
# define LEMIPC_H

# include <libft.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/sem.h>
# include <sys/shm.h>
# include <sys/msg.h>
# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# include <signal.h>
# include <errno.h>

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
# define MAP_TOO_BIG		12
# define RGSTR_EMPTY		13
# define RGSTR_TM_NF		14
# define MSGGET_FAILED		15

# define MAXWIDTH		80
# define MAXHEIGHT		50
# define WIDTH			20
# define HEIGHT			20
# define VOID_CHAR		-1

# define MSG_SIZE		10
# define MSG_RKEY		1
# define MSG_GTPOS		2
# define MSG_HIDEPOS	3
# define MSG_DEAD		4
# define MSG_GAME_OVER	5

# define REFRESH_TIME	500000
# define TIMEOUT		2000
# define UNLOCK			1
# define LOCK			-1
# define POS(i, j)		((i) * WIDTH + (j))
# define INFOS_ADD_SIZE	4
# define TEAM_ADD_SIZE	2
# define MAP_SIZE		e->map_mem->size - INFOS_ADD_SIZE
# define CMAP			e->map_mem->cdata
# define TEAM_LEFT		((int*)(e->map_mem->cdata + MAP_SIZE))[0]
# define PLAYER_LEFT	((int*)e->team_mem->data)[0]
# define LEADER			((int*)e->team_mem->data)[1]

extern int			g_team;

typedef struct		s_msg
{
	long			type;
	char			text[MSG_SIZE];
}					t_msg;

typedef struct		s_target
{
	int				i;
	int				j;
	int				pos;
}					t_target;

typedef struct		s_int
{
	int				alive;
	int				msgq_id;
	struct s_int	*next;
}					t_int;

typedef struct		s_smem
{
	key_t			key;
	int				sema_id;
	int				shm_id;
	void			*data;
	char			*cdata;
	int				size;
}					t_smem;

typedef struct		s_env
{
	t_smem			*map_mem;
	t_smem			*team_mem;
	int				msgq_id;
	int				team;
	int				leader_msgq_id;
	t_int			*teammates;
	int				i;
	int				j;
	int				pos;
	t_target		*target;
	t_target		*hidepos;
	int				ia;
}					t_env;

void				delete_msgq(t_int *teammates, int msgq_id);
void				delete_ipcs(int id, int size);
void				grep_teams(t_env *e, t_int *registre, char *data);
void				stop_game(int signum);
void				close_ipcs(t_smem *ptr, int msgq_id);
void				init_ipcs(t_env *e, char **infos, char *path, int id);
void				init_msgq(t_env *e);
t_msg				send_msg(int msgq_id, long type, char *str);
void				init_memory(t_env *e, t_smem *ptr, int player);
void				init_semaphore(t_env *e, t_smem *ptr, int player);
void				op_sem(t_env *e, t_smem *ptr, int operation);
void				clear_data(t_smem *ptr);

void				check_infos(char **infos);
void				new_player(t_env *e, char **infos);
int					get_player(t_env *e, int i, int j);
void				manage_messages(t_env *e);
void				register_teammate(t_env *e, int msgq_id);
void				unregister_teammate(t_int *teammates, int msgq_id);
void				check_leader(t_env *e);

void				check_dead(t_env *e);
void				move(t_env *e);
int					move_up(t_env *e);
int					move_down(t_env *e);
int					move_left(t_env *e);
int					move_right(t_env *e);
void				move_random(t_env *e);
void				search_target(t_env *e);
void				chase_target(t_env *e);
void				approch(t_env *e, int idist, int jdist);

#endif
