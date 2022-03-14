#include<stdio.h>
#include<pthread.h>
#include<string.h>


void *thread1(void *arg)
{
   char *s = (char *)arg;
   printf("%s\n",s);
   sleep(5);
   return(void*) strlen(s);
   //return NULL;
}

int main(int argc, char *argv[])
{ 
   pthread_t tid;
   void *res;

   int ret = pthread_create(&tid,NULL,thread1,"Hello World");

      
      printf("Message from main()\n");
      sleep(2);
      pthread_join(tid,&res);
      printf("Thread is returned %ld \n",(long)res);

      exit(0);
}
