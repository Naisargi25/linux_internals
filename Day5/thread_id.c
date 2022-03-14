#include<stdio.h>
#include<pthread.h>

pthread_t tid;

void *thread1(void *arg)
{
   printf("Newly created thread executed\n");
   pid_t pid;
   pid = getpid();
   tid = pthread_self();
   printf("pid %u tid %u\n");
   return NULL;
}

int main()
{ 
  
   int ret = pthread_create(&tid,NULL,thread1,NULL);
  
   if(ret!=0)
   {
      printf("Thread is not created\n");
   }

   else
   {
      printf("Thread is created\n");
      //sleep(2);
      pthread_join(tid,NULL);
   }
   while(1);
   return 0;
}
