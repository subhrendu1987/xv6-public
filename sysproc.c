#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "uproc.h"
#include "spinlock.h"

struct {
  struct spinlock lock;
  struct proc proc[NPROC];
} ptable;


int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

/*int
sys_halt(void)
{
  char *p = "Shutdown";
  for( ; *p; p++)
    outw(0xB004, 0x2000);
  return 0;
}*/

int
sys_halt(void)
{
  outb(0xf4, 0x00);
  return 0;
}


int
sys_cps(void)
{
  return cps();
}

int
sys_chpr(void)
{
  int pid, pr;
  if(argint(0, &pid) < 0)
    return -1;
  if(argint(1, &pr) < 0)
    return -1;

  return chpr(pid, pr);
}

int
sys_getprocs(void){
  // declare local variables for max uproc size, struct uproc, and counter
  int max;
  struct uproc *p;
  int i=0;

  // if argint has trouble, return error -1
  if(argint(0,&max) < 0)
    return -1;

  // if argptr for allocating struct size has trouble, return -1
  if(argptr(1,(char**)&p, max*sizeof(struct uproc)) < 0)
    return -1;

  // create pointer to ptable processes
  struct proc *ptr = ptable.proc;

  // loop through ptable
  for(; ptr < &ptable.proc[NPROC]; ptr++)
  {
    if(!(ptr->state == UNUSED))
    {
      // if the process in ptable is not UNUSED, assign pid, parent pid, and name to uproc
      p[i].pid = ptr->pid;
      p[i].ppid = ptr->parent->pid;
      strncpy(p[i].name, ptr->name, 16);
      // add 1 to the process counter
      i++;
    }
  }
  
  // return the number of processes that are not UNUSED
  return i;
}



