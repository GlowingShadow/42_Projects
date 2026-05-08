/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:53:26 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:53:28 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <script.h>

int			ft_isdigit_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check(char *cp, int i)
{
	if (ft_isdigit(cp[i]) == 0 && cp[i] != 43 && cp[i] != 45)
		return (0);
	if (cp[i] == 43 || cp[i] == 45)
		if (cp[i + 1] == 43 || cp[i + 1] == 45)
			return (0);
	return (1);
}

int			ft_atoi2(char *str)
{
	char	*cp;
	int		i;
	int		n;

	n = 0;
	i = 0;
	cp = str;
	if (ft_check(cp, i) != 1)
		return (0);
	i++;
	while (ft_isdigit(cp[i]) == 1)
		i++;
	cp[i] = '\0';
	if (ft_isdigit(cp[0]) == 1)
		i = 0;
	else
		i = 1;
	while (i < ft_strlen(cp))
		n = 10 * n + (int)cp[i++] - 48;
	if (cp[0] == 45)
		n = -n;
	return (n);
}
