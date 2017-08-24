#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdbool.h>

sem_t forke[5];
pthread_t tid[5];

//func
void *func(void *arg){
 long d= (long)arg;
 int t=1,j;
   printf("Philosopher %ld is thinking\n",d);

  wait(forke[d]);
  wait(forke[d+1]);
 
  printf("Philosopher %ld is eating\n",d);
   signal(forke[d]);
   signal(forke[d+1]);
 
pthread_exit(NULL);
}
//func1
void *func1(void *arg){
 long d= (long)arg;
 int t=1,j;

    printf("Philosopher %ld is thinking\n",d);
   

  wait(forke[0]);
  wait(forke[4]);
 
  printf("Philosopher %ld is eating\n",d);
   signal(forke[0]);
   signal(forke[4]);
 
pthread_exit(NULL);
}

main(){
int i;
for(i=0;i<1;i++) {
 
 sem_init(&forke[i],0,1);
/*if(r!=0)
 printf("Error in creating semaphore");*/
 pthread_create(&tid[0],NULL,func,(void *)1);
 pthread_create(&tid[1],NULL,func,(void *)2);
 pthread_create(&tid[2],NULL,func,(void *)3);
 pthread_create(&tid[3],NULL,func,(void *)4);
 pthread_create(&tid[4],NULL,func1,(void *)5);
}
for(i=0;i<6;i++){
  pthread_join(tid[i],NULL);
sem_destroy(&forke[i]);}
 pthread_exit(NULL);
}

