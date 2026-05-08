/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:56:13 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:56:15 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static t_ant	*new_ant(t_env *e, int id)
{
	t_ant	*newborn;

	if ((newborn = (t_ant*)malloc(sizeof(t_ant))) == NULL)
	{
		ft_putendl("MALLOC SALLE BALTRINGUE");
		exit(0);
	}
	newborn->id = id;
	newborn->my_way = NULL;
	newborn->rooms_taken = 0;
	newborn->room_pos = e->start_room;
	newborn->next = NULL;
	return (newborn);
}

void			init_ants(t_env *e)
{
	int		id;
	t_ant	*ptr;

	e->ants = new_ant(e, 1);
	ptr = e->ants;
	id = 2;
	while (id <= e->ants_amount)
	{
		ptr->next = new_ant(e, id);
		ptr = ptr->next;
		id++;
	}
}
