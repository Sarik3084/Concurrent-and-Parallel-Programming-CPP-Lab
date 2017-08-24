/*3. Implement producer-consumer problem with Semaphores (finite buffer).*/

#include <stdio.h> 
#include <pthread.h> 
#include<semaphore.h>
#include<stdbool.h>


#define M 5
#define MAX 5
sem_t notEmpty;
sem_t notFull;
int buffer[MAX];
int f=-1,r=-1;

void printbuff()
{
  int j;
  printf("\n Buffer :");

      if (f == -1)
           printf("Queue is empty ");
      
 	 for( j=f;j<=r;j++){
  
      printf(" %d ",buffer[j]);

  }

}
void append(int d){

   if(r==MAX-1){
     printf("\n Queue Full");
     
   }
   else{
 
         if(f==-1)
             f=0;
    
         buffer[++r]=d;
    
   }
}


int take(){
int d;
   

    if (f == -1 || f > r){
      printf("\n Queue Empty");
      return -1;
   }
   else{

      d=buffer[f++];
     

     
    }

    if(f>r){

       f=-1;r=-1;
      }

  return d;

}
void* producer() { 

int d=1;

        d=rand()%100+1;
        printf("\n Producing %d ",d);
        sem_wait(&notFull);
        append(d);
        //printbuff();
        sem_post(&notEmpty);
	
  
pthread_exit(NULL);
    
} 

void* consumer() {

 int d; 
 
        sem_wait(&notEmpty);
        d=take(buffer);
       // printbuff(); 
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
