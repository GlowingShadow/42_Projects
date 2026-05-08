#include <stdio.h>

/*
**	comment 1
*/
void	func(void)
{

}

int		main(void)
{
	char	*str = "#include <stdio.h>%c%c/*%c**%ccomment 1%c*/%cvoid%cfunc(void)%c{%c%c}%c%cint%c%cmain(void)%c{%c%cchar%c*str = %c%s%c;%c%c/*%c%c**%ccomment 2%c%c*/%c%cprintf(str, 10, 10, 10, 9, 10, 10, 9, 10, 10, 10, 10, 10, 9, 9, 10, 10, 9, 9, 34, str, 34, 10, 9, 10, 9, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 10);%c%cfunc();%c%creturn (0);%c}%c";
	/*
	**	comment 2
	*/
	printf(str, 10, 10, 10, 9, 10, 10, 9, 10, 10, 10, 10, 10, 9, 9, 10, 10, 9, 9, 34, str, 34, 10, 9, 10, 9, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 10);
	func();
	return (0);
}
