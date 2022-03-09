#include<stdio.h>

int main()
{
  printf("st1\n");
  fork();
  fork();
  fork();
  printf("st2\n");
 // while(1);
  return 0;
}
