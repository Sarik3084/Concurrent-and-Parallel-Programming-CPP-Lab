#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<stdbool.h>

sem_t OKtoRead;
sem_t OKtoWrite;
int buffer[100];
#define m 10
int f=-1,r=-1,in=0,out=0;
#define MAX 5

void append(int d){
 if(r==MAX-1){
  printf("Queue is full");
   exit(0);
   }
else{
 
 if(f==-1)
   f=0;
  
   buffer[++r]=d;
} 
} 

 int take(){
   int d;
 if(f==-1 || f>r)
 printf("Empty Queue");
  
  else{
     d=buffer[f++];
    }

 if(f>r){
  f=-1;r=-1;}
   
return d;
  }


void *reader(){
  
    sem_wait(&OKtoRead);
      
      in=(in+1);
      //append(d);
 sem_post(&OKtoWrite);

 pthread_exit(NULL);
}

void *writer(){
 int d=1;
    sem_wait(&OKtoRead);
    //d=take(buffer);
  d=buffer[out];
  out=out+1%MAX;
     sem_post(&OKtoWrite);
    printf("Consuming\n");
  
 pthread_exit(NULL);
 }
   
int main(){
 int i;

 pthread_t t[m];

 int s1=sem_init(&OKtoRead,0,0);
 int s2=sem_init(&OKtoWrite,0,MAX);
  if(s1!=0||s2!=0)
 printf("Error in creating semaphore");


 for(i=0;i<m;i++){
  pthread_create(&t[i],NULL,reader,NULL);
  pthread_create(&t[i],NULL,writer,NULL);
  }

 for(i=0;i<m;i++)
  pthread_join(t[i],NULL);

  sem_destroy(&notEmpty);
  sem_destroy(&notFull);
  pthread_exit(NULL);
}
  
 
