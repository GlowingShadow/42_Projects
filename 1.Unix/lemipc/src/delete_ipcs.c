/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_ipcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 16:59:42 by REDACTED          #+#    #+#             */
/*   Updated: 2016/07/01 16:59:45 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

static void		delete_semaphore(int key)
{
	int		sema_id;

	sema_id = semget(key, 1, IPC_CREAT | IPC_EXCL | 0666);
	if (sema_id == -1)
		sema_id = semget(key, 1, IPC_CREAT | 0666);
	if (sema_id == -1)
		ft_errexit("semget failed", RED, SEMGET_FAILED);
	semctl(sema_id, 0, IPC_RMID, 0);
}

static void		delete_memory(int key, int size)
{
	int		shm_id;
	char	*data;

	shm_id = shmget(key, size, 0644 | IPC_CREAT | IPC_EXCL);
	if (shm_id == -1)
		shm_id = shmget(key, size, 0644 | IPC_CREAT);
	if (shm_id == -1)
		ft_errexit("shmget failed", RED, SHMGET_FAILED);
	if ((int)(data = (char*)shmat(shm_id, (void*)0, 0)) == -1)
		ft_errexit("shmat failed", RED, SHMAT_FAILED);
	shmctl(shm_id, IPC_RMID, 0);
}

void			delete_msgq(t_int *teammates, int msgq_id)
{
	msgctl(msgq_id, IPC_RMID, 0);
	while (teammates != NULL)
	{
		if (teammates->alive == 1)
			msgctl(teammates->msgq_id, IPC_RMID, 0);
		teammates = teammates->next;
	}
}

void			delete_ipcs(int id, int size)
{
	int			key;

	key = ftok(getenv("_"), id);
	if (key == -1)
		ft_errexit("ftok failed", RED, FTOK_FAILED);
	delete_semaphore(key);
	delete_memory(key, size);
}

void			stop_game(int signum)
{
	delete_ipcs(g_team, sizeof(int) * TEAM_ADD_SIZE);
	delete_ipcs(0, WIDTH * HEIGHT + INFOS_ADD_SIZE);
	(void)signum;
}
