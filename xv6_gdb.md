## Bash shell commands
* `$nm kernel| grep _start`[^1]
* `$make-nox-gdb`[^2]
* `$gdb`[^0]

[^0]: (Cheatsheet) [https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf]
[^1]: Get `ADDRESS` (e.g. 0x0010000c)
[^2]: Get `TCP_PORT` (e.g. :26000)
## GDB shell commands
### Entry address breakpoint
* `(gdb)set architecture i386:x86-64`
* `(gdb)target remote :26000`[^1]
* `(gdb)file kernel`
* `(gdb)break *0x0010000c`[^2]
* `(gdb)continue`
* `(gdb)quit`[^3]

[^3]: Quit
### Context Switch break point
* `(gdb)set architecture i386:x86-64`
* `(gdb)target remote :26000`[^1]
* `(gdb)file kernel`
* `(gdb)break swtch`
* `(gdb)continue` & `(gdb)step`
* `(gdb)clear`
* `(gdb)exec`
* `(gdb)print argv[0]` & `(gdb)print argv[1]`
* `(gdb)backtrace`
* `(gdb)up`
* `(gdb)list`