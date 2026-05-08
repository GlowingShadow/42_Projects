/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 06:59:14 by REDACTED          #+#    #+#             */
/*   Updated: 2016/08/05 06:59:16 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libcorewar.h>

void	*ft_malloc(int nombre)
{
	void	*str;

	str = malloc(nombre);
	if (str == NULL)
	{
		ft_putendl("Error malloc");
		exit(MALLOCFAIL);
	}
	return (str);
}
