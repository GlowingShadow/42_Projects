/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 06:03:12 by REDACTED          #+#    #+#             */
/*   Updated: 2014/12/04 06:52:10 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*chaine;

	chaine = (t_list*)malloc(sizeof(t_list) * 1);
	if (content == NULL)
	{
		chaine->content = NULL;
		chaine->content_size = 0;
	}
	else
	{
		chaine->content = (void*)malloc(sizeof(content));
		ft_memcpy((chaine->content), content, content_size);
		chaine->content_size = content_size;
	}
	chaine->next = NULL;
	return (chaine);
}
