#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void	n()
{
	system("/bin/cat /home/user/level7/.pass");
}

void	m(void)
{
	printf("Nope\n");
}

int		main(int ac, char **av)
{
	char *s1 = malloc(64);

	void (**p)(void);
	p = malloc(4);
	*p = &m;

	// printf("%p\n", p);
	// printf("%p\n", *p);
	// printf("%p\n", m);

	strcpy(s1, av[1]);
	(*p)();
	return (0);
}