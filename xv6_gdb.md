## Bash shell commands
* `$nm kernel| grep _start`[^1]
* `$make-nox-gdb`[^2]
* `$gdb`

[^1]: Get `ADDRESS` (e.g. 0x0010000c)
[^2]: Get `TCP_PORT` (e.g. :26000)
## GDB shell commands
### Entry address breakpoint
* `(gdb)set architecture i386:x86-64`
* `(gdb)target remote :26000`		--> Use `TCP_PORT`
* `(gdb)file kernel`
* `(gdb)break *0x0010000c`			--> Use `ADDRESS`
* `(gdb)continue`
* `(gdb)quit`						--> Quit
### Context Switch break point
* `(gdb)set architecture i386:x86-64`
* `(gdb)target remote :26000`		--> Use `TCP_PORT`
* `(gdb)file kernel`
* `(gdb)break swtch`
* `(gdb)continue` & `(gdb)step` 	--> to proceed
* `(gdb)clear`
* `(gdb)exec`
* `(gdb)print argv[0]` & `(gdb)print argv[1]`
* `(gdb)backtrace`
* `(gdb)up`
* `(gdb)list`