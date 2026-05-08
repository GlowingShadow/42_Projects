#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void toto()
{
	printf("%s\n", "pkok");
}

int main (int ac, char **av, char **env)
{
	{
		printf(".\n");
		// int pid;
		
		// signal(SIGINT, SIG_DFL);
		// // pid = fork();
		// // if (pid == 0)
		// // {
		// // 	execve("/bin/ls", av, NULL);
		// // 	exit(0);
		// // }
		// // wait(0);
		// // while (1);
		// read(1, 0 , 1);
		// // for (int i = 0; env[i]; ++i)
		// // {
		// // printf("%s\n", env[i]);
		// // }
	}
	{
		(void)ac; (void)env; (void)av;
		pid_t	forker;

		forker = fork();
		if (forker > 0)
		{
			printf("Father\n");
			wait(0);
		}
		if (forker == 0)
		{
			printf("--\n");
		}
	}
}