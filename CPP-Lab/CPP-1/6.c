/*6. Write a program to simulate the transactions on a bank account.
 Create structure for account number and current balance detail. One thread credit and another thread debit from account same time. Use mutex lock to synchronize the transactions. pthread_mutex_trylock() function should be used to lock the variable.*/
 
 #include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<pthread.h>
typedef struct det{
 int account_number;
 float current_balance;
 }det;
 
 det d;
 pthread_mutex_t lock;
  void *debit(){
   int a;
    if(pthread_mutex_trylock(&lock)==0){
   printf("Enter the amount you want to withdraw");
    scanf("%d",&a);
    
    d.current_balance-=a;
    printf("Current Balance => %f \n", d.current_balance);
    }
    pthread_mutex_unlock(&lock);
    }
    
    void *credit(){
   int a;
   if(pthread_mutex_trylock(&lock)==0){
   printf("Enter the amount you want to add");
    scanf("%d",&a);
    
    d.current_balance+=a;
    printf("Current Balance => %f \n", d.current_balance);
    }
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
    pthread_join(tid,NULL);
    break;
    
    case 2:
     
     pthread_create(&tid1,NULL,credit,NULL);
     pthread_join(tid1,NULL);
     break;
     
     case 3:
      exit(0);
     }
     }
    pthread_exit(NULL);
 }
