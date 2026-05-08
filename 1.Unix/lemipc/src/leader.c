/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 17:00:18 by REDACTED          #+#    #+#             */
/*   Updated: 2016/07/01 17:00:22 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

void	check_leader(t_env *e)
{
	if (LEADER != e->leader_msgq_id)
	{
		if (LEADER == -1)
			LEADER = e->msgq_id;
		else
			send_msg(LEADER, MSG_RKEY, ft_itoa(e->msgq_id));
		e->leader_msgq_id = LEADER;
	}
}

void	register_teammate(t_env *e, int msgq_id)
{
	t_int	*new_teammate;

	if ((new_teammate = (t_int*)malloc(sizeof(t_int))) == NULL)
	{
		close_ipcs(e->team_mem, -1);
		close_ipcs(e->map_mem, -1);
		ft_errexit("malloc failed", RED, MALLOC_FAILED);
	}
	new_teammate->alive = 1;
	new_teammate->msgq_id = msgq_id;
	new_teammate->next = NULL;
	if (e->teammates == NULL)
		e->teammates = new_teammate;
	else
	{
		new_teammate->next = e->teammates;
		e->teammates = new_teammate;
	}
}

void	unregister_teammate(t_int *teammates, int msgq_id)
{
	t_int	*ptr;

	ptr = teammates;
	if (!ptr)
	{
		printf("No teammates registered\n");
		return ;
	}
	while (ptr != NULL && ptr->msgq_id != msgq_id)
		ptr = ptr->next;
	if (!ptr)
	{
		printf("%d : Player not registered as teammate\n", msgq_id);
		return ;
	}
	ptr->alive = 0;
}
