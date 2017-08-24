/*1. Write a program to increment and decrement a commom variable using different threads using mutex lock.*/
#include<stdio.h>
#include<sys/types.h>

int x=4;

pthread_mutex_t lock;
pthread_t tid[4];


void increment(void *t){
 pthread_mutex_lock(&lock);
  x=x+1;
 printf("The value of x -pid %dafter increment is %d\n",pthread_self(), x);
   pthread_mutex_unlock(&lock);
}

   
void decrement(void *t){
 pthread_mutex_lock(&lock);
 x=x-1;
printf("The value of x -pid %d after decrement is %d\n",pthread_self(), x);
   pthread_mutex_unlock(&lock);
}

void main(){

int a,b,i;
long t;


for(i=0;i<4;i++) {
a=pthread_create(&tid[i],NULL,&increment,(void*)t);
b=pthread_create(&tid[i],NULL,&decrement,(void*)t);
 }

pthread_exit();
}
 
