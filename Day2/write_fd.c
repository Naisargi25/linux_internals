#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd1,len;
    int x;
    char write_buff[60] = "Linux kernel new program";
    
     
    fd1 = open("linux_xyz.txt",O_CREAT | O_RDWR, 0777);

    //printf("File descriptor for linux_abc.txt file is: %d\n",fd1);

    write(fd1,write_buff,60); //from write_buf writing to fd

    close(fd1);
    return 0;
}


