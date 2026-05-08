#include <stdio.h>
#include <stdlib.h>

void	v()
{
		char buf[10];
			fgets(buf, 10, stdin);
				printf("%s\n", buf);
}

void	main(void)
{
		system("/bin/sh");
}
