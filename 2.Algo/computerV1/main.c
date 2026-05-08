/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 00:39:39 by REDACTED          #+#    #+#             */
/*   Updated: 2015/04/04 07:13:52 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

char	*ft_complete_zero(char *src)
{
	char	*dst;
	int		i;

	i = ft_strlen(src);
	if (src[0] == '0' && src[1] == ' ' && src[2] == '=')
	{
		dst = ft_strjoin("0 * X^0", src + 1);
		free(src);
	}
	else if (src[i - 1] == '0' && src[i - 2] == ' ' && src[i - 3] == '=')
	{
		dst = ft_strjoin(src, " * X^0");
		free(src);
	}
	else
		return (src);
	return (dst);
}

char	*ft_add_space(char *src)
{
	int		i;
	int		j;
	char	*dst;

	dst = ft_strnew(ft_strlen(src) * 2);
	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		dst[j] = src[i];
		i++;
		j++;
		if (ft_isoperand(src[i]) == 1 && i != 0 && src[i - 1] != '=')
			dst[j++] = ' ';
		if (ft_isoperand(src[i - 1]) == 1 && i != 1 && src[i - 2] != '=')
			dst[j++] = ' ';
	}
	dst[j] = '\0';
	free(src);
	return (dst);
}

char	*ft_nospace(char *src)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	dst = ft_strnew(ft_strlen(src));
	while (src[i] != '\0')
	{
		while (src[i] == ' ' || src[i] == '\t')
			i++;
		dst[j] = src[i];
		if (dst[j] == '\0')
			break ;
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dst);
}

int		ft_error(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_color("Parsing error\n", RED);
		return (-1);
	}
	(void)av;
	return (0);
}

int		main(int ac, char **av)
{
	char	**tab;
	t_env	e;

	if (ft_error(ac, av) == -1)
		return (0);
	av[1] = ft_nospace(av[1]);
	av[1] = ft_add_space(av[1]);
	av[1] = ft_complete_zero(av[1]);
	av[1] = ft_complete_zero(av[1]);
	if ((tab = ft_cut(av[1])) == NULL)
	{
		ft_putstr_color("Parsing error\n", RED);
		return (0);
	}

	ft_stock_value(&e, tab);
	ft_display(e);
	return (0);
}
