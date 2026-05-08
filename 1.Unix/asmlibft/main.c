/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 12:41:05 by REDACTED          #+#    #+#             */
/*   Updated: 2015/05/15 15:52:20 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfts.h"

int		main(int ac, char **av)
{
	(void)av;
	(void)ac;

	// TEST FT_ISDIGIT
	ft_putnbr(ft_isdigit('0'));	ft_putnbr(ft_isdigit('1'));
	ft_putnbr(ft_isdigit('2'));	ft_putnbr(ft_isdigit('3'));
	ft_putnbr(ft_isdigit('4'));	ft_putnbr(ft_isdigit('5'));
	ft_putnbr(ft_isdigit('6'));	ft_putnbr(ft_isdigit('7'));
	ft_putnbr(ft_isdigit('8'));	ft_putnbr(ft_isdigit('9'));
	ft_putchar('\n');
	ft_putnbr(ft_isdigit(47));	ft_putnbr(ft_isdigit(58));
	ft_putendl("\n-----------ft_isdigit\n");	
	
	// TEST FT_ISALPHA
	ft_putnbr(ft_isalpha('a'));	ft_putnbr(ft_isalpha('z'));
	ft_putnbr(ft_isalpha('A'));	ft_putnbr(ft_isalpha('Z'));
	ft_putchar('\n');
	ft_putnbr(ft_isalpha(64));	ft_putnbr(ft_isalpha(91));
	ft_putnbr(ft_isalpha(96));	ft_putnbr(ft_isalpha(123));
	ft_putendl("\n-----------ft_isalpha\n");	
	
	// TEST FT_ISALNUM
	ft_putnbr(ft_isalnum('0')); ft_putnbr(ft_isalnum('1'));
	ft_putnbr(ft_isalnum('2')); ft_putnbr(ft_isalnum('3'));
	ft_putnbr(ft_isalnum('4')); ft_putnbr(ft_isalnum('5'));
	ft_putnbr(ft_isalnum('6'));	ft_putnbr(ft_isalnum('7'));
	ft_putnbr(ft_isalnum('8'));	ft_putnbr(ft_isalnum('9'));
	ft_putnbr(ft_isalnum('a'));	ft_putnbr(ft_isalnum('z'));
	ft_putnbr(ft_isalnum('a'));	ft_putnbr(ft_isalnum('z'));
	ft_putchar('\n');
	ft_putnbr(ft_isalnum(58));	ft_putnbr(ft_isalnum(47));
	ft_putnbr(ft_isalnum(64));	ft_putnbr(ft_isalnum(91));
	ft_putnbr(ft_isalnum(96));	ft_putnbr(ft_isalnum(123));
	ft_putendl("\n-----------ft_isalnum\n");

	// TEST FT_ISPRINT
	ft_putnbr(ft_isprint(32)); ft_putnbr(ft_isprint(33));
	ft_putchar('\n');
	ft_putnbr(ft_isprint(255)); ft_putnbr(ft_isprint(254));
	ft_putnbr(ft_isprint(31)); ft_putnbr(ft_isprint(0));
	ft_putnbr(ft_isprint(256)); ft_putnbr(ft_isprint(257));
	ft_putendl("\n------------ft_isprint\n");

	// TEST FT_ISASCII
	ft_putnbr(ft_isascii(127)); ft_putnbr(ft_isascii(2));
	ft_putnbr(ft_isascii(32)); ft_putnbr(ft_isascii(33));
	ft_putnbr(ft_isascii(95)); ft_putnbr(ft_isascii(48));
	ft_putchar('\n');
	ft_putnbr(ft_isascii(-1)); ft_putnbr(ft_isascii(128));
	ft_putendl("\n-----------ft_isascii\n");
	
	// FT_TOLOWER
	ft_putchar(ft_tolower('A'));ft_putchar(ft_tolower('Z'));
	ft_putchar(ft_tolower('B'));ft_putchar(ft_tolower('Y'));
	ft_putchar('\n');
	ft_putchar(ft_tolower('@'));ft_putchar(ft_tolower('['));
	ft_putendl("\n-----------ft_tolower\n");
	
	// FT_TOLOWER
	ft_putchar(ft_toupper('a'));ft_putchar(ft_toupper('z'));
	ft_putchar(ft_toupper('b'));ft_putchar(ft_toupper('y'));
	ft_putchar('\n');
	ft_putchar(ft_toupper('`'));ft_putchar(ft_toupper('{'));
	ft_putendl("\n-----------ft_toupper\n");
	
	// FT_STRLEN
	ft_putnbr(ft_strlen("Coucou!"));
	ft_putendl("\n-----------ft_strlen\n");

	// FT_PUTS
	ft_putnbr(ft_puts(NULL));
	ft_putchar('\n');
	ft_putnbr(ft_puts("coucou"));
	ft_putendl("\n-------------ft_puts\n");

	// FT_BZERO
	char *str;

	str = strdup("Coucoulesgens");
	ft_bzero(str + 6, 3);
	ft_putstr(str); ft_putchar(32); ft_putstr(str + 9);
	ft_bzero(str + 6, 7);
	ft_putendl("\n------------ft_bzero\n");

	// FT_STRCAT
	ft_putstr(ft_strcat(str, "lesgens"));
	ft_putendl("\n------------ft_strcat\n");

	// FT_MEMSET
	ft_putstr(ft_memset(str, '.', 6));
	ft_putendl("\n------------ft_memset\n");

	// FT_MEMCPY
	ft_putstr(ft_memcpy(str, "Coucoulesgens", 6));
	ft_putendl("\n------------ft_memcpy\n");

	// FT_STRDUP
	ft_putstr(str); ft_putchar('\n');
	ft_putstr(ft_strdup(str));
	ft_putendl("\n------------ft_strdup\n");

	// FT_CAT
	ft_putendl("---------------ft_cat");
	int fd;
	fd = open("test2.txt", O_RDONLY);
	ft_cat(42);
	ft_cat(-1);
	ft_cat(fd);
	fd = open("test.txt", O_RDONLY);
	ft_cat(fd);
	ft_putendl("---------------ft_cat");

	// // BONUS
	ft_putendl("\n============== bonus ==============\n");
	
	// FT_STRCHR
	char *f;
	ft_putendl(str);
	if ((f = ft_strchr(str, 'l')) != NULL)
		ft_putstr(f);
	else
		ft_putstr("null");
	ft_putendl("\n------------ft_strchr\n");

	// FT_STRRCHR
	ft_putendl(str);
	if ((f = ft_strrchr(str, 'e')) != NULL)
		ft_putstr(f);
	else
		ft_putstr("null");
	ft_putendl("\n-----------ft_strrchr\n");

	// FT_STRNEW
	f = ft_strnew(7);
	ft_putstr(f);
	f = ft_memcpy(f, str, 6);
	ft_putstr(f);
	ft_putendl("\n------------ft_strnew\n");

	// FT_STREQU
	ft_putnbr(ft_strequ(str, f));
	ft_putnbr(ft_strequ(f, str)); ft_putchar('\n');
	ft_putnbr(ft_strequ(str, str));
	ft_putendl("\n------------ft_strequ\n");

	// FT_STRJOIN

	ft_putstr(ft_strjoin(str, f));
	ft_putendl("\n-----------ft_strjoin\n");
	return (0);
}













