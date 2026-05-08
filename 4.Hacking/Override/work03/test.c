#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	print_decimal(char *s)
{
	int		i = 0;
	while (s[i])
	{
		printf("%3d  ", s[i]);
		i++;
	}
	printf("\t%s\n", s);
}

void	compare(char *s1, char *s2)
{
	int	i = 0;
	while (s1[i] && s2[i])
	{
		printf("%3,d  ", s1[i] - s2[i]);
		i++;
	}
	printf("\n");
}

void	rot_xor(char *s, char n)
{

	char	*dst = strdup(s);
	int i = 0;
	while (s[i])
	{
		dst[i] = dst[i] ^ n;
		i++;
	}
	printf("%s\n", dst);
}

int		main(void)
{
	// test();
	char *s1 = "Congratulations!";
	char *s2 = "Q}|u`sfg~sf{}|a3";

	print_decimal(s1);
	print_decimal(s2);
	compare(s1, s2);
	rot_xor(s1, 18);
	rot_xor(s2, 18);
	return (0);
}