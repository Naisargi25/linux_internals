#include <stdio.h>

int main(int argc,char *argv[])
{
    execl("/bin/ls", argv[1],argv[2],0);
    return 0;
}
