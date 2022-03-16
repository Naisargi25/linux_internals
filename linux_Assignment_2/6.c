#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

void callback1(void)
{
    printf("Calling callback1\n");
}
void callback2(void)
{
    printf("Calling callback2\n");
}

void callback3(void)
{
    printf("Calling callback3\n");
}

void callback4(void)
{
    printf("Calling callback4\n");
}

int main()
{
    printf("Registering callback1\n");
    atexit(callback1);
    printf("Registering callback2\n");
    atexit(callback2);
    printf("Registering callback3\n");
    atexit(callback3);
    printf("Registering callback4\n");
    atexit(callback4);

    printf("main() executed\n");
    printf("\nFunction are called in reverse order\n");

    exit(0);
    return 0;
}
