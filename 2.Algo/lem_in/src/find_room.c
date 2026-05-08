/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 02:52:42 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/10 02:52:44 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_room	*find_room(t_env *e, char *room_name)
{
	t_room	*ptr;

	ptr = e->rooms;
	while (ptr != NULL)
	{
		if (ft_strcmp(ptr->name, room_name) == 0)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

t_room	*get_room(t_env *e, int room_id)
{
	t_room	*ptr;

	ptr = e->rooms;
	while (ptr != NULL)
	{
		if (ptr->id == room_id)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

t_way	*get_way(t_env *e, int way_id)
{
	t_way	*ptr;

	ptr = e->ways;
	while (ptr != NULL)
	{
		if (ptr->id == way_id)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}
