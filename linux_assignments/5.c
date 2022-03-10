#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

char buf1[]="LAB ";
char buf2[]="OS Linux";

int main()
{    
    int fd;
    if((fd=creat("file.txt", 0666)) < 0) 
    {
	printf("Creation error");
    }

    if(write(fd, buf1, sizeof(buf1)) < 0) //write data from the buffer 1
    {
       printf("Writing error");
    }

    if(lseek(fd, 4096, SEEK_SET) < 0) //set file pointer to 4096 
    {
       printf("Positioning error");
    }
    
    if(write(fd, buf2, sizeof(buf2)) < 0) //write data from buffer 2 at 4097 position
    {       
       printf("Writing error");
    }
   
    int total = lseek(fd,0,SEEK_END); //gives the size of the file
    printf("%d\n",total);

    return 0;
}
