#include <sh1.h>

char	**ft_tabdup(char **src)
{
	char	**dst;
	int		i;

	dst = (char**)malloc(sizeof(char*) * ft_tablen(src) + 1);
	i = 0;
	while (src[i] != NULL)
	{
		dst[i] = ft_strdup(src[i]);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
