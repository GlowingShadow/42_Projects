/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 17:00:50 by REDACTED          #+#    #+#             */
/*   Updated: 2016/07/01 17:00:52 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc.h>

void			clear_data(t_smem *ptr)
{
	int		i;

	i = 0;
	while (i < ptr->size - INFOS_ADD_SIZE)
	{
		ptr->cdata[i] = VOID_CHAR;
		i++;
	}
	((int*)(ptr->data + ptr->size - 4))[0] = 0;
	((int*)(ptr->data + ptr->size - 4))[1] = -1;
}

void			check_infos(char **infos)
{
	char	*coo[2];

	if (!ft_isdigit_str(infos[0]))
		ft_errexit("Bad arguments.\n", RED, BAD_ARGS);
	if (infos[1])
	{
		if (!infos[2])
			ft_errexit("Bad arguments.\n", RED, BAD_ARGS);
		if (!ft_isdigit_str(infos[1]) || !ft_isdigit_str(infos[2]))
			ft_errexit("Bad arguments.\n", RED, BAD_ARGS);
		coo[0] = ft_itoa(HEIGHT - 1);
		coo[1] = ft_itoa(WIDTH - 1);
		if (ft_strlen(infos[1]) > ft_strlen(coo[0]) || \
			ft_strlen(infos[2]) > ft_strlen(coo[1]) || \
			ft_atoi(infos[1]) > HEIGHT || ft_atoi(infos[2]) > WIDTH)
		{
			free(coo[0]);
			free(coo[1]);
			ft_errexit("Bad arguments, coo too big.\n", RED, BAD_ARGS);
		}
	}
}

void			new_player(t_env *e, char **infos)
{
	if (infos[1] && infos[2])
	{
		e->i = ft_atoi(infos[1]);
		e->j = ft_atoi(infos[2]);
		if (infos[3] && infos[3][0] != 0)
			e->ia = infos[3][0] - 48;
	}
	op_sem(e, e->map_mem, LOCK);
	e->pos = POS(e->i, e->j);
	if (e->pos > (WIDTH * HEIGHT - 1) || CMAP[e->pos] != VOID_CHAR)
	{
		op_sem(e, e->map_mem, UNLOCK);
		ft_errexit("Can't place player.\n", RED, NO_PLACE);
	}
	op_sem(e, e->team_mem, UNLOCK);
	PLAYER_LEFT += 1;
	op_sem(e, e->team_mem, UNLOCK);
	CMAP[e->pos] = e->team;
	op_sem(e, e->map_mem, UNLOCK);
}
