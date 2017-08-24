#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>

int wantp=0,wantq=0,turn=1;

 void *pfunc(){
  wantp=1;
  while(wantq!=0){
    if(turn=2)
     wantp=0;
     while(turn!=1)
      wantp=1;
      }
      printf("P\n");
      turn=2;
      wantp=0;
      }
      
      
      void *qfunc(){
  wantq=1;
  while(wantp!=0){
    if(turn=1)
     wantq=0;
     while(turn!=2)
      wantq=1;
      }
      printf("Q\n");
      turn=1;
      wantq=0;
      
      }
      
         


main(){
 pthread_t tid[2];
 while(1){
  pthread_create(&tid[0],NULL,pfunc,NULL);
  pthread_create(&tid[1],NULL,qfunc,NULL);
  
   pthread_join(tid[0],NULL);
   pthread_join(tid[1],NULL);
   }
   pthread_exit(NULL);
   }
   
