/*1. Implement solution of Critical Section problem with Semaphores (two processes).*/

#include <stdio.h> 
#include <pthread.h> 
#include<semaphore.h>
#include<stdbool.h>

#define M 2

sem_t S;


void* thread_1() { 
int t=M;
   while(t--){
         printf("\n I am in NCS of process P "); 
        sem_wait(&S);
 
        printf("\n I am in CS of process P "); 
   
        sem_post(&S);
	}
pthread_exit(NULL);
    
} 

void* thread_2() { 
 int t = M;
    while(t--){
        printf("\n I am in NCS of process Q "); 

        sem_wait(&S);

        printf("\n I am in CS of process Q "); 

        sem_post(&S);
	
    }
    
pthread_exit(NULL);
} 

int main() { 
  pthread_t t1, t2; 
  int rets=sem_init(&S,0,1);

  if(rets!=0){
  	printf("\n Error in creating semaphore ");
  }
  
  int iret1 = pthread_create(&t1, NULL, thread_1, NULL) ;	
  int iret2 = pthread_create(&t2, NULL, thread_2, NULL); 
	
	pthread_join(t1,NULL);  
	pthread_join(t2,NULL);
	printf("\n");        
	sem_destroy(&S); 
	pthread_exit(NULL); 
  

}
