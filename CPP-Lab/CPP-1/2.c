//Addition of Matrix

#include<stdio.h>
#include<sys/types.h>

int global;
pthread_mutex_t lock;

void *add( void* mat){
  int *mat1= (int*) mat;
  int i;
     pthread_mutex_lock(&lock);
   for(i=0;i<3;i++)
      global+=mat1[i];
   pthread_mutex_unlock(&lock);
       }
   
main(){
  int m[3][3]={1,2,3,4,5,6,7,8,9};
  pthread_t tid[3];
 
     
     pthread_create(&tid[0],NULL,add,(void *)m[0]);
     pthread_create(&tid[1],NULL,add,(void *)m[1]);
     pthread_create(&tid[2],NULL,add,(void *)m[2]);
     
     
     pthread_join(tid[0],NULL);
     pthread_join(tid[1],NULL);
     pthread_join(tid[2],NULL);
   
   printf("%d\n",global);
     }
