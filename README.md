# ENVIRONMENT PREPARETION
 ## LINUX
 1. `sudo apt-get install git wget qemu aqemu`
 1. `git clone https://github.com/subhrendu1987/xv6-public/`
 1. `sudo apt-get install gdb`
 1. `cd xv6-public && make qemu`
 1. If you have 64 bit OS there is a chance Makefile will not be able to find qemu.
 	Check using the command `make qemu-nox` and see the output.
  In that case you should edit the Makefile at line 54 and add the following code:
     `QEMU = qemu-system-x86_64`
 1. `make qemu-gdb`
 1. Open new terminal
  `cd xv6-public && gdb ./kernel`
  
# BUILDING AND RUNNING XV6

* To build xv6 on an x86 ELF machine (like Linux or FreeBSD), run "make".

* On non-x86 or non-ELF machines (like OS X, even on x86), you may need to install a cross-compiler gcc suite capable of producing x86 ELF binaries (see https://pdos.csail.mit.edu/6.828/).

* Then run "make TOOLPREFIX=i386-jos-elf-". Now install the QEMU PC simulator and run "make qemu".

