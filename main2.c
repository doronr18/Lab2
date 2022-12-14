#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

// srand(time(0));
#define   MAX_COUNT  rand()% 30

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */


void  main(void){

  pid_t child_a, child_b;
  child_a = fork();

  if (child_a == 0) {
    ChildProcess();
  }else {
    child_b = fork();
    if (child_b == 0){
      ChildProcess();
    } else{
      ParentProcess();
    }
  }
}

void  ChildProcess(void)
{
     int   i;
     for (i = 1; i <= MAX_COUNT; i++){
       printf("Child Pid: %d is going to sleep! \n", getpid());
       int number;
       number = (rand() % (10-1+1)) + 1;
       sleep(number);
       printf("Child Pid: %d is awake! Where is my Parent: %d? \n", getpid(), getppid());
     }
     printf("   *** Child process is done ***\n");
    exit(0);
}

void  ParentProcess(void)
{
     int   i;
     int status, child_pid;

     for (i = 1; i <= 2; i++){
       child_pid = wait(&status);
       printf("Child Pid: %d has completed \n", child_pid);
     }
     printf("*** Parent is done ***\n");
}





/*
void  Child2Process(void)
{
     int   i;
     pid = getpid();
     ppid = getppid()
     for (i = 1; i <= MAX_COUNT; i++){
       printf("Child Pid: %d is going to sleep!", getpid());
       sleep(rand()%10+1);
       printf("Child Pid: %d is awake!\n Where is my Parent: %d?", pid, ppid);
     }
    exit(0);
    //  printf("   *** Child process is done ***\n");
}
*/

// else if (pid2 == 0) {
//     /* Child 2 code goes here */
//     Child2Process();

/*
void RunChildern(void){
  for (i = 1; i <= MAX_COUNT; i++){
    ChildProcess();
    Child2Process;
  } 
  exit(0);
}
*/