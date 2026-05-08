#include <stdio.h>
 
void vulnfunction(char *msg)
{
    printf(msg);
}
 
int main(int argc, char **argv)
{
    char buff[256];
 
    printf("Input: ");
    fgets(buff, 256, stdin);
    vulnfunction(buff);
    printf("Bye\n");
    return 0;
}
/*
(lldb) di -n vulnfunction
test1`vulnfunction:
test1[0x1ea0] <+0>:  pushl  %ebp
test1[0x1ea1] <+1>:  movl   %esp, %ebp
test1[0x1ea3] <+3>:  subl   $0x18, %esp
test1[0x1ea6] <+6>:  movl   0x8(%ebp), %eax
test1[0x1ea9] <+9>:  movl   %eax, -0x4(%ebp)
test1[0x1eac] <+12>: movl   -0x4(%ebp), %eax
test1[0x1eaf] <+15>: movl   %eax, (%esp)
test1[0x1eb2] <+18>: calll  0x1f74                    ; symbol stub for: printf
test1[0x1eb7] <+23>: movl   %eax, -0x8(%ebp)
test1[0x1eba] <+26>: addl   $0x18, %esp
test1[0x1ebd] <+29>: popl   %ebp
test1[0x1ebe] <+30>: retl
test1[0x1ebf] <+31>: nop

(lldb) di -n main
test1`main:
test1[0x1ec0] <+0>:   pushl  %ebp
test1[0x1ec1] <+1>:   movl   %esp, %ebp
test1[0x1ec3] <+3>:   pushl  %edi
test1[0x1ec4] <+4>:   pushl  %esi
test1[0x1ec5] <+5>:   subl   $0x130, %esp              ; imm = 0x130
test1[0x1ecb] <+11>:  calll  0x1ed0                    ; <+16>
test1[0x1ed0] <+16>:  popl   %eax
test1[0x1ed1] <+17>:  movl   0xc(%ebp), %ecx
test1[0x1ed4] <+20>:  movl   0x8(%ebp), %edx
test1[0x1ed7] <+23>:  leal   0xcc(%eax), %esi
test1[0x1edd] <+29>:  movl   $0x0, -0xc(%ebp)
test1[0x1ee4] <+36>:  movl   %edx, -0x10(%ebp)
test1[0x1ee7] <+39>:  movl   %ecx, -0x14(%ebp)
test1[0x1eea] <+42>:  movl   %esi, (%esp)
test1[0x1eed] <+45>:  movl   %eax, -0x118(%ebp)
test1[0x1ef3] <+51>:  calll  0x1f74                    ; symbol stub for: printf
test1[0x1ef8] <+56>:  movl   $0x100, %ecx              ; imm = 0x100
test1[0x1efd] <+61>:  movl   -0x118(%ebp), %edx
test1[0x1f03] <+67>:  movl   0x138(%edx), %esi
test1[0x1f09] <+73>:  leal   -0x114(%ebp), %edi
test1[0x1f0f] <+79>:  movl   (%esi), %esi
test1[0x1f11] <+81>:  movl   %edi, (%esp)
test1[0x1f14] <+84>:  movl   $0x100, 0x4(%esp)         ; imm = 0x100
test1[0x1f1c] <+92>:  movl   %esi, 0x8(%esp)
test1[0x1f20] <+96>:  movl   %eax, -0x11c(%ebp)
test1[0x1f26] <+102>: movl   %ecx, -0x120(%ebp)
test1[0x1f2c] <+108>: calll  0x1f6e                    ; symbol stub for: fgets
test1[0x1f31] <+113>: leal   -0x114(%ebp), %ecx
test1[0x1f37] <+119>: movl   %ecx, (%esp)
test1[0x1f3a] <+122>: movl   %eax, -0x124(%ebp)
test1[0x1f40] <+128>: calll  0x1ea0                    ; vulnfunction
test1[0x1f45] <+133>: movl   -0x118(%ebp), %eax
test1[0x1f4b] <+139>: leal   0xd4(%eax), %ecx
test1[0x1f51] <+145>: movl   %ecx, (%esp)
test1[0x1f54] <+148>: calll  0x1f74                    ; symbol stub for: printf
test1[0x1f59] <+153>: xorl   %ecx, %ecx
test1[0x1f5b] <+155>: movl   %eax, -0x128(%ebp)
test1[0x1f61] <+161>: movl   %ecx, %eax
test1[0x1f63] <+163>: addl   $0x130, %esp              ; imm = 0x130
test1[0x1f69] <+169>: popl   %esi
test1[0x1f6a] <+170>: popl   %edi
test1[0x1f6b] <+171>: popl   %ebp
test1[0x1f6c] <+172>: retl

*/