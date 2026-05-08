#include <lemipc.h>

static void			delete_semaphore(int key)
{
	int		sema_id;

	sema_id = semget(key, 1, IPC_CREAT | IPC_EXCL | 0666);
	if (sema_id == -1)
		sema_id = semget(key, 1, IPC_CREAT | 0666);
	if (sema_id == -1)
		ft_errexit("semget failed", RED, SEMGET_FAILED);
	semctl(sema_id, 0, IPC_RMID, 0);
}

static void			delete_memory(int key, int size)
{
	int		shm_id;

	shm_id = shmget(key, size, 0644 | IPC_CREAT | IPC_EXCL);
	if (shm_id == -1)
		shm_id = shmget(key, size, 0644 | IPC_CREAT);
	if (shm_id == -1)
		ft_errexit("shmget failed", RED, SHMGET_FAILED);
	shmctl(shm_id, IPC_RMID, 0);
}

static void			delete_msgq(int key)
{
	int			msgq_id;

	msgq_id = msgget(key, IPC_CREAT | IPC_EXCL | 0666);
	if (msgq_id == -1)
		msgq_id = msgget(key, IPC_CREAT | 0666);
	if (msgq_id == -1)
		ft_errexit("msgget failed", RED, MSGGET_FAILED);
	msgctl(msgq_id, IPC_RMID, 0);
}

static void			delete_ipcs(int id, int size)
{
	int			key;

	key = ftok(getenv("_"), id);
	if (key == -1)
		ft_errexit("ftok failed", RED, FTOK_FAILED);

	delete_semaphore(key);
	delete_memory(key, size);
	delete_msgq(key);
}

void				stop_game(int signum)
{
	delete_ipcs(1, sizeof(int) * TEAM_ADD_SIZE);
	delete_ipcs(0, WIDTH * HEIGHT + INFOS_ADD_SIZE);
	(void)signum;
	exit(OK);
}
