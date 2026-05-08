/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:50:07 by REDACTED          #+#    #+#             */
/*   Updated: 2014/11/10 17:08:06 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	f(char *s)
{
	s[0] = 'c';
}

void	f2(unsigned int i, char *s)
{
	if (i > 5)
		(s + i)[0] = 'c';
}

char	f3(char s)
{
	s = 'c';
	return (s);
}

char	f4(unsigned int i, char s)
{
	if (i > 5)
		s = 'c';
	return (s);
}

int		main(void)
{
	printf("[]ft_putchar:\n");
	ft_putchar('Y');
	printf("\n\n");

	printf("[]ft_putstr:\n");
	char	str[] = "Fonctionne";
	ft_putstr(str);
	printf("\n\n");

	printf("[]ft_putnbr: 450850, 0, -55\n");
	ft_putnbr(450850);
	ft_putchar('\n');
	ft_putnbr(0);
	ft_putchar('\n');
	ft_putnbr(-55);
	printf("\n\n");

	printf("[]ft_strlen: (10lettres)\n");
	printf("%d", ft_strlen(str));
	printf("\n\n");

	printf("[]ft_strdup:\n");
	printf("%s", ft_strdup(str));
	printf("\n\n");

	printf("[]ft_strcpy:\n");
	char	dest[] = "Ne fonctionne pas";
	printf("%s", ft_strcpy(dest, str));
	printf("\n\n");

	printf("[]ft_strncpy:\n");
	char	src1[] = "Fonctionne";
	char	dst1[] = "AAnctionne";
	printf("%s", ft_strncpy(dst1, src1, 2));
	printf("\n\n");

	printf("[]ft_strstr: Fonctionne\n");
	char	str2[] = "TonProgrammeFonctionne";
	char	str3[] = "";
	char	str32[] = "coucou";
	printf("%s\n", ft_strstr(str2, str));
	printf("%s\n", ft_strstr(str2, str3));
	printf("%s", ft_strstr(str2, str32));
	printf("\n\n");

	printf("[]ft_strnstr: gramme\n");
	char	t1[] = "TonProgrammeFonctionne";
	char	t2[] = "gramme";
	char	t3[] = "";
	char	t33[] = "";
	char	*strr = "Hello les genw";
	printf("%s\n", ft_strnstr(strr, "Hello", 6));
	printf("%s\n", ft_strnstr(strr, "Hello", 3));
	printf("%s\n", ft_strnstr(strr, "les", 1));
	printf("%s\n", ft_strnstr(strr, "gen", 2));
	printf("%s\n", ft_strnstr(strr, "w", 0));
	printf("%s\n", ft_strnstr(strr, "", 3));

	printf("%s\n", ft_strnstr(t1, t2, 156));
	printf("%s\n", ft_strnstr(t1, t3, 7));
	printf("%s", ft_strnstr(t1, t2, 2));
	printf("%s\n", ft_strnstr(t3, t33, 7));
	printf("\n\n");

	printf("[]ft_tolower:\n");
	printf("%c", ft_tolower(89));
	printf("%c", ft_tolower(49));
	printf("%c", ft_tolower(63));
	printf("\n\n");

	printf("[]ft_toupper:\n");
	printf("%c", ft_toupper(121));
	printf("%c", ft_toupper(49));
	printf("%c", ft_toupper(63));
	printf("\n\n");

	printf("[]ft_strjoin:\n");
	char	*s1 = "Fonc";
	char	*s2 = "tionne";
	printf("%s", ft_strjoin(s1, s2));
	printf("\n\n");

	printf("[]ft_strtrim: mots separes par ' ', \\n puis \\t\n");
	char	*s3 = " \n \t Ton programme\nfonctionne\tparfaitememt \t \n";
	printf("%s", ft_strtrim(s3));
	printf("%c", '_');
	printf("\n\n");

	printf("[]ft_strsplit:\n");
	char	*s4 = "Ton*programme*fonctionne*parfaitement*";
	char	*s441 = "Ton*programme*fonctionne*parfaitement*";
	char	*s442 = "Fonctionne";
	char	*s443 = "**********";
	int		i;
	char	**tab = ft_strsplit(s4, '*');
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	ft_putnbr(i);
	printf("\n\n");
	/////////////////////////////////////////////////
	tab = ft_strsplit(s441, '*');
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	ft_putnbr(i);
	printf("\n\n");
	///////////////////////////////////////////////
	tab = ft_strsplit(s442, '*');
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	ft_putnbr(i);
	printf("\n\n");
	////////////////////////////////////////////////
	tab = ft_strsplit(s443, '*');
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	ft_putnbr(i);
	printf("\n\n");
/*
	printf("[]ft_memcmp: 42?\n");
	char	s5[] = "k\200";
	char	s55[] = "A\200";
	char	s6[] = "A\0";
	printf("%d\n", ft_memcmp(s5, s6, 2));
	printf("%d\n", ft_memcmp(s55, s6, 2));
	printf("\n\n");

	printf("[]ft_bzero:\n");
	char	s7[50] = "coucou";
	ft_bzero(s7, 3);
	printf(s7);
	printf("\n\n");

	printf("[]ft_memset: 3 espaces avant \n");
	char s8[50] ="FFFFonctionne";
	ft_memset(s8, ' ', 3);
	printf(s8);
	printf("\n\n");

	printf("[]ft_memmove:\n");
	char	s9[] = "coucou";
	char	s10[] = "Fonctionne";
	ft_memmove(s9, s10, 10);
	printf(s9);
	printf("\n\n");

	printf("[]ft_memchr: \n");
	char	s11[] = "TonProgrammeFonctionne";
	printf(ft_memchr(s11, 70, 13));
	printf("\n");
	if (ft_memchr(s11, 70, 12) == NULL)
		printf("%d", 1);
	printf("\n\n");

	printf("[]ft_memcpy:\n");
	char	src2[] = "Fonctionne";
	char	dst2[] = "";
	//	printf(dst2);
	//	printf("\n");
	ft_memcpy(dst2, src2, ft_strlen(src2));
	printf(dst2);
	printf("\n\n");

	printf("[]ft_memccpy:\n");
	char	src3[] = "Fonctionne aussi oupas";
	char	dst3[] = "blablabla";
	printf("%p\n", ft_memccpy(dst3, src3, 116, 13));
	printf("%s ", dst3);
	if (dst3[ft_strlen(dst3)] == '\0')
		printf("Y\n");
	if (ft_memccpy(dst3, src3, 'Z', 16) == NULL)
		printf(dst3);
	printf("\n\n");

	printf("[]ft_strcat:\n");
	char	s12[] = "Fonc";
	char	s13[] = "tionne";
	printf("%s", ft_strcat(s12, s13));
	printf("\n\n");

	printf("[]ft_strncat:\n");
	char	s14[] = "Fonc";
	char	s15[] = "tionnePAS";
	char	s114[] = "";
	char	s115[] = "FonctionnePAS";
	printf("%s\n", ft_strncat(s14, s15, 6));
	printf("%s", ft_strncat(s114, s115, 10));
	printf("\n\n");

	printf("[]ft_strlcat:\n");
	char	s16[] = "Fonc\0.....";
	char	s17[] = "tionne";
	ft_putnbr(ft_strlcat(s16, s17, sizeof(s16)));
	printf(s16);
	ft_putnbr(ft_strlen(s16));
	printf("\n\n");

	printf("[]ft_strchr:\n");
	char	s18[] = "oFonctionne";
	printf(ft_strchr(s18, 70));
	printf("\n");
	if (ft_strchr(s18, 65) == NULL) 
		printf("NULL Fonctionne");
	if ((ft_strchr(s18, 0))[0] == '\0')
		printf("\n\\0 Fonctionne");
	else
		printf("\n\\0 ne fonctionne pas");
	printf("\n\n");

	printf("[]ft_strrchr:\n");
	char	s19[] = "oFFFonctionne";
	char	s119[] = "";
	//	printf(ft_strrchr(s19, 'F'));
	if (ft_strrchr(s119, 'd') == NULL)
		ft_putstr("null>>");
	printf("\n");
	if (ft_strrchr(s19, 65) == NULL) 
		printf("NULL Fonctionne");
	if ((ft_strrchr(s19, 0))[0] == '\0')
		printf("\n\\0 Fonctionne");
	else
		printf("\n\\0 ne fonctionne pas");
	printf("\n\n");

	printf("[]ft_strcmp:\n");
	char	s20[] = "a\200AAAA";
	char	s21[] = "a\0AAAB";
	char	s22[] = "aa";
	printf("%d\n", ft_strcmp(s20, s21));
	printf("%d\n", ft_strcmp(s21, s21));
	printf("%d", ft_strcmp(s21, s22));
	printf("\n\n");

	printf("[]ft_strncmp:\n");
	printf("%d\n", ft_strncmp(s20, s21, 3));
	printf("%d\n", ft_strncmp(s21, s21, 3));
	printf("%d\n", ft_strncmp(s21, s22, 3));
	printf("%d\n", ft_strncmp(s20, s21, 1));
	printf("%d\n", ft_strncmp(s21, s21, 1));
	printf("%d", ft_strncmp(s21, s22, 1));
	printf("\n\n");

	printf("[]ft_isalpha: AZaz 1? \\0\n");
	printf("%d ", ft_isalpha(65));
	printf("%d ", ft_isalpha(90));
	printf("%d ", ft_isalpha(97));
	printf("%d\n", ft_isalpha(122));
	printf("%d ", ft_isalpha(64));
	printf("%d ", ft_isalpha(91));
	printf("%d ", ft_isalpha(96));
	printf("%d\n", ft_isalpha(123));
	printf("%d ", ft_isalpha(49));
	printf("%d ", ft_isalpha(63));
	printf("%d ", ft_isalpha(32));
	printf("%d", ft_isalpha('\0'));
	printf("\n\n");

	printf("[]ft_isdigit: 0-9\n");
	printf("%d ", ft_isdigit(48));
	printf("%d ", ft_isdigit(49));
	printf("%d ", ft_isdigit(50));
	printf("%d ", ft_isdigit(51));
	printf("%d ", ft_isdigit(52));
	printf("%d ", ft_isdigit(53));
	printf("%d ", ft_isdigit(54));
	printf("%d ", ft_isdigit(55));
	printf("%d ", ft_isdigit(56));
	printf("%d\n", ft_isdigit(57));
	printf("%d ", ft_isdigit(47));
	printf("%d", ft_isdigit(58));
	printf("\n\n");

	printf("[]ft_isalnum:\n");
	printf("%d ", ft_isalnum(65));
	printf("%d ", ft_isalnum(90));
	printf("%d ", ft_isalnum(97));
	printf("%d\n", ft_isalnum(122));
	printf("%d ", ft_isalnum(64));
	printf("%d ", ft_isalnum(91));
	printf("%d ", ft_isalnum(96));
	printf("%d\n", ft_isalnum(123));
	printf("%d ", ft_isalnum(49));
	printf("%d ", ft_isalnum(63));
	printf("%d ", ft_isalnum(32));
	printf("%d", ft_isalnum('\0'));
	printf("\n");
	printf("%d ", ft_isalnum(48));
	printf("%d ", ft_isalnum(49));
	printf("%d ", ft_isalnum(50));
	printf("%d ", ft_isalnum(51));
	printf("%d ", ft_isalnum(52));
	printf("%d ", ft_isalnum(53));
	printf("%d ", ft_isalnum(54));
	printf("%d ", ft_isalnum(55));
	printf("%d ", ft_isalnum(56));
	printf("%d\n", ft_isalnum(57));
	printf("%d ", ft_isalnum(47));
	printf("%d\n", ft_isalnum(58));
	printf("\n\n");

	printf("[]ft_isascii:\n");
	int		y;
	y = 0;
	while (y < 128)
	{
		ft_putnbr(ft_isascii(y));
		y++;
	}
	printf("\n%d", ft_isascii(128));
	printf("\n\n");

	printf("[]ft_isprint:\n");
	y = 31;
	printf("%d\n", ft_isprint(y));
	y = 32;
	while (y < 127)
	{
		ft_putnbr(ft_isprint(y));
		y++;
	}
	printf("\n%d", ft_isprint(127));
	printf("\n\n");

	printf("[]ft_atoi:\n");
	/*	printf("%d\n", ft_atoi(" \n-999sssss"));
		printf("%d\n", ft_atoi("\t-999sssss"));
		printf("%d\n", ft_atoi("+45"));
		printf("%d\n", ft_atoi("+46 64"));
		printf("%d\n", ft_atoi("4"));
		printf("%d\n", ft_atoi("+999sssss"));
		printf("%d\n", ft_atoi("-95422"));
		printf("%d\n", ft_atoi("999sssss"));
		printf("%d\n", ft_atoi("aa999sssss"));
		printf("%d\n", ft_atoi("a999sssss"));
		printf("%d\n", ft_atoi("++999sssss"));
		printf("%d\n", ft_atoi("--999sssss"));
		printf("%d\n", ft_atoi("-+999sssss"));
		printf("%d\n", ft_atoi("2500100100"));
		printf("%d\n", ft_atoi("12-3"));
		printf("%d\n", ft_atoi("-+123"));
		printf("%d\n", ft_atoi("a123"));
		printf("%d\n", ft_atoi("123a"));
		printf("%d\n", ft_atoi("123"));
		printf("%d\n", ft_atoi("-123"));
		printf("%d\n", ft_atoi("+123"));
		printf("%d\n", ft_atoi(" - 123"));
		printf("%d\n", ft_atoi("\t - 123"));
		printf("%d\n", ft_atoi("-2147483648"));
		printf("%d\n", ft_atoi("\n\v\t\r\f -123"));
		printf("%d\n", ft_atoi("\n\t -123"));
		*/	
	//printf("%d\n\n", -2147483648); //  explication?
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", ft_atoi("123"));
	printf("%d\n", ft_atoi("-123"));
	printf("%d\n", ft_atoi(""));
	
	   printf("\n");

	   printf("[]ft_memalloc:\n");
	   char	*s23;
	   char	s24[] = "Fonctionne";
	   int		z;
	   z = 0;
	   s23 = ft_memalloc(ft_strlen(s24));
	   while (z < ft_strlen(s24))
	   {
	   s23[z] = s24[z];
	   z++;
	   }
	   s23[z] = '\0';
	   printf(s23);
	   printf("\n\n");

	   printf("[]ft_memdel: voir le code");
	   void	*s25;
	   s25 = ft_memalloc(40);
	   ft_memdel(&s25);
	   printf("\n\n");

	   printf("[]ft_strnew: remplacer '\\0' dans le .c pour comparer strlen\n");
	   char	*s26;
	   s26 = ft_strnew(16);
	   printf("%d\n", ft_strlen(s26));
	   printf(s26);
	   printf("\n\n");

	   printf("[]ft_strclr:\n");
	   char	*s28;
	   s28 = (char*)malloc(sizeof(char) * 50);
	   int	i2;
	   i2 = 0;
	   while (i2 < 25)
	   {
	   s28[i2] = 'c';
	   i2++;
	   }	
	   printf(s28);
	   printf("\n");
	   ft_strclr(s28);
	   printf(s28);
	   printf(";\n\n");

	   printf("[]ft_strdel:\n");
	   char	*s27;
	   s27 = (char*)malloc(sizeof(char) * 50);
	   int	i1;
	   i1 = 0;
	   while (i1 < 25)
	   {
	   s27[i1] = 'c';
	   i1++;
	   }	
	   printf("%s\n", s27);
	   ft_strdel(&s27);
	   if(s27 == NULL)
	   printf("Fonctionne");
	   printf(";\n\n");

	   printf("[]ft_striter: fonction: remplace par 'c'\n");
	   char	*s29;
	   s29 = (char*)malloc(sizeof(char) * 50);
	   int	i3;
	   i3 = 0;
	   while (i3 < 25)
	   {
	   s29[i3] = '*';
	i3++;
}	
printf("%s\n", s29);
ft_striter(s29, f);
printf(s29);
printf("\n\n");

printf("[]ft_striteri: fonction: remplace par 'c' a partir de la 7e\n");
char	*s30;
s30 = (char*)malloc(sizeof(char) * 50);
int	i4;
i4 = 0;
while (i4 < 25)
{
	s30[i4] = '*';
	i4++;
}	
printf("%s\n", s30);
ft_striteri(s30, f2);
printf(s30);
printf("\n\n");

printf("[]ft_strmap: fonction: remplace par 'c'\n");
char	*s31;
s31 = (char*)malloc(sizeof(char) * 50);
int	i5;
i5 = 0;
while (i5 < 25)
{
	s31[i5] = '*';
	i5++;
}	
printf("%s\n", s31);
printf("%s", ft_strmap(s31, f3));
printf("\n\n");

printf("[]ft_strmapi: fonction: remplace par 'c' a partir de la 7e\n");
char	*s32;
s32 = (char*)malloc(sizeof(char) * 50);
int	i6;
i6 = 0;
while (i6 < 25)
{
	s32[i6] = '*';
	i6++;
}	
printf("%s\n", s32);
printf("%s", ft_strmapi(s32, f4));
printf("\n\n");

printf("[]ft_strequ: 1 1 0 0 0\n");
char	s33[] = "coucou";
char	s34[] = "coucou";
char	s35[] = "poutou";
char	s36[] = "";
char	s37[] = "";
printf("%d ", ft_strequ(s33, s34));
printf("%d ", ft_strequ(s36, s37));
printf("%d ", ft_strequ(s33, s35));
printf("%d ", ft_strequ(s33, s36));
printf("%d ", ft_strequ(s36, s33));
printf("\n\n");

printf("[]ft_strnequ: 1 1 0 0 0\n");
char	s38[] = "coucou";
char	s39[] = "coutou";
char	s41[] = "";
char	s42[] = "";
printf("%d ", ft_strnequ(s38, s39, 3));
printf("%d ", ft_strnequ(s41, s42, 5));
printf("%d ", ft_strnequ(s38, s39, 4));
printf("%d ", ft_strnequ(s38, s41, 5));
printf("%d ", ft_strnequ(s41, s38, 5));
printf("\n\n");

printf("[]ft_strsub:\n");
char	s40[] = "Ton Programme Ne Fonctionne Pas";
printf("%s", ft_strsub(s40, 17, 10));
printf("\n\n");

printf("[]ft_itoa:\n");
printf("%s\n", ft_itoa(12345));
printf("%s\n", ft_itoa(+12345));
printf("%s\n", ft_itoa(0));
printf("%s\n", ft_itoa(+0));
printf("%s\n", ft_itoa(-0));
printf("%s\n", ft_itoa(-12345));

printf("\n%s", ft_itoa(2147483647));
printf("\n%s\n", ft_itoa(-2147483648));
printf("\n\n");

printf("[]ft_putendl:\n");
char	s43[] = "Fonctionne";
ft_putendl(s43);
printf("_");
printf("\n\n");

printf("[]ft_putchar_fd:\n");
ft_putchar_fd('Y', 1);
printf("\n\n");

printf("[]ft_putstr_fd:\n");
char	s44[] = "Fonctionne";
ft_putstr_fd(s44, 1);
printf("\n\n");

printf("[]ft_putendl_fd:\n");
ft_putendl_fd(s44, 1);
ft_putchar_fd('_', 1);
printf("\n\n");

printf("[]ft_putnbr_fd: 450850, 0, -55\n");
ft_putnbr_fd(450850, 1);
printf("\n");
ft_putnbr_fd(0, 1);
printf("\n");
ft_putnbr_fd(-55, 1);
printf("\n");
ft_putnbr_fd(-2147483648, 1);
printf("\n\n");
*/
return (0);
}
