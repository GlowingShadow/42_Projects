/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 14:17:06 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/17 14:17:16 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <script.h>

int		ft_args_len(char **cmd)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (cmd[i] != NULL)
	{
		len += ft_strlen(cmd[i]) + 1;
		i++;
	}
	if (len >= BUFFER_CMD)
		return (-1);
	return (len);
}

void	ft_close_ptmx(t_env *e)
{
	e->term.c_lflag |= ~(ECHO | ICANON);
}
