#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char buf[70];
	char *ptr = gets(buf);
	if ((int)ptr & 0xb0000000)
	{
		printf("tupuducu ptr: %p\n", (void*)ptr);
		exit(1);
	}
	printf("You Win !");
	return (0);
}

Dump of assembler code for function main:
   0x08048434 <+0>:     push   %ebp
   0x08048435 <+1>:     mov    %esp,%ebp
   0x08048437 <+3>:     and    $0xfffffff0,%esp
   0x0804843a <+6>:     sub    $0x60,%esp
   0x0804843d <+9>:     lea    0x12(%esp),%eax
   0x08048441 <+13>:    mov    %eax,(%esp)
   0x08048444 <+16>:    call   0x8048340 <gets@plt>
   0x08048449 <+21>:    mov    %eax,0x5c(%esp)
   0x0804844d <+25>:    mov    0x5c(%esp),%eax
   0x08048451 <+29>:    mov    %eax,0x58(%esp)
   0x08048455 <+33>:    mov    0x58(%esp),%eax
   0x08048459 <+37>:    and    $0xb0000000,%eax
   0x0804845e <+42>:    test   %eax,%eax
   0x08048460 <+44>:    je     0x8048483 <main+79>
   0x08048462 <+46>:    mov    $0x8048570,%eax
   0x08048467 <+51>:    mov    0x5c(%esp),%edx
   0x0804846b <+55>:    mov    %edx,0x4(%esp)
   0x0804846f <+59>:    mov    %eax,(%esp)
   0x08048472 <+62>:    call   0x8048330 <printf@plt>
   0x08048477 <+67>:    movl   $0x1,(%esp)
   0x0804847e <+74>:    call   0x8048360 <exit@plt>
   0x08048483 <+79>:    mov    $0x8048582,%eax
   0x08048488 <+84>:    mov    %eax,(%esp)
   0x0804848b <+87>:    call   0x8048330 <printf@plt>
   0x08048490 <+92>:    mov    $0x0,%eax
   0x08048495 <+97>:    leave
   0x08048496 <+98>:    ret