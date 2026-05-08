/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping_amazing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:48:18 by abou              #+#    #+#             */
/*   Updated: 2015/01/30 15:30:49 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"
#include "libft.h"
#include "get_next_line.h"
# include <mlx.h>

int		ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_strswap(char **s1, char **s2)
{
	char *tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
	tmp = NULL;
}

void	ft_swap(char **pile) //sa || sb
{
	ft_strswap(&(pile[0]), &(pile[1]));
}

void	ft_sswap(char **pile1, char **pile2) // ss
{
	ft_swap(pile1);
	ft_swap(pile2);
}

void	ft_ablation(char **src)
{
	int	i;

	i = 0;
	while (src[i + 1] != NULL)
	{
		src[i] = src[i + 1];
		i++;
	}
	src[i] = NULL;
}

void	ft_rot(char **pile) // ra || rb
{
	int	i;

	i = 0;
	while (pile[i + 1])
	{
		ft_strswap(&(pile[i]), &(pile[i + 1]));
		i++;
	}
}

void	ft_rrot(char **pile) // rra || rrb
{
	int	i;

	i = ft_tablen(pile) - 1;
	while (i >= 1)
	{
		ft_strswap(&(pile[i]), &(pile[i - 1]));
		i--;
	}
}

int		ft_push(char **src, char **dst) // pa || pb
{
	int	i;

	if (src[0] == NULL)
		return (0);
	i = ft_tablen(dst);
	dst[i + 1] = NULL;
	dst[i] = src[0];
	ft_rrot(dst);
	ft_ablation(src);
	return (0);
}

void	ft_rot_all(char **pile1, char **pile2) // rr
{
	ft_rot(pile1);
	ft_rot(pile2);
}

void	ft_rrot_all(char **pile1, char **pile2) // rrr
{
	ft_rrot(pile1);
	ft_rrot(pile2);
}

void	ft_puttab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	ft_display(char **pile1, char **pile2)
{
	ft_putstr("\tA: ");
	ft_puttab(pile1);
	ft_putstr("\tB: ");
	ft_puttab(pile2);
	ft_putchar('\n');
}

int		ft_key_hook(int	keycode, t_env *e)
{
	static int	count;
	static char	*cmd;

	count++;
	if (count == 1)
		cmd = ft_strnew(1);

	if (keycode == 65307)
			exit(0);

	if (keycode == 49)
	{
		ft_swap(e->pile1);
		cmd = ft_strjoin(cmd," sa");
		system("clear");
		ft_putnbr(count);
		ft_putstr(": ");
		ft_putendl(cmd);
		ft_display(e->pile1, e->pile2);
	}
	if (keycode == 50)
	{
		ft_swap(e->pile2);
		cmd = ft_strjoin(cmd," sb");
		system("clear");
		ft_putnbr(count);
		ft_putstr(": ");
		ft_putendl(cmd);
		ft_display(e->pile1, e->pile2);
	}
	if (keycode == 51)
	{
		ft_sswap(e->pile1, e->pile2);
		cmd = ft_strjoin(cmd," ss");
		system("clear");
		ft_putnbr(count);
		ft_putstr(": ");
		ft_putendl(cmd);
		ft_display(e->pile1, e->pile2);
	}
	if (keycode == 65362)
	{
		ft_push(e->pile2, e->pile1);
		cmd = ft_strjoin(cmd," pa");
		system("clear");
		ft_putnbr(count);
		ft_putstr(": ");
		ft_putendl(cmd);
		ft_display(e->pile1, e->pile2);
	}
	if (keycode == 65364)
	{
		ft_push(e->pile1, e->pile2);
		cmd = ft_strjoin(cmd," pb");
		system("clear");
		ft_putnbr(count);
		ft_putstr(": ");
		ft_putendl(cmd);
		ft_display(e->pile1, e->pile2);
	}
	if (keycode == 65361)
	{
		ft_rot(e->pile1);
		cmd = ft_strjoin(cmd," ra");
		system("clear");
		ft_putnbr(count);
		ft_putstr(": ");
		ft_putendl(cmd);
		ft_display(e->pile1, e->pile2);
	}
	if (keycode == 113)
	{
		ft_rot(e->pile2);
		cmd = ft_strjoin(cmd," rb");
		system("clear");
		ft_putnbr(count);
		ft_putstr(": ");
		ft_putendl(cmd);
		ft_display(e->pile1, e->pile2);
	}
	if (keycode == 97)
	{
		ft_rot_all(e->pile1, e->pile2);
		cmd = ft_strjoin(cmd," rr");
		system("clear");
		ft_putnbr(count);
		ft_putstr(": ");
		ft_putendl(cmd);
		ft_display(e->pile1, e->pile2);
	}
	if (keycode == 65363)
	{
		ft_rrot(e->pile1);
		cmd = ft_strjoin(cmd," rra");
		system("clear");
		ft_putnbr(count);
		ft_putstr(": ");
		ft_putendl(cmd);
		ft_display(e->pile1, e->pile2);
	}
	if (keycode == 119)
	{
		ft_rrot(e->pile2);
		cmd = ft_strjoin(cmd," rrb");
		system("clear");
		ft_putnbr(count);
		ft_putstr(": ");
		ft_putendl(cmd);
		ft_display(e->pile1, e->pile2);
	}
	if (keycode == 115)
	{
		ft_rrot_all(e->pile1, e->pile2);
		cmd = ft_strjoin(cmd," rrr");
		system("clear");
		ft_putnbr(count);
		ft_putstr(": ");
		ft_putendl(cmd);
		ft_display(e->pile1, e->pile2);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	ac = ac;
	e.pile1 = av + 1;
	e.pile2 = (char**)malloc(sizeof(char*) * ft_tablen(av));
	e.pile2[0] = NULL;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 200, 200, "d");

	mlx_key_hook(e.win, ft_key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
