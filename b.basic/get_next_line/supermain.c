#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "get_next_line.h"
#include "libft.h"

#define PRINT 0
#define UNIT_TESTING 1
#define HELP 1
#define COLORS

#ifdef COLORS
# define C_NONE         "\033[0m"
# define C_BOLD         "\033[1;30m"
# define C_BLACK        "\033[30m"
# define C_RED          "\033[31m"
# define C_GREEN        "\033[32m"
# define C_BROWN        "\033[33m"
# define C_BLUE         "\033[34m"
# define C_MAGENTA      "\033[35m"
# define C_CYAN         "\033[36m"
# define C_GREY         "\033[37m"
#else
# define C_NONE         ""
# define C_BOLD         ""
# define C_BLACK        ""
# define C_RED          ""
# define C_GREEN        ""
# define C_BROWN        ""
# define C_BLUE         ""
# define C_MAGENTA      ""
# define C_CYAN         ""
# define C_GREY         ""
#endif



int     suicide_child(int *pid)
{
	int     status;

	*pid = fork();
	if (*pid == -1)
		return (-1);
	else if (*pid == 0)
		return (1); // RIP
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (1);
		else
			return (0);
	}
}

int     diff(char *f1, char *f2)
{
	char    *cmd;
	if (!(cmd = malloc(64)))
		return (0);
	cmd = strcat(cmd, "diff ");
	cmd = strcat(cmd, f1);
	cmd = strcat(cmd, " ");
	cmd = strcat(cmd, f2);
	printf(C_CYAN"=> Diff (%s) (%s)"C_RED"\n", f1, f2);
	system(cmd);
	printf(C_NONE);
	return (1);
}

char    *rw_name(char *name, int type)
{
	char    *ret = strdup(name);
	if (type == 'r')
		ret[0] = 'r';
	else
		ret[0] = 'w';
	return (ret);
}

int g_buffsize = BUFF_SIZE;
int     change_buffsize(char *buffsize)
{
	char    *cmd;

	g_buffsize = atoi(buffsize);
	if(!(cmd = malloc(64)))
		return (0);
	strcat(cmd, "echo \"\n");
	strcat(cmd, "#undef BUFF_SIZE\n#define BUFF_SIZE ");
	strcat(cmd, buffsize);
	strcat(cmd, "\" >> get_next_line.h");
	system(cmd);
	return (1);
}

int     diff_test(int ac, char **av)
{
	char    **filename = NULL;
	int     fd[ac];
	int     fd_w[ac];
	char    *line[ac];
	int     lineid[ac];
	int     flag = 1;
	int     i = -1;

	if (!(filename = malloc(sizeof(char*) * ac)))
		return (0);;
	if (ac < 2)
		fd[0] = 0;
	else
		while (i++ < ac - 1 && !(lineid[i-1] = 0))
		{
			filename[i-1] = av[i];
			fd[i-1] = open(rw_name(filename[i-1], 'r'), O_RDONLY);
			fd_w[i-1] = open(rw_name(filename[i-1], 'w'), O_WRONLY | O_CREAT | O_TRUNC, 0666);
		}
	while (flag)
	{
		flag = 0;
		i = -1;
		while (i++ < ac - 2)
			if (get_next_line(fd[i], &line[i]) > 0 && (flag = 1))
			{
				if (PRINT)
					printf("[%d:%s:%d] %s%s\n"C_NONE, fd[i], filename[i], ++lineid[i], i % 2 ? C_GREEN : C_CYAN, line[i]);
				if (UNIT_TESTING)
				{
					write(fd_w[i], line[i], strlen(line[i]));
					write(fd_w[i], "\n", 1);
				}           
			}
		if (PRINT) printf(C_BROWN"==============================\n"C_NONE);
	}
	if (UNIT_TESTING)
	{
		printf(C_BROWN"============ DIFF TEST (%d) =============\n"C_NONE, g_buffsize);
		i = -1;
		while (i++ < ac - 2)
		{
			diff(rw_name(filename[i], 'r'), rw_name(filename[i], 'w'));
			close(fd[i]);
			close(fd_w[i]);
		}
	}   
	return (0);
}

int     null_test()
{
	int pid;
	int ret;

	if (!UNIT_TESTING)
		return (-1);
	printf(C_BROWN"=============== NULL TEST ===============\n"C_NONE);
	if (suicide_child(&pid))
	{
		ret = get_next_line(open("r_nulltest", O_RDONLY), NULL);
		if (!pid)
			exit(0);
		if (ret == -1)
		{
			printf(C_GREEN"Passed (no segfault)\n"C_NONE);
			return (1);
		}
		else
		{
			printf(C_RED"Failed (no segfault but ret=%d)\n"C_NONE, ret);
			return (0);
		}
	}
	else
	{
		printf(C_RED"Failed (seg fault catched)\n"C_NONE);
		return (0);
	}
}

int     badfd_test()
{
	char    *line;
	int pid;
	int ret;

	if (!UNIT_TESTING)
		return (-1);
	printf(C_BROWN"============== BAD FD TEST ==============\n"C_NONE);
	if (suicide_child(&pid))
	{
		ret = get_next_line(-272, &line);
		if (!pid)
			exit(0);
		if (ret == -1)
		{
			printf(C_GREEN"Passed (no segfault)\n"C_NONE);
			return (1);
		}
		else
		{
			printf(C_RED"Failed (no segfault but ret=%d)\n"C_NONE, ret);
			return (0);
		}
	}
	else
	{
		printf(C_RED"Failed (seg fault catched)\n"C_NONE);
		return (0);
	}
}

int     badfdflag_test()
{
	char    *line;
	int pid;
	int ret;

	if (!UNIT_TESTING)
		return (-1);
	printf(C_BROWN"============ BAD FD FLAG TEST ===========\n"C_NONE);
	if (suicide_child(&pid))
	{
		ret = get_next_line(open("r_badfdflagtest", O_WRONLY), &line);
		if (!pid)
			exit(0);
		if (ret == -1)
		{
			printf(C_GREEN"Passed (no segfault)\n"C_NONE);
			return (1);
		}
		else
		{
			printf(C_RED"Failed (no segfault but ret=%d)\n"C_NONE, ret);
			return (0);
		}
	}
	else
	{
		printf(C_RED"Failed (seg fault catched)\n"C_NONE);
		return (0);
	}
}

int     multi_diff_test(int ac, char **av, int hmlvl)
{
	char    *spf = NULL;
	int bs_lst[] = {-1, 0, 1, 8, 32, 128, 1024, 4096, 65536, 262144};
	int hm_lst[] = { 1, 1, 0, 0,  0,   0,    0,    0,     2,      2, -1};   
	int i = 0;

	if (!(spf = malloc(16)))
		return (-1);
	(void)ac;
	(void)av;
	while (hm_lst[i] != -1)
	{
		if (hmlvl >= hm_lst[i])
		{
			sprintf(spf, "%d", bs_lst[i]);
			change_buffsize(spf);
			diff_test(ac, av);
		}
		++i;
	}   
	return (1);
}

int     stdin_test()
{
	char    *line;

	while (get_next_line(0, &line) > 0)
		printf(C_CYAN"stdin: "C_NONE"%s\n", line);
	return (1);
}

int     main(int ac, char **av)
{
	if (HELP)
	{
		printf(C_BOLD"================= HELP ==================\n");
		printf("- ./a.out filename: will run the program with your default BUFF_SIZE, and do the diff, null, and badfd testes\n");
		printf("- ./a.out filename -set x: will set the BUFF_SIZE in your get_next_line.h to the desired value (it will fucked up your .h, clean it from times to times), and do diff, null, and badfd\n");
		printf("- ./a.out filename -multi x: will try with many (depending on the HardMode level) different BUFF_SIZE, if x=0, only the easiest case will be tested, x=1 will add -1 and 0, and x=2 will add 2^16 and 2^18 (it will fucked up your .h, clean it from times to times), and do diff, null, and badfd\n");
		printf("- ./a.out: will get_next_line() on stdin\n");
		printf("=========================================\n\n"C_NONE);
	}
	if (ac < 2)
		stdin_test();
	else
	{
		if (!strcmp(av[ac-2], "-multi") && (ac -= 2))
			multi_diff_test(ac, av, atoi(av[ac+1]));
		else if (!strcmp(av[ac-2], "-set") && (ac -= 2))
		{
			change_buffsize(av[ac+1]);
			diff_test(ac, av);
		}
		else
		{
			diff_test(ac, av);
		}
	}
	null_test();
	badfd_test();
	badfdflag_test();
	return (0);
}
