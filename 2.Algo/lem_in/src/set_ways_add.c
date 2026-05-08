/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ways_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:55:12 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:55:14 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void		add_way2(t_env *e, int way[BUFF])
{
	t_way		*save;
	int			i;

	save = (t_way*)malloc(sizeof(t_way));
	save->istr = (int*)malloc(sizeof(int) * way[SIZE]);
	save->istr2 = (int*)malloc(sizeof(int) * e->rooms_amount);
	i = 0;
	while (i < e->rooms_amount)
		save->istr2[i++] = 0;
	i = 0;
	while (i < way[SIZE])
	{
		save->istr[i] = way[i];
		save->istr2[way[i]] = 1;
		i++;
	}
	save->id = way[ID];
	save->size = way[SIZE];
	save->next = NULL;
	if (e->ways == NULL)
		e->ways = save;
	else
		e->endways->next = save;
	e->endways = save;
}
