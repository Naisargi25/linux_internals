#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>


int main()
{
   int fd;
   char read_buf[50];
   char write_buf[50]="Hello How are you? How was your day?";
   int len;
   fd = open("linux_kernel.txt", O_CREAT | O_RDWR,0777); 
   
   len = write(fd,write_buf,50);

   printf("Return value from a file is: %d\n",len);

   lseek(fd,6,SEEK_SET); // To set file pointer to 6th byte/character in the file
   read(fd,read_buf,len);
   printf("The data from write buffer is: %s\n",read_buf);
   close(fd);
   return 0;
}
