#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>


void *thread1(void *arg)
{
   pthread_detach(pthread_self());
   printf("Sleeping 2 secs\n");
   sleep(2);
   printf("Slept 2 secs\n");
   //return NULL;
}

int main(int argc, char *argv[])
{ 
   pthread_t tid;

   int ret = pthread_create(&tid,NULL,thread1,NULL);

   if(ret)
      perror("pthread create:\n");

   pthread_exit(NULL);
}
