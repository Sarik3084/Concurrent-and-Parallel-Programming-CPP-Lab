//3. Write a program to sort an array using bubble sort and linear search an element in array  using different threads. 
//Use mutex lock to synchronize the results.
 
#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>

typedef struct node
{
	int arr[100];
	int n;
}node;
pthread_mutex_t mutex;

void *bubble(void *arg)
{
	pthread_mutex_lock(&mutex);
	node *s=(node*)arg;
	
	int i,j,temp;
	for(i=s->n-1;i>=0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(s->arr[j]>s->arr[j+1])
			{
				temp=s->arr[j];
				s->arr[j]=s->arr[j+1];
				s->arr[j+1]=temp;
			}
		}
	}
	printf("Sorted array is\n");
	for(i=0;i<s->n;i++)
		printf("%d  ",s->arr[i]);
	printf("\n");
	pthread_mutex_unlock(&mutex);
}
void *linear(void *arg)
{
	pthread_mutex_lock(&mutex);
	node *s=(node*)arg;
	//int n=12;
	//printf("%d",n);
	int i,a,f=1;
	printf("Enter the value to search=>");
	scanf("%d",&a);
	for(i=0;i<s->n;i++)
	{
		if(s->arr[i]==a)
		{
			f=0;
			break;
		}
	}
	if(f==0)
		printf("Found at index %d\n",i);
	else
		printf("Not found\n");	
	pthread_mutex_unlock(&mutex);	
}
int main()
{
	node s;
	int i;
	printf("Enter the size of array=>");
	scanf("%d",&s.n);
	for(i=0;i<s.n;i++)
	{
		printf("Enter value=");
		scanf("%d",&s.arr[i]);
	}
	
	pthread_t tid[2];
	pthread_create(&tid[0],NULL,bubble,&s);
	pthread_create(&tid[1],NULL,linear,&s);
	
	
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
}
