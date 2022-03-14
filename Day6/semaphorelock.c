#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int sharedvar = 5;

sem_t my_sem;

void *thread_inc(void *arg)
{
    sem_wait(&my_sem);
    sharedvar++;
    sem_post(&my_sem);
    //printf("After inc = %d\n");
}

void *thread_dec(void *arg)
{
    sem_wait(&my_sem);
    sharedvar--;
    sem_post(&my_sem);
    //printf("After dec = %d\n");
}

int main()
{
    pthread_t thread1,thread2;
   
    sem_init(&my_sem,0,1);

    pthread_create(&thread1,NULL,thread_inc,NULL);
    pthread_create(&thread2,NULL,thread_dec,NULL);
 
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    printf("Shredvar = %d\n",sharedvar);
    return 0;
}
