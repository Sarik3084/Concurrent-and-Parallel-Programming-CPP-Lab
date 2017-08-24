#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>

int wantp=0,wantq=0,cs_var;

void *func(){
 
    while(wantq!=0);
     wantp=1;
      printf("P\n");
      wantp=0;
      
 }     
    void *func1(){

    while(wantp!=0);
     wantq=1;
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
   
