/*6. Write a program to simulate the transactions on a bank account.
 Create structure for account number and current balance detail. One thread credit and another thread debit from account same time. Use mutex lock to synchronize the transactions. pthread_mutex_trylock() function should be used to lock the variable.*/
 
 #include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<pthread.h>
#include<errno.h>

typedef struct det{
 int account_number;
 float current_balance;
 }det;
 
 det d;
 pthread_mutex_t lock;
 //DEBIT
 void *debit(){
   int a,x;

  x=pthread_mutex_trylock(&lock);
if(x==0)
{
   printf("Enter the amount you want to withdraw");
    scanf("%d",&a);
    
    d.current_balance-=a;
    printf("Current Balance => %f \n", d.current_balance);
    }
else if(x==EBUSY)
 printf("\n Thread busy\n");

    pthread_mutex_unlock(&lock);
    }
   //CREDIT 
    void *credit(){
   int a,x;

  x=pthread_mutex_trylock(&lock);
if(x==0)
{
   printf("Enter the amount you want to deposit");
    scanf("%d",&a);
    
    d.current_balance+=a;
    printf("Current Balance => %f \n", d.current_balance);
    }
else if(x==EBUSY)
 printf("\n Thread busy\n");

    pthread_mutex_unlock(&lock);
    }
    
 
main(){
 
 int acc,c;
 pthread_t tid,tid1;
 printf("Enter the bank account number");
  scanf("%d", &d.account_number);
  
   d.current_balance=rand()%1000;   //Not sure
   //scanf("%f",&d.current_balance);
   while(1) {
  printf("Do you want to \n 1.Debit 2. Credit 3. Exit");
   scanf("%d", &c);
   
   switch(c){
   case 1:
    
    pthread_create(&tid,NULL,debit,NULL);
    pthread_create(&tid1,NULL,credit,NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid,NULL);
    break;
    
    case 2:
     
     pthread_create(&tid1,NULL,credit,NULL);
     pthread_create(&tid,NULL,debit,NULL);
     pthread_join(tid,NULL);
     pthread_join(tid1,NULL);
     break;
     
     case 3:
      exit(0);
     }
     }
    pthread_exit(NULL);
 }
