#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
   int f1,f2,len,total;

   char buff_copy[100];
   char new[100];
   f1 = open("read.txt",O_RDONLY,0777); //open a file called read.txt file to read data
   f2 = open("new_linux.txt",O_CREAT | O_RDWR,0777); //open a file called new_linux.txt to write data
   
   read(f1,buff_copy,100);

   total = lseek(f1,0,SEEK_END);
   printf("Total = %d\n",total);
   write(f2,buff_copy,total);  

   //close fds
   close(f1);
   close(f2);
   return 0;
}
