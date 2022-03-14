#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<stdlib.h>

void *thread1(void *param)
{
   sleep(2);
   return 0;

}

int main()
{ 
   pthread_attr_t Attr;
   pthread_t Id;
   void *stk;
   size_t size;
   int err;

   size_t my_stksize = 0x3000000; //0x100 .. 100m
   void *my_stack;

   pthread_attr_init(&Attr);
   pthread_attr_getstacksize(&Attr,&size);
   pthread_attr_getstackaddr(&Attr,&stk);
   
   printf("Default Address = %08x default size=%d\n",stk,size);

   my_stack = (void*)malloc(my_stksize);

   pthread_attr_setstack(&Attr,my_stack,my_stksize);
   pthread_create(&Id,&Attr,thread1,NULL);

   pthread_attr_getstack(&Attr,&stk,&size);

   printf("Newly defined Address = %08x default size=%d\n",stk,size);

   sleep(3);
   
  
   return 0;
}
