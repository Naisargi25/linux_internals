#include<stdio.h>

int main()
{
  int pid_1;
  
  printf("Current process pid; %d\n",getpid());

  pid_1 = fork(); //child id sent parent 
                   // 0 return child process
  
  if(pid_1 == 0)
  {
     printf("New child process id: %d\n",getpid());
     printf("New child process id: %d\n",getppid());
  } 

  else
  {
     sleep(3);
     printf("New parent process id: %d\n",getpid());
     printf("New parent process id: %d\n",getppid());
  }

  /*if(pid_1)
  {
     printf("New parent process id: %d\n",getpid());
     printf("New parent process id: %d\n",getppid());
  } 

  else
  {
     printf("New child process id: %d\n",getpid());
     printf("New child process id: %d\n",getppid());
  }*/
 
  while(1);
  return 0;
}
