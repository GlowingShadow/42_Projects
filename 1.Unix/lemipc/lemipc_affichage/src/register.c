/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 17:03:33 by REDACTED          #+#    #+#             */
/*   Updated: 2016/07/01 17:03:35 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemipc_aff.h>

static void		try_register(t_env *e, int newteam, t_int *ptr)
{
	ptr = e->teams;
	while (ptr != NULL)
	{
		if (newteam == ptr->n)
		{
			ptr->amount += 1;
			return ;
		}
		ptr = ptr->next;
	}
	if ((ptr = (t_int*)malloc(sizeof(t_int))) == NULL)
		ft_errexit("malloc failed", RED, MALLOC_FAILED);
	ptr->n = newteam;
	ptr->logo = NULL;
	ptr->color = NULL;
	ptr->next = NULL;
	if ((e->team_ind += 1) < 100)
	{
		ptr->logo = &(e->logos[e->team_ind % 10]);
		ptr->color = &(e->color[(e->team_ind % 10 + e->team_ind / 10) % 10]);
	}
	(e->teams != NULL) ? e->end_team->next = ptr : (void)ptr;
	(e->teams == NULL) ? e->teams = ptr : (void)ptr;
	e->end_team = ptr;
}

void			register_teams(t_env *e)
{
	int		x;
	t_int	*ptr;

	ptr = e->teams;
	while (ptr != NULL)
	{
		ptr->amount = 0;
		ptr = ptr->next;
	}
	x = 0;
	while (x < e->size - 1)
	{
		if (e->mapcpy[x] != VOID_CHAR)
			try_register(e, e->mapcpy[x], NULL);
		x++;
	}
}

t_int			*get_team(t_env *e, int team)
{
	t_int	*ptr;

	ptr = e->teams;
	while (ptr != NULL)
	{
		if (ptr->n == team)
			return (ptr);
		ptr = ptr->next;
	}
	ft_putnbr(team);
	ft_errexit(" team not registered", RED, TEAM_NOT_RGSTRD);
	return (NULL);
}
