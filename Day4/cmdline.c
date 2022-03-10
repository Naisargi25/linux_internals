#include<stdio.h>

int main(int argc,char *argv[])
{
   int i;
   printf("FIle name: %s\n",argv[0]);
   printf("Total no. of arguments: %d\n",argc);
   printf("Arguments passed: ");
    
   for(int i=1;i<argc;i++)
   {
      printf("%s ",argv[i]);
   }
   printf("\n");
   return 0;
}
