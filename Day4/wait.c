#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
   pid_t pid;
   
   if(pid==0)
   {
     sleep(5);
     printf("I am child process\n");
   }

   else
   {
      int pid2;
      printf("I am parent processs\n");
      pid2 = wait(0);

      printf("child process %d executed normally\n",pid2);
      printf("Process id = %d\n",getpid());
   }
   return 0;
}
