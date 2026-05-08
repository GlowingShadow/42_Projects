/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 09:15:58 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/16 17:58:19 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_read_op(char *str)
{
	char	*dst;
	int		i;

	i = 0;
	dst = ft_strnew(ft_strlen(str) * 4 + 1);
	while (str[i] != '\0')
	{
		str[i] == '0' ? dst = ft_strcat(dst, "sa ") : (void)dst;
		str[i] == '1' ? dst = ft_strcat(dst, "sb ") : (void)dst;
		str[i] == '2' ? dst = ft_strcat(dst, "ra ") : (void)dst;
		str[i] == '3' ? dst = ft_strcat(dst, "rb ") : (void)dst;
		str[i] == '4' ? dst = ft_strcat(dst, "pa ") : (void)dst;
		str[i] == '5' ? dst = ft_strcat(dst, "pb ") : (void)dst;
		str[i] == '6' ? dst = ft_strcat(dst, "rra ") : (void)dst;
		str[i] == '7' ? dst = ft_strcat(dst, "rrb ") : (void)dst;
		str[i] == '8' ? dst = ft_strcat(dst, "ss ") : (void)dst;
		str[i] == '9' ? dst = ft_strcat(dst, "rr ") : (void)dst;
		str[i] == ':' ? dst = ft_strcat(dst, "rrr ") : (void)dst;
		i++;
	}
//ft_putstr("\t");
//ft_putstr(dst);
	return (dst);
}
