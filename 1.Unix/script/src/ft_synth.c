/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_synth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 03:25:42 by REDACTED          #+#    #+#             */
/*   Updated: 2015/02/13 02:16:27 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <script.h>

void		ft_illegal_option(t_env *e, char c, int *j)
{
	e->illegal_option = 0;
	if (c != 0)
	{
		ft_putstr("ft_script: illegal option -- ");
		ft_putchar(c);
		ft_putendl("\nusage: script [-akq] [-t time] [file [command ...]]");
		e->illegal_option = 1;
	}
	*j = 0;
}

char		*ft_synth2(t_env *e, char *arg, char **s)
{
	int		i;
	int		j;

	i = 1;
	if (arg[0] == '-' && arg[1] != '\0')
	{
		if (arg[1] == '-' && arg[2] == 0)
			return (*s);
		while (arg[i] != 0 && (arg[i] == 'a' || arg[i] == 'k' || arg[i] == 'q' \
					|| arg[i] == 't'))
			i++;
		ft_illegal_option(e, arg[i], &j);
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

int			ft_synth(t_env *e, char *arg, char *tmp)
{
	ft_bzero(tmp, MAX_OPTION + 1);
	tmp = ft_synth2(e, arg, &tmp);
	return (1);
}

int			ft_synth_option(t_env *e, int argc, char **argv, char *opt)
{
	int			i;
	char		tmp[MAX_OPTION + 1];

	i = 1;
	while (i < argc && ft_synth(e, argv[i], tmp) != 0 && tmp[0] != 0)
	{
		if (tmp[0] == 0)
		{
			i++;
			return (i);
		}
		ft_strcat(opt, tmp);
		i++;
	}
	return (i);
}
