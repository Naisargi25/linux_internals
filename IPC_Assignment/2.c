#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <unistd.h>

typedef struct
{
    long mtype;
    char data[100];
}msg;

int main()
{
    int mqid,i;
    msg m1,m2;
    struct msqid_ds buf;
    mqid = msgget(36,IPC_CREAT|0644);
    m1.mtype = 10;
    strcpy(m1.data,"Hello");

    m2.mtype = 50;
    strcpy(m2.data,"Good");

    i = msgsnd(mqid,&m1,sizeof(msg),0);
    
    i = msgsnd(mqid,&m2,sizeof(msg),0);
 
    printf("\nMessage qid: %d\n",mqid);
    
    i = msgctl(mqid,IPC_STAT,&buf);
    if(i==-1)
    {
        printf("msgctl - failure\n");
    }
    printf("Here are the details of the queue\n");
    printf("No. of msg's in queue: %ld\n",buf.msg_qnum);
    printf("No. of bytes in queue %lu\n",buf.__msg_cbytes);
    printf("Max no. of bytes in queue %li\n",buf.msg_qbytes);

    i = msgctl(mqid,IPC_RMID,&buf);
    if(i==-1)
    {
        printf("msgctl - failure\n");
    }
    else
    {
        printf("Message queue is deleted\n\n");
    }
}