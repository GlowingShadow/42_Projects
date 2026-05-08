#include <stdio.h>
#include <string.h>

void		print_memory(void *ptr, int n)
{
	char *s = (char*)ptr;
	
	printf("%p : \t", ptr);
	int	i = 0;
	while (i < n)
	{
		printf("%d ", (int)(s[i]));
		i++;
	}
	printf("\n");
}

void		p()
{
	char	buf[20];

	print_memory(buf, 20);
	strncpy(buf, "01234567890123456789", 20);
}

int		main(void)
{
	p();
	p();

	return (0);
}