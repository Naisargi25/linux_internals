#include<stdio.h>
#include<pthread.h>

pthread_t tid;

void *thread1(void *arg)
{
   printf("Newly created thread executed\n");
   return NULL;
}

int main()
{ 
   int ret = pthread_create(&tid,NULL,thread1,NULL);
  
   if(ret)
   {
      printf("Thread is not created\n");
   }

   else
   {
      printf("Thread is created\n");
      //sleep(2);
      pthread_join(tid,NULL);
   }
   return 0;
}
