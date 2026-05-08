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

#include "libft.h"
#include "ft_ls.h"

void		ft_illegal_option(char c, int *j)
{
	if (c != 0)
	{
		ft_putstr("ls: illegal option -- ");
		ft_putchar(c);
		ft_putendl("\nusage: ls [-1Ralrt] [file ...]");
		exit(-1);
	}
	*j = 0;
}

char		*ft_synth2(char *arg, char **s)
{
	int		i;
	int		j;

	i = 1;
	if (arg[0] == '-' && arg[1] != '\0')
	{
		if (arg[1] == '-' && arg[2] == 0)
			return (ft_strjoin(*s, ""));
		while (arg[i] != 0 && (arg[i] == 108 || arg[i] == 116 || arg[i] == 82 \
					|| arg[i] == 97 || arg[i] == 114 || arg[i] == 49))
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

	s = (char*)malloc(sizeof(char) * 5 + 1);
	ft_strclr(s);
	s = ft_synth2(arg, &s);
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
