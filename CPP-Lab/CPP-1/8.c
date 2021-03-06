#include <stdio.h> 
#include <pthread.h> 
#include<errno.h>
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER; 
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER; 


void* thread_1(void *ptr) { 
int x;
 x= pthread_mutex_trylock(&mutex2);
  if(x==0){
  pthread_mutex_lock(&mutex1); 
  printf("I am in thread thread_1\n"); 
  pthread_mutex_unlock(&mutex1); 
  pthread_mutex_unlock(&mutex2); 
	pthread_exit(NULL); 
}
else if(x==EBUSY)
printf("\n Thread Busy\n");
} 

void* thread_2(void *ptr) { 
 int x;
 x=pthread_mutex_trylock(&mutex2); 
if(x==0){
  pthread_mutex_lock(&mutex1); 
  printf("I am in thread thread_2\n"); 
  pthread_mutex_unlock(&mutex1);
  pthread_mutex_unlock(&mutex2);
}
else if(x==EBUSY)
printf("\n Thread Busy\n"); 
	pthread_exit(NULL); 
} 

int main() { 
  pthread_t t1, t2; 
  int iret1 = pthread_create(&t1, NULL, thread_1, NULL); 
  int iret2 = pthread_create(&t2, NULL, thread_2, NULL); 
	pthread_join(t1,NULL); 
	pthread_join(t2,NULL); 
	pthread_exit(NULL); 
}
