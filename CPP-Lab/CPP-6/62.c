#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t notEmpty;

int buffer[100];
#define m 3
int f=-1,r=-1;

void append(int d){
 if(f==-1)
   f=0;

   buffer[++r]=d;
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


void *producer(){
   int d=1;
      d=rand()%100;
      printf("Producing %d\n",d);
      append(d);
 sem_post(&notEmpty);

 pthread_exit(NULL);
}

void *consumer(){
 int d=1;
    sem_wait(&notEmpty);
    d=take(buffer);
    printf("Consuming %d\n",d);
  
 pthread_exit(NULL);
 }
   
int main(){
 int i;

 pthread_t t[m];

 int s1=sem_init(&notEmpty,0,0);

  if(s1!=0)
 printf("Error in creating semaphore");


 for(i=0;i<m;i++){
  pthread_create(&t[i],NULL,producer,NULL);
  pthread_create(&t[i],NULL,consumer,NULL);
  }

 for(i=0;i<m;i++)
  pthread_join(t[i],NULL);

  sem_destroy(&notEmpty);
  pthread_exit(NULL);
}
  
 
