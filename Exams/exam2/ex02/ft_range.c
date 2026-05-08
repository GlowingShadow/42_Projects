/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 14:55:00 by exam              #+#    #+#             */
/*   Updated: 2015/01/29 15:10:28 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int start, int end)
{
	int	i;
	int	j;
	int	*s;

	if (start <= end)
		i = end - start + 1;
	else
		i = start - end + 1;
	s = (int*)malloc(sizeof(int) * i);
	j = 0;
	if (start <= end)
	{
		while (start != end + 1)
		{
			s[j] = start;
			j++;
			start++;
		}
	}
	else
	{
		while (start != end - 1)
		{
			s[j] = start;
			j++;
			start--;
		}
	}
}
