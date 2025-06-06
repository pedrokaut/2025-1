/*Reading symbols from C:\Users\pedro\OneDrive\Documentos\GitHub\2025-1\complexidade\2.exe...done.
(gdb) break f
Breakpoint 1 at 0x401466: file complexidade/2.c, line 8.
(gdb) n
The program is not being run.
(gdb) run
Starting program: C:\Users\pedro\OneDrive\Documentos\GitHub\2025-1/complexidade/2.exe
[New Thread 15064.0x480c]
[New Thread 15064.0x3dd4]

Breakpoint 1, f (n=3) at complexidade/2.c:8
8           if (n == 1)
(gdb) n
13          return ((1 / 2) * f(n - 1) + 2 / (f(n - 1)));
(gdb) print n
$1 = 3
(gdb) next

Breakpoint 1, f (n=2) at complexidade/2.c:8
8           if (n == 1)
(gdb) quit
A debugging session is active.

        Inferior 1 [process 15064] will be killed.*/