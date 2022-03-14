#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>



void *thread1(void *p)
{
   printf("Hello\n");
   while(1);
}

int main()
{ 
   pthread_t thread;

   int t=0;
   printf("Creating thread\n");
   int ret = pthread_create(&thread,NULL,thread1,NULL);
   printf("Thread id : %u\n",thread);
   sleep(6);
   t = pthread_cancel(thread);
   if(t == 0)
   {
     printf("Thread cancelled\n");
     printf("Thread id: %u",thread);
   }
   
  
   return 0;
}
