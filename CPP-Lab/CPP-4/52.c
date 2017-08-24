#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>

int wantp=0,wantq=0,cs_var;

void *func(){
 wantp=1;
    while(wantq!=0)
    //printf("Deadlock check");
     printf("P\n");
      wantp=0;
      
 }     
    void *func1(){
wantq=1;
    while(wantp!=0)
    //printf("Deadlock check");
     printf("Q\n");
      wantq=0;
      
      
}

  void main(){
   pthread_t tid,tid1;
   
   pthread_create(&tid,NULL,func,NULL);
   pthread_create(&tid1,NULL,func1,NULL);
   
   
   pthread_join(tid,NULL);
   pthread_join(tid1,NULL);
   
   pthread_exit(NULL);
   }
   
