#include "malloc.h"
#include <stdio.h>
int main()
{ 
	int i; 
	char *addr[1024]; 

	i = 0;

	while (i < 1024) 
	{ 
		addr[i] = (char*)ft_malloc(1024);
		//printf("%p\n", addr[i]);
		addr[i][0] = 'a'; 
		i++; 
	}
		printf("%d", i);
	return (0); 
}
