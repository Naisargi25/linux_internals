#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
  pid_t pid;
  
  printf("Current process pid; %d\n",getpid());

  pid = vfork(); //child id sent parent 
                   // 0 return child process

  if(pid)
  {  
     sleep(5);
     printf("New parent process id: %d\n",getpid());
  } 

  else
  {
     printf("New child process id: %d\n",getpid());
  }
 
  while(1);
  exit(0);
  return 0;
}
