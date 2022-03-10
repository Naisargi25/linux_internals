#include<stdio.h>
#include<pthread.h>

pthread_t tid , tid1;

void *thread1(void *arg)
{
   printf("Newly created thread executed\n");
   return NULL;
}

void *thread2(void *arg)
{
   printf("Thread 2 task is executing\n");
   return NULL;
}

int main()
{ 
   int ret = pthread_create(&tid,NULL,thread1,NULL);
  
   int ret1 = pthread_create(&tid1,NULL,thread2,NULL);
   if(ret) //error code
   {
      printf("Thread is not created\n");
   }

   else
   {
      printf("Thread1 is created\n");
      //sleep(2);
      pthread_join(tid,NULL);
   }

   if(ret1) //error code
   {
      printf("Thread 2 is not created\n");
   }

   else
   {
      printf("Thread2 is created\n");
      //sleep(2);
      pthread_join(tid1,NULL);
   }
   return 0;
}
