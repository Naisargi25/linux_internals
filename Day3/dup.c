#include<stdio.h>
#include<fcntl.h>

int main()
{
   int fd1,fd2,fd3,fd4;
   fd1 = open("linux_1.txt",O_WRONLY | O_CREAT | O_TRUNC,0777);
   fd2 = open("linux_2.txt",O_WRONLY | O_CREAT | O_TRUNC,0777);

   printf("fd1 = %d\n",fd1);
   printf("fd2 = %d\n",fd2);
 
   fd3 = dup(fd1);
   fd4 = dup2(fd2,8);
   printf("Value of fd3 = %d\n",fd3);
   printf("Value of fd4 = %d\n",fd4);
   close(fd4);
   close(fd3);
   close(fd2);
   close(fd1);

   return 0;
}
