/*
**	comment 1
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define STR "/*%c**%ccomment 1%c*/%c#include <stdio.h>%c#include <stdlib.h>%c#include <fcntl.h>%c#define STR %c%s%c%c#define TWO int fd = open(%cGrace_kid.c%c, O_CREAT | O_WRONLY, 0666);if(fd==-1)return(1);dprintf(fd, STR, 10, 9, 10, 10, 10, 10, 10, 34, STR, 34, 10, 34, 34, 10, 10, 10, 10);%c#define ONE int main(void){TWO return (0);}%c%cONE%c"
#define TWO int fd = open("Grace_kid.c", O_CREAT | O_WRONLY, 0666);if(fd==-1)return(1);dprintf(fd, STR, 10, 9, 10, 10, 10, 10, 10, 34, STR, 34, 10, 34, 34, 10, 10, 10, 10);
#define ONE int main(void){TWO return (0);}

ONE
