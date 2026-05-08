#include <libft.h>

typedef struct		s_env
{
	char **tab;
}					t_env;

void	read2(t_env *e)
{
	static int	i = 0;
	char		*line;
	char		*save;
	int			ind;

	ind = i;
	i++;
	if (get_next_line(0, &line) > 0 && ft_strlen(line) >= 0)
	{
		save = ft_strdup(line);
		read2(e);
	}
	else
	{
		e->tab = (char**)malloc(sizeof(char*) * (i + 1));
		e->tab[i] = NULL;
		return ;
	}

	ft_putnbr(i);ft_putchar(32);
	ft_putnbr(ind);ft_putchar('\t');ft_putchar('|');

	e->tab[ind] = save;
	ft_putendl(e->tab[ind]);
}

int		main(void)
{
	t_env	*e;

	e = (t_env*)malloc(sizeof(t_env));
	read2(e);
	ft_putchar(10);
	ft_puttab(e->tab);
	return (0);
}