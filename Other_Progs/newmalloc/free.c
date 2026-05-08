#include "malloc.h"

int		is_our_alloc(void *ptr)
{
	(void)ptr;
	return (1);
}
void	free(void *ptr)
{
	if (ptr == NULL)
		return ;
	if (is_our_alloc(ptr))
	{
		//((t_mal*)(ptr - sizeof(t_mal))->free = 1;
		//check le block ou le free a eu lieu et unmap si necessaire
	}
}
void	*realloc(void *ptr, size_t size)
{
	//if (!ptr)
	(void)ptr; (void)size;
		return (malloc);

}
/*int main(void)
	
{
	int i = 0;
	while (i < 100)
	{
		char *s = malloc(512);
		memset(s, 'd', i);
		i++;
		printf("%s\n", s);
		free(s);
	}
	//printf("%d, %zu", getpagesize(), sizeof(t_mal));
	write(1, "Fewfe", 3);
	return (0);
}*/