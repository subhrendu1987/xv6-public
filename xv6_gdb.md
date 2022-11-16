## Bash shell commands
`$nm kernel| grep _start`	--> Get `ADDRESS` (e.g. 0x0010000c)
`$make-nox-gdb`				--> Get `TCP_PORT` (e.g. :26000)
`$gdb`
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