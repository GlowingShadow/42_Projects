/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_msgq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 17:00:11 by REDACTED          #+#    #+#             */
/*   Updated: 2016/07/01 17:00:13 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

t_msg			send_msg(int msgq_id, long type, char *str)
{
	t_msg	msg;

	msg.type = type;
	ft_strncpy(msg.text, str, ft_strlen(str) + 1);
	if (msgsnd(msgq_id, (void*)&msg, sizeof(msg.text), IPC_NOWAIT) == -1)
	{
		printf("\ttype: %ld, \"%s\", msgq_id: %d\n", type, str, msgq_id);
	}
	return (msg);
}

static void		check(t_env *e)
{
	t_msg	reception;
	int		byte;
	int		msgq_id;

	while ((byte = msgrcv(e->msgq_id, &reception, \
		MSG_SIZE, MSG_GAME_OVER, IPC_NOWAIT | MSG_NOERROR)) > 0)
	{
		printf("\n\n\tGAME OVER !!!\n");
		grep_teams(e, NULL, CMAP);
	}
	if (byte < -1)
		perror("ERROR msgrcv GAMEOVER");
	while (LEADER == e->msgq_id && (byte = msgrcv(e->msgq_id, &reception, \
		MSG_SIZE, MSG_RKEY, IPC_NOWAIT | MSG_NOERROR)) > 0)
	{
		msgq_id = ft_atoi(reception.text);
		register_teammate(e, msgq_id);
		send_msg(msgq_id, MSG_GTPOS, ft_itoa(POS(4, 7)));
	}
	if (byte < -1)
		perror("ERROR msgrcv LEADER");
}

void			manage_messages(t_env *e)
{
	int		byte[3];
	t_msg	reception;

	check(e);
	while (LEADER == e->msgq_id && (byte[0] = msgrcv(e->msgq_id, &reception, \
		MSG_SIZE, MSG_DEAD, IPC_NOWAIT | MSG_NOERROR)) > 0)
		unregister_teammate(e->teammates, ft_atoi(reception.text));
	while (LEADER != e->msgq_id && (byte[1] = msgrcv(e->msgq_id, &reception, \
		MSG_SIZE, MSG_GTPOS, IPC_NOWAIT | MSG_NOERROR)) > 0)
	{
		e->target->pos = ft_atoi(reception.text);
		e->target->i = e->target->pos / WIDTH;
		e->target->j = e->target->pos % WIDTH;
	}
	while (LEADER != e->msgq_id && (byte[2] = msgrcv(e->msgq_id, &reception, \
		MSG_SIZE, MSG_HIDEPOS, IPC_NOWAIT | MSG_NOERROR)) > 0)
	{
		e->hidepos->pos = ft_atoi(reception.text);
		e->hidepos->i = e->hidepos->pos / WIDTH;
		e->hidepos->j = e->hidepos->pos % WIDTH;
	}
	if (byte[0] < -1 || byte[0] < -1 || byte[0] < -1)
		perror("ERROR msgrcv");
}

void			init_msgq(t_env *e)
{
	e->msgq_id = msgget(IPC_PRIVATE, IPC_CREAT | IPC_EXCL | 0666);
	printf("%d msg queue created:\t%d\n", e->team, e->msgq_id);
	op_sem(e, e->team_mem, LOCK);
	if (LEADER == -1)
	{
		LEADER = e->msgq_id;
		e->leader_msgq_id = e->msgq_id;
	}
	else if (LEADER != -1)
	{
		e->leader_msgq_id = LEADER;
		send_msg(LEADER, MSG_RKEY, ft_itoa(e->msgq_id));
		printf("\tsend --> %d\n", LEADER);
	}
	op_sem(e, e->team_mem, UNLOCK);
}
