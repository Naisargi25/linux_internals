#include<stdio.h>
#include<pthread.h>

pthread_t tid , tid1;

void *thread1(void *arg)
{
   printf("Newly created thread 1 is executed\n");
   for(int i=0;i<5;i++)
   {
      printf("Thd of con 2\n");
   }
   return NULL;
}

void *thread2(void *arg)
{
   printf("Thread 2 task is executing\n");
   for(int i=0;i<5;i++)
   {
      printf("Thd of con 2\n");
   }
   return NULL;
}

int main()
{  
   pthread_t pt1,pt2;
   getchar();
   pthread_create(&pt1,NULL,thread1,NULL);
   pthread_create(&pt2,NULL,thread2,NULL);
   //getchar();

   pthread_join(pt1,NULL);
   pthread_join(pt2,NULL);
   printf("End of main thread\n");
   return 0;
}
