#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
   int pid;
   int status;
   printf("Parent = %d\n",getpid());

   pid = fork();
   if(pid==0)
   {
     printf("I am child process and mypid is:%d\n",getpid());
     sleep(5);
      exit(0);
   }
   
   printf("parent is waiting for pid = %d\n",waitpid(pid,&status,0));

   return 0;
}
