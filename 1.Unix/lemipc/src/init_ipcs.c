/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ipcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 17:00:02 by REDACTED          #+#    #+#             */
/*   Updated: 2016/07/01 17:00:04 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

int		g_team = 0;

void			init_semaphore(t_env *e, t_smem *ptr, int player)
{
	ptr->sema_id = semget(ptr->key, 1, IPC_CREAT | IPC_EXCL | 0666);
	if (ptr->sema_id == -1)
	{
		ptr->sema_id = semget(ptr->key, 1, IPC_CREAT | 0666);
		if (ptr->sema_id == -1)
			ft_errexit("semget failed", RED, SEMGET_FAILED);
	}
	else
	{
		if (semctl(ptr->sema_id, 0, SETVAL, 1) == -1)
			ft_errexit("semop failed", RED, SEMCTL_FAILED);
		if (player != 0)
		{
			op_sem(e, e->map_mem, UNLOCK);
			TEAM_LEFT += 1;
			op_sem(e, e->map_mem, LOCK);
		}
	}
}

void			init_memory(t_env *e, t_smem *ptr, int player)
{
	ptr->shm_id = shmget(ptr->key, ptr->size, 0644 | IPC_CREAT | IPC_EXCL);
	if (ptr->shm_id == -1)
	{
		ptr->shm_id = shmget(ptr->key, ptr->size, 0644 | IPC_CREAT);
		if (ptr->shm_id == -1)
			ft_errexit("shmget failed", RED, SEMGET_FAILED);
		if ((int)(ptr->data = shmat(ptr->shm_id, (void*)0, 0)) == -1)
			ft_errexit("shmat failed", RED, SHMAT_FAILED);
		ptr->cdata = (char*)ptr->data;
	}
	else
	{
		if ((int)(ptr->data = shmat(ptr->shm_id, (void*)0, 0)) == -1)
			ft_errexit("shmat failed", RED, SHMAT_FAILED);
		ptr->cdata = (char*)ptr->data;
		op_sem(e, ptr, LOCK);
		if (player == 0)
			clear_data(ptr);
		else
		{
			PLAYER_LEFT = 0;
			LEADER = -1;
		}
		op_sem(e, ptr, UNLOCK);
	}
}

void			init_ipcs(t_env *e, char **infos, char *path, int id)
{
	if ((e->map_mem->key = ftok(path, id)) == -1)
		ft_errexit("ftok failed", RED, FTOK_FAILED);
	init_semaphore(e, e->map_mem, 0);
	init_memory(e, e->map_mem, 0);
	check_infos(infos);
	e->team = ft_atoi(infos[0]);
	g_team = e->team;
	if ((e->team_mem->key = ftok(path, e->team)) == -1)
		ft_errexit("ftok failed", RED, FTOK_FAILED);
	init_semaphore(e, e->team_mem, 1);
	init_memory(e, e->team_mem, 1);
	new_player(e, infos);
}

void			close_ipcs(t_smem *ptr, int msgq_id)
{
	semctl(ptr->sema_id, 0, IPC_RMID, 0);
	shmctl(ptr->shm_id, IPC_RMID, ptr->data);
	if (msgq_id != -1)
		msgctl(msgq_id, IPC_RMID, 0);
}

void			op_sem(t_env *e, t_smem *ptr, int operation)
{
	struct sembuf	op;

	op.sem_num = 0;
	op.sem_op = operation;
	op.sem_flg = 0;
	if (semop(ptr->sema_id, &op, 1) == -1)
	{
		close_ipcs(e->team_mem, e->msgq_id);
		free(e->map_mem);
		free(e->team_mem);
		free(e);
		stop_game(0);
		ft_errexit("semop failed", RED, SEMOP_FAILED);
	}
}
