#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int pid;
    pid = fork();
    if(pid == 0)
    {
        //child process
        printf("Child process is running \n");
        printf("\nReading data....\n");
        int fd;
        char buf[300];
        fd = open("4.c", O_CREAT | O_RDWR, 0777);
        if(fd<0)
        {
            printf("No data is created or read");
        }
   
        read(fd,buf,300);
        printf("%s",buf);

        //it will read data from the 4.c and it will display on terminal
        printf("\nChild process stopped...!");
    }

    else
    {
        wait(0);//parent will wait till child execute
        printf("\n\nParent running\n");
        printf("Parent Process Stopped...!\n");
    }
}
