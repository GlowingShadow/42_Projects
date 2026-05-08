/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 17:09:34 by REDACTED          #+#    #+#             */
/*   Updated: 2015/02/13 02:11:21 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

int					ft_taballoc(DIR *rep)
{
	int				i;

	i = 0;
	while ((readdir(rep)) != NULL)
		i++;
	if (closedir(rep) == -1)
		perror("closedir");
	return (i);
}

DIR					*ft_opendir(char *dir)
{
	DIR				*rep;

	rep = opendir(dir);
	return (rep);
}

int					ft_lsa(char ***tab, char *dir)
{
	DIR				*rep;
	struct dirent	*s;
	int				i;

	if ((rep = ft_opendir(dir)) == NULL)
		return (-1);
	*tab = (char**)malloc(sizeof(char*) * ft_taballoc(rep) + 1);
	if ((rep = ft_opendir(dir)) == NULL)
		return (-1);
	i = 0;
	s = NULL;
	while ((s = readdir(rep)) != NULL)
	{
		(*tab)[i] = ft_strdup(s->d_name);
		i++;
	}
	if (closedir(rep) == -1)
		perror("closedir");
	(*tab)[i] = NULL;
	ft_tabsort(tab);
	return (0);
}
