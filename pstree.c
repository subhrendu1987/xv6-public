#include "types.h"
#include "stat.h"
#include "user.h"
#include "uproc.h"
#define MAXPROC 64

int
main(int argc, char *argv[]){
  // declare a uproc struct with an allocated size of 64
  struct uproc *prs = malloc(MAXPROC*sizeof(struct uproc));

  // call getprocs in kernel space and get the amount of processes running back
  int num = getprocs(MAXPROC, prs);

  // getprocs will return -1 if an error is received. Handle errors here
  if(num == -1){
    printf(1, "Kernel returned an error when getting processes. \n");
    exit();
  }

  // create a counter
  int i=0;

  // loop through uproc structs that were created in the kernel space for each process
  for(; i< num; i++) {
    // format output to the user
    if(prs[i].pid == 1){
      // if the pid is 1 then this is init
      printf(1, "%s[%d] \n", prs[i].name, prs[i].pid-1);
    }else if(prs[i].ppid == 1){
      // if parent pid is 1, then it is a child to parent init
      printf(1, "   %s[%d] \n", prs[i].name, prs[i].pid-1);
    }else {
      // if parent pid is not 1, then it is a grandchild to init and child to another process
      printf(1, "      %s[%d] \n", prs[i].name, prs[i].pid-1);
    }
  }

  // exit after pstree command is done
  exit();
}
