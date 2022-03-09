#include<stdio.h>
#include<fcntl.h>

int main()
{
    int fd1;
   
    fd1 = open("linux_abc.txt",O_CREAT | O_RDWR, 0777);

    printf("File descriptor for linux_abc.txt file is: %d\n",fd1);

    close(fd1);
    return 0;
}


