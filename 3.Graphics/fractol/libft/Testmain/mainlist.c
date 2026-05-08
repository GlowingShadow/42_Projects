/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 06:17:37 by REDACTED          #+#    #+#             */
/*   Updated: 2014/12/04 06:52:07 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(void)
{
	char	*str;
	t_list	*chaine;

	str = "cou";
	ft_putendl(str);
	chaine = ft_lstnew(str, ft_strlen(str) + 1);
	ft_putendl(chaine->content);
	ft_putnbr(chaine->content_size);
	return (0);
}
