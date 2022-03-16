#include<stdio.h>
#include<fcntl.h>

int main()
{
    int fd;
    fd = open("/home/naisargi/Process/read",O_RDONLY,0777);
    printf("Inherited File Descriptor: %d\n",fd);   
}
