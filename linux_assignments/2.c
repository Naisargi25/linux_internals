#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>


int main()
{
   int fd;
   int len;
   char read_buf[50];
   fd = open("read.txt", O_CREAT | O_RDWR,0777);
 
   lseek(fd,0,SEEK_SET); // To set file pointer to 0th byte/character in the file 

   //lseek(fd,6,SEEK_SET); // To set file pointer to 6th byte/character in the file

   //lseek(fd,-6,SEEK_END); // To find 3rd byte before the end of file

   //lseek(fd,7,SEEK_CUR); // To find forward 7 bytes from current position

   read(fd,read_buf,50);
   printf("The data from write buffer is: %s\n",read_buf);

   //close fd
   close(fd);

   return 0;
}
