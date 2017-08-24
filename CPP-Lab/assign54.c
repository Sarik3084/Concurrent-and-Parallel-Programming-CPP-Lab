/**4. Implement producer-consumer problem with Semaphores (circular buffer).**/


#include <stdio.h> 
#include<stdlib.h>
#include <pthread.h> 
#include<semaphore.h>
#include<stdbool.h>


#define M 10
#define MAX 4
sem_t notEmpty;
sem_t notFull;
static i=0;
int buffer[MAX];

int in=0, out=0;

void display()
{
    int i,j;
    if(out==0&&in==-1)
    {
        printf("Queue is underflow\n");
       
      
    }
    else if(out>in)
    {   printf("\n");
        for(i=0;i<=in;i++)
            printf("\t%d",buffer[i]);
        for(j=out;j<=MAX-1;j++)
            printf("\t%d",buffer[j]);
       
    }
    else
    {   printf("\n");
        for(i=out;i<=in;i++)
        {
            printf("\t%d",buffer[i]);
        }
       
    }
    printf("\n");
}

void* producer() { 

int d=1;

        d=rand()%100+1;
        printf("\n Producing %d ", d); 
        sem_wait(&notFull);
        buffer[in]=d;
        //display();
        in=(in+1)%MAX;
        sem_post(&notEmpty);
	
pthread_exit(NULL);
    
} 

void* consumer() {

 int d; 
 
        sem_wait(&notEmpty);
        d=buffer[out];
       // display();
        out=(out+1)%MAX;
        sem_post(&notFull);
        printf("\n Consuming %d",d);
	
    
pthread_exit(NULL);
} 

int main() { 
  pthread_t t[M]; 
  int rets=sem_init(&notEmpty,0,0);
  sem_init(&notFull,0,MAX);
  if(rets!=0){
  	printf("\n Error in creating semaphore ");
  }
  long i;
  for( i=0 ;i<M;i++){
  int iret1 = pthread_create(&t[i], NULL, producer, NULL) ;	
  int iret2 = pthread_create(&t[i], NULL, consumer, NULL); 
  }	

  for( i=0 ;i<M;i++){
 	pthread_join(t[i],NULL);  
  }
	
	
	printf("\n");        
	sem_destroy(&notEmpty); 
        sem_destroy(&notFull);
	pthread_exit(NULL); 
  

}
