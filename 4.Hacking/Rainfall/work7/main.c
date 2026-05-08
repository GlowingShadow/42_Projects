#include <...>

char secret[X];

void	m()
{
	int t = time(NULL);
	printf("%s - %d", secret, t);
}

int		main(int ac, char **av)
{
	char *s1 = malloc(8);
	char *s2 = malloc(8);
	char *s3 = malloc(8);
	char *s4 = malloc(8);

	strcpy(s2, av[1]);
	strcpy(s4, av[2]);

	FILE *f = fopen("/home/user/level8/.pass", "r");
	fgets(secret, X, f);
	puts("~~");

	return (0);
}
