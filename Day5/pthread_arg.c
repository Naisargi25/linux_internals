#include<stdio.h>
#include<pthread.h>


void *thread1(void *arg)
{
   printf("Newly created thread executed\n");
   char *s = (char *)arg;
   printf("%s\n",s);
   return NULL;
}

int main(int argc, char *argv[])
{ 
   pthread_t tid;
   void *res;

   int ret = pthread_create(&tid,NULL,thread1,"Hello World");
  
   if(ret)
   {
      printf("Thread is not created\n");
   }

   else
   {
      printf("Thread is created\n");
      printf("Message from main()\n");
      //sleep(2);
      pthread_join(tid,NULL);
   }
   return 0;
}
