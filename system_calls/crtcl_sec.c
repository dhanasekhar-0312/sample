#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int share = 1;

void* func1(void* arg)
{
	int x=share;
	printf("the share value is readed %d \n",x);
	x++;
	sleep(2);
	share=x;
	printf("the share value in thread-1 is  %d \n",share);
	return 0;
}

void* func2(void* arg)
{
	int y = share;
	printf (" the share value is redaded %d \n",share);
	y--;
	sleep(2);
	share=y;
	printf("the share value in thread-2 is %d \n",share);
	return 0;
}
	
int main()
{
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,func1,NULL);
	pthread_create(&thread2,NULL,func2,NULL);
	pthread_join(thread1,NULL);
        pthread_join(thread2,NULL);
	printf("the final value of share is %d\n",share);

	return 0;

}
	
