/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_str_dup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 12:15:19 by REDACTED          #+#    #+#             */
/*   Updated: 2015/05/15 15:41:57 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_istr		ft_int_str_dup(int *str, int size)
{
	t_istr	newstr;
	
   newstr.istr = (int*)malloc(sizeof(int) * size);
   newstr.size = size;
   while (size >= 0)
   {
	   (newstr.istr)[size] = str[size];
	   size--;
   }
   return (newstr);
}
