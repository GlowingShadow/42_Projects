#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
int main(void)
{
	int i = 5;if(i<0)return(2);
	char *cmd = strdup("gcc Sully_X.c -o Sully_X ; ./Sully_X X");
	cmd[10] = i + 48;cmd[23] = i + 48;cmd[35] = i + 48;cmd[37] = i + 48;
	char *str = "#include <stdio.h>%c#include <stdlib.h>%c#include <string.h>%c#include <fcntl.h>%cint main(void)%c{%c%cint i = %d;if(i<0)return(2);%c%cchar *cmd = strdup(%cgcc Sully_X.c -o Sully_X ; ./Sully_X X%c);%c%ccmd[10] = i + 48;cmd[23] = i + 48;cmd[35] = i + 48;cmd[37] = i + 48;%c%cchar *str = %c%s%c;%c%cchar *file = strndup(cmd + 4, 9);int fd = open(file, O_CREAT | O_WRONLY, 0666);if(fd==-1)return(1);dprintf(fd, str, 10,10,10,10,10,10,9,i-1,10,9,34,34,10,9,10,9,34,str,34,10,9,10,9,10,10);%c%csystem(cmd); return (0);%c}%c";
	char *file = strndup(cmd + 4, 9);int fd = open(file, O_CREAT | O_WRONLY, 0666);if(fd==-1)return(1);dprintf(fd, str, 10,10,10,10,10,10,9,i-1,10,9,34,34,10,9,10,9,34,str,34,10,9,10,9,10,10);
	system(cmd); return (0);
}
