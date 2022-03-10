#include<stdio.h>

int main(int argc,char *argv[])
{
   int i;
   printf("File name: %s\n",argv[0]);
   printf("Total no. of arguments: %d\n",argc);
   printf("Arguments passed: ");
    
   
   execl("/usr/bin/vi","argv[1]","argv[2]",0);
  
   
   
   printf("\n");
   return 0;
}
