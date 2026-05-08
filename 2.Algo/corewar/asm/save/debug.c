#include <asm.h>

void			ft_putnbrendl(int n)
{
	ft_putnbr(n);
	ft_putchar(10);
}

void	ft_dumptab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr("\033[33;34m[\033[33;0m");
		ft_putstr(tab[i]);
		ft_putstr("\033[33;34m]\033[33;0m");
		i++;
	}
	ft_putchar(10);
}

void		check_instructions(t_ins *ins)
{
	t_ins	*ptr;

	ptr = ins;
	while (ptr != NULL)
	{
		ft_putendl(ptr->instab[0]);
		ptr = ptr->next;
	}
}

void	print_instructions(t_env *e)
{
	t_ins	*ptr;
	t_label	*ptr2;

	ft_putstr("name:   \t");
	ft_putstr("\033[33;34m[\033[33;0m");
	ft_putstr(e->info[0]);
	ft_putstr("\033[33;34m]\033[33;0m\n");
	ft_putstr("comment:\t");
	ft_putstr("\033[33;34m[\033[33;0m");
	ft_putstr(e->info[1]);
	ft_putstr("\033[33;34m]\033[33;0m\n");
	ptr = e->ins;
	while (ptr != NULL)
	{
		ptr2 = ptr->labels;
		while (ptr2 != NULL)
		{
			ft_putstr(ptr2->name);
			(ptr2->next == NULL) ? ft_putstr("") : ft_putstr("\n");
			ptr2 = ptr2->next;
		}
		if (ptr->labels == NULL)
			ft_putstr("\t\t");
		else
			ft_putstr("    \t");
		ft_dumptab(ptr->instab);
		ptr = ptr->next;
	}
}

#include <stdio.h>
void	print_octets(t_env *e)
{
	t_ins	*ptr;
	t_int	*octets;

	ptr = e->ins;
	while (ptr != NULL)
	{
		// ft_dumptab(ptr->instab);
		octets = ptr->done;
		while (octets != NULL)
		{
			// ft_putnbr(octets->octet[0]);
			// ft_putchar('['); ft_putnbr(octets->valid); ft_putchar(']');
			// ft_putchar(32);
			printf("%02x ", octets->octet[0]);
			octets = octets->next;
		}
		// ft_putchar('\n');
		printf("\n");
		ptr = ptr->next;
	}
}

char	*bin (unsigned long int i)
{
    static char		buffer[1 + sizeof(unsigned long int) * 8] = { 0 };
    char			*p = buffer - 1 + sizeof(unsigned long int) * 8;

    do { *--p = '0' + (i & 1); i >>= 1; } while (i);
    return p;
}

void		test(void)
{
	unsigned short int	byte2[1];
	unsigned int		byte4[1];

	byte2[0] = -5;
	byte4[0] = -5;
	ft_putnbrendl(((unsigned char*)byte2)[0]);
	ft_putnbrendl(((unsigned char*)byte2)[1]);
	ft_putnbrendl(((unsigned char*)byte4)[0]);
	ft_putnbrendl(((unsigned char*)byte4)[1]);
	ft_putnbrendl(((unsigned char*)byte4)[2]);
	ft_putnbrendl(((unsigned char*)byte4)[3]);
	unsigned char a = 0b00000000;
	a = a | (3 << 6);
	a = a | (2 << 4);
	a = a | (1 << 2);
	printf ("%s\n",bin(a));
	// exit(OK);
	return ;
	ft_putchar(10);
	ft_putstr("T_REG                \t");ft_putnbrendl(T_REG);
	ft_putstr("T_DIR                \t");ft_putnbrendl(T_DIR);
	ft_putstr("T_IND                \t");ft_putnbrendl(T_IND);
	ft_putchar(10);
	ft_putstr("T_DIR | T_REG        \t");ft_putnbrendl(T_DIR | T_REG);
	ft_putstr("T_IND | T_REG        \t");ft_putnbrendl(T_IND | T_REG);
	ft_putstr("T_DIR | T_IND        \t");ft_putnbrendl(T_DIR | T_IND);
	ft_putchar(10);
	ft_putstr("T_REG | T_IND | T_DIR\t");ft_putnbrendl(T_REG | T_IND | T_DIR);
	ft_putchar(10);
	ft_putnbrendl(g_op_tab[0].param_amount);
	exit(0);
}
