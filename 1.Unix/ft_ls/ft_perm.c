/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 14:14:41 by REDACTED          #+#    #+#             */
/*   Updated: 2015/01/27 04:00:51 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_perm2(char **perm, t_stat *buf)
{
	if ((*perm)[6] == 'x')
		(*perm)[6] = ((buf->st_mode & S_ISGID) ? 's' : 'x');
	if ((*perm)[6] == '-')
		(*perm)[6] = ((buf->st_mode & S_ISGID) ? 'S' : '-');
	(*perm)[7] = ((buf->st_mode & S_IROTH) ? 'r' : '-');
	(*perm)[8] = ((buf->st_mode & S_IWOTH) ? 'w' : '-');
	(*perm)[9] = ((buf->st_mode & S_IXOTH) ? 'x' : '-');
	if ((*perm)[9] == 'x')
		(*perm)[9] = ((buf->st_mode & S_ISVTX) ? 't' : 'x');
	if ((*perm)[9] == '-')
		(*perm)[9] = ((buf->st_mode & S_ISVTX) ? 'T' : '-');
	(*perm)[10] = 0;
}

char	*ft_perm(t_stat *buf)
{
	char		*perm;

	perm = (char*)malloc(sizeof(char*) * 10 + 1);
	perm[0] = ((S_ISDIR(buf->st_mode)) ? 'd' : '-');
	perm[0] = ((S_ISLNK(buf->st_mode) != 0) ? 'l' : perm[0]);
	perm[0] = ((S_ISBLK(buf->st_mode) != 0) ? 'b' : perm[0]);
	perm[0] = ((S_ISCHR(buf->st_mode) != 0) ? 'c' : perm[0]);
	perm[0] = ((buf->st_mode & S_IFIFO) ? 'p' : perm[0]);
	perm[0] = ((S_ISSOCK(buf->st_mode) != 0) ? 's' : perm[0]);
	perm[1] = ((buf->st_mode & S_IRUSR) ? 'r' : '-');
	perm[2] = ((buf->st_mode & S_IWUSR) ? 'w' : '-');
	perm[3] = ((buf->st_mode & S_IXUSR) ? 'x' : '-');
	if (perm[3] == 'x')
		perm[3] = ((buf->st_mode & S_ISUID) ? 's' : 'x');
	if (perm[3] == '-')
		perm[3] = ((buf->st_mode & S_ISUID) ? 'S' : '-');
	perm[4] = ((buf->st_mode & S_IRGRP) ? 'r' : '-');
	perm[5] = ((buf->st_mode & S_IWGRP) ? 'w' : '-');
	perm[6] = ((buf->st_mode & S_IXGRP) ? 'x' : '-');
	ft_perm2(&perm, buf);
	return (perm);
}
