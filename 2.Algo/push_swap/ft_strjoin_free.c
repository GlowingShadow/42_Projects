/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 01:12:40 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/12 07:05:24 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_free(char *s1, char *s2, int n)
{
	char	*dst;

	dst = ft_strjoin(s1, s2);
	if (n == 1 || n == 3)
	{
		ft_strclr(s1);
		free(s1);
	}
	if (n == 2 || n == 3)
	{
		ft_strclr(s2);
		free(s2);
	}
	return (dst);
}
