/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_synth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 03:25:42 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/17 18:34:36 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_isnumber(char *arg)
{
	int		i;

	i = 1;
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void		ft_illegal_option(char c, int *j)
{
	if (c != 0)
	{
		ft_putstr("push_swap: illegal option -- ");
		ft_putchar(c);
		ft_putendl("\nusage: push_swap [-cva] [numbers ...]");
		exit(-1);
	}
	*j = 0;
}

char		*ft_synth2(char *arg, char **s, int i)
{
	int		j;

	if (arg[0] == '-' && arg[1] != '\0')
	{
		if (ft_isnumber(arg) == 1)
			return (NULL);
		if (arg[1] == '-' && arg[2] == 0)
			return (ft_strjoin(*s, ""));
		while (arg[i] != 0 && (arg[i] == 99 || arg[i] == 118 || arg[i] == 97))
			i++;
		ft_illegal_option(arg[i], &j);
		if (arg[i] == 0)
		{
			i = 1;
			while (arg[i] != 0)
			{
				if (ft_strchr(*s, arg[i]) == NULL)
					(*s)[j++] = arg[i];
				i++;
			}
			return (*s);
		}
	}
	return (NULL);
}

char		*ft_synth(char *arg)
{
	char	*s;

	s = ft_strnew(2);
	s = ft_synth2(arg, &s, 1);
	return (s);
}

int			ft_synth_option(int argc, char **argv, char **opt)
{
	int			i;
	char		*tmp;
	char		*ptr;

	i = 1;
	while (i < argc && (tmp = ft_synth(argv[i])) != NULL)
	{
		if (tmp[0] == 0)
		{
			i++;
			return (i);
		}
		ptr = *opt;
		*opt = ft_strjoin(*opt, tmp);
		free(tmp);
		free(ptr);
		i++;
	}
	return (i);
}
