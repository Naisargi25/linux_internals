#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#define NUM_THREADS 3

int i=0;
void *myfun(void *null)
{
   i++;
   int result=0;
   result = result + i*1000;
   printf("Result=%d\n",result);

   pthread_exit(NULL);
}


int main(int argc,char *argv)
{
   pthread_t thread[NUM_THREADS];
   pthread_attr_t attr;
   int rc,status,detach_state;

   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

   for(int i=0;i<NUM_THREADS;i++)
   {
       printf("Creating thread %d\n",i);
       pthread_create(&thread[i],&attr,myfun,NULL);
   }

   pthread_attr_getdetachstate(&attr,&detach_state);

   printf("\nExiting from main thread\n");
   pthread_exit(NULL);
   return 0;
}
