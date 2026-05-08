#include <stdio.h>

int	main(void)
{
	char buf[5] = "FLOW";
	buf[4] = 0;

	if (*(int*)(buf) == 1464814662)
	{
		printf("yes\n");
	}
	else
		printf("%d\n", (int)( *(int*)(buf)));

	int n = -2147483637;
	char *s = &n;
	printf("%02x %02x %02x %02x \n", s[0], s[1], s[2], s[3]);


	unsigned int u = 11;
	char *f = &n;
	printf("%02x %02x %02x %02x \n", f[0], f[1], f[2], f[3]);


	int q = -2147483637;
	int qq = q * 4;
	char *a = &qq;

	printf("%d\n", qq);
	printf("%02x %02x %02x %02x \n", a[0], a[1], a[2], a[3]);
	return 0;
}