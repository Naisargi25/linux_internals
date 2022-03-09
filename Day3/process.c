#include<stdio.h>
#include<unistd.h>

int main()
{
   printf("MY process id: %d\n", getpid());
   printf("PArent process id: %d\n",getppid());
  
   while(1);
   return 0;
}
