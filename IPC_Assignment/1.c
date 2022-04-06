/*Write a program that creates a shared memory region and displays shared memory id
and also print address at which shared area in this process starts from.*/

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>

int main()
{
    void *p;
    int id;

    //int shmget(key_t key, size_t size, int flag);
    id = shmget(49,270,IPC_CREAT|0644);

    if(id<0)
    {
        perror("shmget");
        return 0;
    }

    printf("Id of Shared memory is: %d\n",id);

    //void *shmat(int shmid, const void *addr, int flag);

    p = shmat(id,0,SHM_RDONLY); // PAS -- User spcae

    printf("Address of shared memory region: %p\n",p);
    
    return 0;
}

