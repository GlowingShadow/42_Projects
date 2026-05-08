/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 22:16:57 by REDACTED          #+#    #+#             */
/*   Updated: 2014/12/03 21:03:08 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

int		main(int argc, char **argv)
{	
	struct stat		*buf;
	struct passwd	*pw;
	struct group	*gr;
	time_t			t;

	argc = argc;
	argv = argv;
	buf = (struct stat*)malloc(sizeof(struct stat) * 1 + 1);
	if((lstat(argv[1], buf)) == -1)
		ft_putstr("fail");

	ft_putchar('\n');
	ft_putstr("number of links:\t");
	ft_putnbr(buf->st_nlink);
	ft_putchar('\n');

	ft_putstr("user id of owner:\t");
	ft_putnbr((buf->st_uid));
	pw = getpwuid(buf->st_uid);
	ft_putstr(" - ");
	ft_putstr(pw->pw_name);
	ft_putstr(" - ");
//	ft_putstr((getpwuid(buf->st_uid))->pw_name);
	ft_putchar('\n');

	ft_putstr("group id of owner:\t");
	ft_putnbr((buf->st_gid));
	gr = getgrgid(buf->st_gid);
	ft_putstr(" - ");
	ft_putstr(gr->gr_name);
	ft_putstr(" - ");
//	ft_putstr((getgrgid(buf->st_gid))->gr_name);
	ft_putchar('\n');

	ft_putstr("size:\t\t\t");
	ft_putnbr((buf->st_size));
	ft_putstr(" bytes");
	ft_putchar('\n');

	ft_putstr("Last modification:\t");
	ft_putnbr(buf->st_mtimespec.tv_sec);
	ft_putstr(" - ");
	ft_putstr(ctime(&buf->st_mtimespec.tv_sec));

	t = time(NULL);
	ft_putstr("\t\t\t");
	ft_putnbr(t);
	ft_putstr(" - ");
	ft_putendl(ctime(&t));

	ft_putstr("Droits:\t\t\t");
	ft_putchar((S_ISDIR(buf->st_mode)) ? 'd' : '-');
	ft_putchar((buf->st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((buf->st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((buf->st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((buf->st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((buf->st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((buf->st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((buf->st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((buf->st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((buf->st_mode & S_IXOTH) ? 'x' : '-');
	ft_putchar('\n');
	ft_putchar('\n');

	ft_putstr("Device (major,minor):\t");
	ft_putnbr(major(buf->st_rdev));
	ft_putchar(',');
	ft_putnbr(minor(buf->st_rdev));
	ft_putchar('\n');

	ft_putnbr(major(buf->st_dev));
	ft_putchar(',');
	ft_putnbr(minor(buf->st_dev));
	ft_putchar('\n');

	ft_putnbr(buf->st_rdev >> 24 & 0xff);
	ft_putchar(',');
	ft_putnbr(buf->st_rdev & 0xff);
	ft_putchar('\n');
	
	printf("\n\n");

	return (0);
}
