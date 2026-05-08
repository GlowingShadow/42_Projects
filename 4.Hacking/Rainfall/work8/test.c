#include <stdlib.h>
#include <string.h>

char *p = NULL;

int	main(void)
{
	p = malloc(4);
	strcpy(p, "12345678");
	return (0);
}
/*
080483e4 <main>:
 80483e4:       55                      push   %ebp
 80483e5:       89 e5                   mov    %esp,%ebp
 80483e7:       83 e4 f0                and    $0xfffffff0,%esp
 80483ea:       83 ec 10                sub    $0x10,%esp
 80483ed:       c7 04 24 04 00 00 00    movl   $0x4,(%esp)
 80483f4:       e8 07 ff ff ff          call   8048300 <malloc@plt>
 80483f9:       a3 1c a0 04 08          mov    %eax,0x804a01c
 80483fe:       ba f0 84 04 08          mov    $0x80484f0,%edx
 8048403:       a1 1c a0 04 08          mov    0x804a01c,%eax
 8048408:       8b 0a                   mov    (%edx),%ecx
 804840a:       89 08                   mov    %ecx,(%eax)
 804840c:       8b 4a 04                mov    0x4(%edx),%ecx
 804840f:       89 48 04                mov    %ecx,0x4(%eax)
 8048412:       0f b6 52 08             movzbl 0x8(%edx),%edx
 8048416:       88 50 08                mov    %dl,0x8(%eax)
 8048419:       b8 00 00 00 00          mov    $0x0,%eax
 804841e:       c9                      leave
 804841f:       c3                      ret
*/