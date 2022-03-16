#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    pid_t child,child1;
    child = fork();
    
    if(child==0){
        child1=fork();
        if(child1==0){
            printf("I am grand child process and my id is : %d\n",getpid());
            printf("Grand child process's parent id : %d\n",getppid());
            printf("Task of grand child is execute\n");
            execl("/usr/bin/vi","vi","i1.txt",0);
        }

        wait(NULL);
        printf("\nI am child Process and my id is: %d\n",getpid());
        printf("My parent process id is: %d\n",getppid());
        printf("Task of child process is execute\n"); 
        execlp("ls","-a",NULL);  
        printf("\n");          
    }
    else{
        wait(NULL);
        printf("\nI am parent Process and my pid is: %d\n",getpid());
        printf("My child process id: %d\n",child);
    }      

    return 0;
}
