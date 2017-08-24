#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>
//int arr[]={5,3,7,1,9,16,3,8};
//int n=sizeof(arr)/sizeof(arr[0]);
pthread_mutex_t mutex;
typedef struct  param                                
{
	int lb;
	int ub;
	int arr[100];
}param;  
int part(int a[],int lb,int ub)
{
	//pthread_mutex_lock(&mutex);
	int c,up=lb,down=ub;
	int x=a[lb];
	while(up<down)
	{
		while(a[up]<=x && up<=down)
			up++;
		while(a[down]>x)
			down--;
		if(up<down)
		{
			c=a[up];
			a[up]=a[down];
			a[down]=c;
		}
	}
	a[lb]=a[down];
	a[down]=x;
	return down;
	//pthread_mutex_lock(&mutex);
}   
void *binary(void * s)
{
	//pthread_mutex_lock(&mutex);
	int x;
	printf("Enter number to search");
	scanf("%d",&x);
	param *p=(param*)s;
	if(p->lb<p->ub)
		return;
	 //NODE *p = (NODE *)a;
       param n1, n2;
       int mid = (p->lb+p->ub)/2;
                pthread_t tid5, tid6;
          if(p->arr[mid]==x)
          	printf("Found\n");
          	 n1.lb = p->lb;
                n1.ub = mid;

                n2.lb = mid+1;
                n2.ub = p->ub;
                pthread_create(&tid5,NULL,binary,&n1); 
	pthread_create(&tid6,NULL,binary,&n2); 
	pthread_join(tid5,NULL);
	pthread_join(tid6,NULL);
	//pthread_mutex_unlock(&mutex);
	
}	
void *quick(void *p)
{
	pthread_mutex_lock(&mutex);
	param *s=(param*)p;
      param n1, n2;
      int k;
                //int mid = (p->i+p->j)/2;
                if(s->lb>=s->ub)
                {
                	//pthread_t tid9;
                	//pthread_create(&tid9,NULL,binary,s);
                	return;
                }
                pthread_t tid1, tid2,tid3;
                //int ret;
			k=part(s->arr,s->lb,s->ub);
                n1.lb = s->lb;
                n1.ub = k-1;

                n2.lb = k+1;
                n2.ub = s->ub;
	//if(s->lb<s->ub)
	//{
	//k=part(s->arr,s->lb,s->ub);
	//pthread_create(&tid1,NULL,part,&s); 
	pthread_create(&tid1,NULL,quick,&n1); 
	pthread_create(&tid2,NULL,quick,&n2); 
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_mutex_unlock(&mutex);
	//pthread_exit(NULL);
	//}
}
	
int main()
{
	//int arr[]={3,6,1,7,3,6,8,9};
	int i;
	param s;
	s.lb=0;
	printf("Enter the matrix size");
	scanf("%d",&(s.ub));
	for(i=0;i<s.ub;i++)
	{
		printf("Enter value=");
		scanf("%d",&(s.arr[i]));
	}
	printf("Before sorting\n");
	for(i=0;i<s.ub;i++)
	{
		printf("%d  ",s.arr[i]);
	}
	pthread_t tid;
	//int n=sizeof(arr)/sizeof(arr[0]);
	pthread_create(&tid,NULL,quick,&s); 
	pthread_join(tid,NULL);
	printf("\nAfter sorting\n");
	for(i=0;i<s.ub;i++)
		printf("%d   ",s.arr[i]);
	/*quick(arr,0,n-1);	
	for(i=0;i<n;i++)
		printf("%d  ",arr[i]);	*/
	return 0;
}
