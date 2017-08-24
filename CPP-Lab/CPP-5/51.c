#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>

 sem_t s;

void *pth(){
  sem_wait(&s);
 printf("P\n");
 sem_post(&s);
 }
void *qth(){
  sem_wait(&s);
 printf("Q\n");
 sem_post(&s);
 }

main(){
 pthread_t tid[2];
 sem_init(&s,0,1);

 pthread_create(&tid[0],NULL,pth,NULL);
  pthread_create(&tid[1],NULL,qth,NULL);

 pthread_join(tid[0],NULL);
 pthread_join(tid[1],NULL);

pthread_exit(NULL);
}
