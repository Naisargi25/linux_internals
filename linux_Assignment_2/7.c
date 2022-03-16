#include<stdio.h>
#include<unistd.h>


int main()
{
    int pid;
    pid = fork();
    if(pid == 0)
    {
        //child process
        printf("Child process is running\n");
        execl("/bin/ls", "ls","-lh",0);
    }
    else
    {
        wait(0); //parent will wait till child execute
        //sleep(5);
        printf("Parent running\n");
        printf("Parent Process Stopped...!\n");
    }
}
