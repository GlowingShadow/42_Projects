/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 15:12:32 by exam              #+#    #+#             */
/*   Updated: 2015/01/29 15:29:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check(int *s, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (s[i] > s[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int	tmp;

	while (ft_check(tab, size) == 0)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
	}
}
