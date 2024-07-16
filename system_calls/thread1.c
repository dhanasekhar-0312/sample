#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int count = 0;

void *threadfun1(void *arg)
{
	int x = count;
	x++;
	printf("the count value is %d\n",x);
	sleep(1);
	x++;
	printf("the count value is %d\n",x);
	return 0;
}

void *threadfun2(void *arg)
{
	int y =count;
	y--;
	printf("the count value is %d\n",y);
	sleep(1);
	y--;
	printf("the count value is %d\n",y);
	return 0;
}

int main()
{

	pthread_t thread1, thread2;
	pthread_create(&thread1,NULL,threadfun1,NULL);
	pthread_create(&thread2,NULL,threadfun2,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	printf("the count value at final is %d\n",count);

	return 0;
}

