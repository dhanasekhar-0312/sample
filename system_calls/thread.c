#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>

void *threadfun(void *arg)
{
	printf("inside the thread\n");
	int *x = arg;
	int sum = x[0]+x[1];

	printf("the sum is %d\n",sum);

	pthread_exit("Sum is calculated");
}


int main()
{
	int n[2]={2,3};
	void *result;
	pthread_t thread;
	pthread_create(&thread,NULL,threadfun,(void*)n);
	pthread_join(thread , &result);
        printf("Inside the main program\n");
	printf("%s",(char*)result);

	return 0;

}
