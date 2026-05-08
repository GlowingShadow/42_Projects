/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 17:01:09 by REDACTED          #+#    #+#             */
/*   Updated: 2016/07/01 17:01:12 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

static void		send_target(t_env *e, t_target *target, int msg_type)
{
	t_int	*ptr;

	ptr = e->teammates;
	while (ptr != NULL)
	{
		if (ptr->alive == 1)
			send_msg(ptr->msgq_id, msg_type, ft_itoa(target->pos));
		ptr = ptr->next;
	}
}

static void		check_target(t_env *e, int x)
{
	int		i;
	int		j;

	i = x / WIDTH;
	j = x % WIDTH;
	if (e->target->pos == -1 || \
		ft_abs(e->i - i) + ft_abs(e->j - j) < \
		ft_abs(e->i - e->target->i) + ft_abs(e->j - e->target->j))
	{
		e->target->i = i;
		e->target->j = j;
		e->target->pos = x;
	}
}

static void		search_hide_pos(t_env *e)
{
	e->hidepos->pos = -1;
	e->hidepos->i = 0;
	e->hidepos->j = 0;
	if (e->i > WIDTH / 2)
		e->hidepos->i = WIDTH - 1;
	if (e->j > HEIGHT / 2)
		e->hidepos->j = HEIGHT - 1;
	e->hidepos->pos = POS(e->hidepos->i, e->hidepos->j);
	send_target(e, e->hidepos, MSG_HIDEPOS);
}

void			search_target(t_env *e)
{
	int		x;

	x = 0;
	e->target->pos = -1;
	e->target->i = -1;
	e->target->j = -1;
	op_sem(e, e->map_mem, LOCK);
	while (x < MAP_SIZE)
	{
		if (CMAP[x] != VOID_CHAR && CMAP[x] != e->team)
		{
			check_target(e, x);
		}
		x++;
	}
	op_sem(e, e->map_mem, UNLOCK);
	if (e->target->pos != -1)
		send_target(e, e->target, MSG_GTPOS);
	search_hide_pos(e);
}
