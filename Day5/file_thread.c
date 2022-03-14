#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

pthread_t tid , tid1;
int fd;

void *thread1(void *p)
{
   char * str, buf[100];
   int n,pid;
   str = (char*)p;
   pid = getpid();
   printf("%s: \t started  now: \t for process id %d\n",str,pid);
   do
   {
      n = read(fd,buf,100);
      printf("%s: \t Read: \t %d \n",str,pid);
      printf("\n--------------------------\n");
      write(1,buf,n); //fd 1 -> std output
      printf("\n-------------------------\n");
      sleep(3);
   }while(n);

   printf("%s :\t Finished for process id %d \n",str,pid);
   return NULL;
}

int main()
{ 
   pthread_t t1,t2;

   fd = open("/etc/passwd",O_RDONLY);
   printf("FIle opened with fd: %d\n");
   int ret = pthread_create(&t1,NULL,thread1,"Thread 1");
   int ret1 = pthread_create(&t2,NULL,thread1,"Thread 2");
   pthread_join(t1,NULL);
   pthread_join(t2,NULL);
  
   return 0;
}
