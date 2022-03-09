#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>


int main()
{
   int fd;
   char buf[300];
   int res;
   fd = open("fd2.c", O_CREAT | O_RDWR, 0777);
   if(fd<0)
   {
      printf("No data is created or read");
   }
   read(fd,buf,300);
   printf("%s",buf);
   return 0;
}
