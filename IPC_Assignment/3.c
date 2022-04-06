#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int fds[2];

//parent code
void parent_code()
{
    char buf[100];
    printf("Parent process is runnig\n");
    printf("Enter the string: ");
    scanf("%s",buf);
    close(fds[0]);
    write(fds[1], buf, 20);
    printf("End of parent process\n\n");
    sleep(1);
}

// togglecase mathod
void toggleCase(char buf[],int cnt)
{
    int i;
    for(i=0;i<cnt;i++)
    {
        if((buf[i]>='A') && (buf[i] <= 'Z'))
        {
            buf[i] += 32; // +32 => A = 65 , a = 65+32 = 97
        }
        else if((buf[i] >= 'a') && (buf[i] <= 'z'))
        {
            buf[i] -= 32;
        }
    }
}

// child code
void child_code()
{
    char buf[100];
    int n;
    close(fds[1]);
    n = read(fds[0], buf, 100);
    printf("Child process is running\n");
    printf("No of charecteres read = %d\n", n);
    toggleCase(buf,n);
    printf("\n\nString read by child process is: %s",buf);
    printf("\nEnd of child process\n");
}
int main()
{
    int res, i;
    pid_t p;

    res = pipe(fds);

    if (res == -1)
    {
        perror("pipe");
        exit(1);
    }
    p = fork();
    if (p == 0)
        //child cod executes
        child_code();
    else
        //parent code executes
        parent_code();

    return 0;
}