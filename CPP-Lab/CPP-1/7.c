#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>
pthread_mutex_t lock1,lock2;
typedef struct node
{
	int val;
	struct node* next;
}node;
node *start='\0';
node *getnode(int a)
{
	node *temp=malloc (sizeof(node));
	temp->val=a;
	temp->next='\0';
	return temp;
}

void insert(int a)
{
	if(start=='\0')
		start=getnode(a);
	else
	{
		node *temp=start;
		while(temp->next!='\0')
			temp=temp->next;
		temp->next=getnode(a);
	}
		
}
void display()
{
	node *temp=start;
	while(temp!='\0')
	{
		printf("%d   ",temp->val);
		temp=temp->next;
	}
	printf("\n");
}
void *delete()
{
	pthread_mutex_lock(&lock1);
	pthread_mutex_lock(&lock2);
	node *temp=start,*p='\0';
	int n;
	printf("\nEnter value to delete	");
	scanf("%d",&n);
	if (start=='\0')
		printf("Empty\n");
	else if(start->val==n)
	{
		start=start->next;
		temp->next='\0';
		free(temp);
	}
	else
	{
		while(temp!='\0')
		{
			if(temp->val==n)
			{
				p->next=temp->next;
				temp->next='\0';
				free(temp);
				break;
			}
			p=temp;
			temp=temp->next;
		}
	}
	pthread_mutex_unlock(&lock2);
	pthread_mutex_unlock(&lock1);
}
int main()
{
	
	int a,ex;
	pthread_t tid;
	while(1)
	{
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Display\n");
	printf("4.Exit\n");
	printf("Enter: =>");
	scanf("%d",&ex);
	
	switch(ex)
	{
	case 1:printf("Enter value ");
		scanf("%d",&a);
		insert(a);
		break;
	case 2:
		 pthread_create(&tid,NULL,delete,NULL);
		 pthread_join(tid,NULL);
		 break;
	case 3:display();
		 break;
	case 4:exit(0);
	}
	}
	
	return 0;
}
