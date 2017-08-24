#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>
//int arr[]={5,3,7,1,9,16,3,8};
//int n=sizeof(arr)/sizeof(arr[0]);
int arr[] = {10, 8, 5, 2, 3, 6, 7, 1, 4, 9};
pthread_mutex_t mutex;
typedef struct  node                                
{
	int lb;
	int ub;
	//int arr[100];
}node;  
//node s; 
int x; 
void *binary(void * p)
{
	//pthread_mutex_lock(&mutex);
	//int x;
	//printf("Enter number to search");
	//scanf("%d",&x);
	//node *s=(node*)p;
	//if(p->lb<p->ub)
	//	return;
	 //NODE *p = (NODE *)a;
	 node *s=(node*)p;
       node n1, n2;
       if(s->lb<s->ub){
       int mid = (s->lb+s->ub)/2;
                pthread_t tid5, tid6;
          if(arr[mid]==x)
          	printf("Found at index %d \n",mid);
          	 n1.lb = s->lb;
                n1.ub = mid;

                n2.lb = mid+1;
                n2.ub = s->ub;
                pthread_create(&tid5,NULL,binary,&n1); 
	pthread_create(&tid6,NULL,binary,&n2); 
	pthread_join(tid5,NULL);
	pthread_join(tid6,NULL);
	}
	pthread_exit(NULL);	
	//pthread_mutex_unlock(&mutex);
	
}
int part(int lb,int ub)
{
	//pthread_mutex_lock(&mutex);
	int c,up=lb,down=ub;
	int x=arr[lb];
	while(up<down)
	{
		while(arr[up]<=x && up<=down)
			up++;
		while(arr[down]>x)
			down--;
		if(up<down)
		{
			c=arr[up];
			arr[up]=arr[down];
			arr[down]=c;
		}
	}
	arr[lb]=arr[down];
	arr[down]=x;
	return down;
	//pthread_mutex_lock(&mutex);
} 	
void *quick(void *p)
{
	//pthread_mutex_lock(&mutex);
	node *s=(node*)p;
      node n1, n2;
      int k;//part(s->lb,s->ub);
       pthread_t tid1, tid2;
       int ret;
     // int k=part(s->arr,s->lb,s->ub);
     if(s->lb<s->ub){
       k=part(s->lb,s->ub);
                n1.lb = s->lb;
                n1.ub = k-1;
                
                n2.lb = k+1;
                n2.ub = s->ub;
          //pthread_mutex_unlock(&mutex);     
         pthread_create(&tid1,NULL,quick,&n1);
         pthread_create(&tid2,NULL,quick,&n2);
   // pthread_mutex_unlock(&mutex);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	}
	  
	pthread_exit(NULL);	
}



/*void * mergesort(void *a)
{
                NODE *p = (NODE *)a;
                NODE n1, n2;
                int mid = (p->i+p->j)/2;
                pthread_t tid1, tid2;
                int ret;

                n1.i = p->i;
                n1.j = mid;

                n2.i = mid+1;
                n2.j = p->j;

                if (p->i >= p->j) return;

                ret = pthread_create(&tid1, NULL, mergesort, &n1);
                if (ret) {
                        printf("%d %s - unable to create thread - ret - %d\n", __LINE__, __FUNCTION__, ret);    
                        exit(1);
                }


                ret = pthread_create(&tid2, NULL, mergesort, &n2);
                if (ret) {
                        printf("%d %s - unable to create thread - ret - %d\n", __LINE__, __FUNCTION__, ret);    
                        exit(1);
                }

                pthread_join(tid1, NULL);
                pthread_join(tid2, NULL);

                merge(p->i, p->j);
                pthread_exit(NULL);	
}
	*/
int main()
{
	//int arr[]={3,6,1,7,3,6,8,9};
	int i;
	node s;
	s.lb=0;
	s.ub=9;
	//printf("Enter the array size");
	//scanf("%d",&(s.ub));
	/*for(i=0;i<s.ub;i++)
	{
		printf("Enter value=");
		scanf("%d",&(s.arr[i]));
	}*/
	printf("Before sorting\n");
	for(i=0;i<=s.ub;i++)
	{
		printf("%d  ",arr[i]);
	}
	pthread_t tid;
	pthread_create(&tid,NULL,quick,&s); 
	pthread_join(tid,NULL);
	printf("\nAfter sorting\n");
	for(i=0;i<=9;i++)
		printf("%d   ",arr[i]);
		printf("\n");
	pthread_t tid4;
	printf("Enter nuber to search");
	scanf("%d",&x);
	pthread_create(&tid4,NULL,binary,&s); 
	pthread_join(tid4,NULL);
	//pthread_join(tid,NULL);
	return 0;
}
