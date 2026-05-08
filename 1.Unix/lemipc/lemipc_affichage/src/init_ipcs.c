/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ipcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 17:03:14 by REDACTED          #+#    #+#             */
/*   Updated: 2016/07/01 17:03:16 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc_aff.h>

static void		init_semaphore(t_env *e)
{
	if ((e->sema1_id = semget(e->key, 1, IPC_CREAT | IPC_EXCL | 0666)) == -1)
	{
		printf("  Semaphore deja cree avec cette cle\n");
		if ((e->sema1_id = semget(e->key, 1, IPC_CREAT | 0666)) == -1)
			ft_errexit("semget failed", RED, SEMGET_FAILED);
		printf("semaphore:\t%d\n", e->sema1_id);
	}
	else
	{
		semctl(e->sema1_id, 0, IPC_RMID, 0);
		ft_errexit("lemipc not started", RED, NO_GAME);
	}
}

static void		init_memory(t_env *e)
{
	e->shm1_id = shmget(e->key, e->size, 0644 | IPC_CREAT | IPC_EXCL);
	if (e->shm1_id == -1)
	{
		printf("  Memoires deja cree avec cette cle\n");
		if ((e->shm1_id = shmget(e->key, e->size, 0644 | IPC_CREAT)) == -1)
			ft_errexit("shmget failed", RED, SEMGET_FAILED);
		if ((int)(e->data = shmat(e->shm1_id, (void*)0, 0)) == -1)
			ft_errexit("shmat failed", RED, 4);
		printf("memory:\t%d\t%p\n", e->shm1_id, e->data);
		e->cdata = (char*)e->data;
	}
	else
		ft_errexit("lemipc not started", RED, NO_GAME);
}

void			init_ipcs(t_env *e, char *path, int id)
{
	if ((e->key = ftok(path, id)) == -1)
		ft_errexit("ftok failed", RED, FTOK_FAILED);
	printf("key created:\t%d\n", (int)e->key);
	init_semaphore(e);
	init_memory(e);
}

void			op_sem(t_env *e, int operation)
{
	struct sembuf	op;

	op.sem_num = 0;
	op.sem_op = operation;
	op.sem_flg = 0;
	if (semop(e->sema1_id, &op, 1) == -1)
	{
		e->end_game = 1;
		printf("semop failed\n");
		shmdt(e->data);
		e->data = NULL;
	}
}
