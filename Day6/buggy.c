#include<stdio.h>
#include<stdlib.h>

//malloc allocate nearest size eg. if 20 byte required then allocate 64 byte
void buggy()
{
    int *intptr;
    int i;
    intptr = (int*)malloc(sizeof(int)*5);
  
    printf("Malloc Checking Addr:%08x and size=%d\n",intptr,sizeof(int)*5);

     for(i=0;i<=10;i++)
      {

          *intptr=100;
          printf("Value at intptr = %d\n",(*intptr));
          intptr++;
       }
}

int main()
{
   buggy();
   return 0;
}
